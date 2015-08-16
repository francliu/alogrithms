#include "PageRank.h"
#include <iostream>

PageRank::PageRank(double q) : q_(q)
{
    // q_ must < 1
}


PageRank::~PageRank(void)
{
}

void PageRank::Calc(vector<Node> & nodes, int n)
{
    for (int i = 0; i< n; ++i) 
    {
        vector<Node>::iterator citr = nodes.begin();
        for (; citr!=nodes.end(); ++citr) 
        {
            Node* node = &(*citr);
            Calc(node);
        }
    }
	return;
}

void PageRank::PrintPageRank(vector<Node> & nodes, string file_name)
{
    double total_pr = 0;

    ofstream outfile(file_name);

    vector<Node>::iterator citr = nodes.begin();
    for (; citr!=nodes.end(); ++citr) 
    {    
        Node * node = &(*citr);
        //node->PrintNode();
        outfile << node->Get_id() << '\t' << node->GetPageRank() << endl;
        total_pr += node->GetPageRank();
    }
    cout << "Total PR:" << total_pr << endl;

    outfile.close();
	return;
}

double PageRank::Calc(Node * node)
{
    double pr = node->CalcRank();
    if (pr < 0.00000000000000000000001 && pr > -0.00000000000000000000001) //pr == 0
    {
        pr = 1-q_;
    }
    else 
    {
        pr = pr * q_ + 1-q_;
    }
    node->SetPageRank(pr);
    return pr;
}