#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

// use graph store webpage, weight representlink times
class Node 
{
public:
    Node(string name, double pr = 1):name_(name), page_rank_(pr){}

    ~Node()
    {
        linkin_nodes_.clear();
    }
    void InsertLinkdInNode(Node* node) 
    {
        if (linkin_nodes_.find(node) == linkin_nodes_.end()) 
        {
            //cout << "---" << endl;
            linkin_nodes_.insert(node);
        }
        node->InsertLinkOutNode(this);
    }

    void InsertLinkOutNode(Node* node) 
    {
        if (linkout_nodes_.find(node) == linkout_nodes_.end()) 
        {
            //cout << "+++" << endl;
            linkout_nodes_.insert(node);
        }
        //cout << linkout_nodes_.size() << endl;
    }

    double GetPageRank()
    {
        return page_rank_;
    }

    void SetPageRank(double pr)
    {
        page_rank_ = pr;
    }

    double CalcRank()
    {
        double pr = 0;
        set<Node*>::const_iterator citr = linkin_nodes_.begin();
        for (; citr != linkin_nodes_.end(); ++citr)
        {
            Node * node = *citr;
            pr += node->GetPageRank()/node->GetOutBoundNum();
        }
        return pr;
    }

    size_t GetOutBoundNum() 
    {
        return linkout_nodes_.size();
    }

    size_t GetInBoundNum() 
    {
        return linkin_nodes_.size();
    }

    string Get_id() const
    {
        return name_;
    }
    
    bool operator==(const Node& comp_node)
    {
        return name_ == comp_node.Get_id();
    }
    
    void PrintNode()
    {
        cout << name_ << " " << linkout_nodes_.size();
        set<Node*>::const_iterator citr = linkout_nodes_.begin();
        for (; citr != linkout_nodes_.end(); ++citr)
        {
            Node * node = *citr;
            cout << node->Get_id() << " ";
        }
        cout << endl; 
    }
private:
    string name_;
    set<Node*> linkin_nodes_;
    set<Node*> linkout_nodes_;
    double page_rank_;
};

class PageRank
{
public:
    PageRank(double q=0.85);
    ~PageRank(void);
    void Calc(vector<Node> & nodes, int n);
    double Calc(Node* node);
    void PrintPageRank(vector<Node> & nodes, string file_name);
private:
    double q_;
};