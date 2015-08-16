#include <string>
#include <map>
#include "PageRank.h"

using namespace std;

void InitGraph(vector<Node> & nodes) 
{
	map<string, int > name2index;
	int index = 0;
    ifstream graph_file("test.txt");
	while (!graph_file.eof())
	{
		string from, to;
		graph_file >> from >> to;
		Node node_from(from);
		Node node_to(to);

		map<string, int> ::iterator it = name2index.find(from);
		if (it == name2index.end()) //new node
		{
			nodes.push_back(node_from);
			name2index[from] = index++;
		}

		it = name2index.find(to);
		if (it == name2index.end()) //new node
		{
			nodes.push_back(node_to);
			name2index[to] = index++;
		}

		int index_from = name2index[from];
		int index_to = name2index[to];
		nodes[index_to].InsertLinkdInNode(&nodes[index_from]);
	}
    graph_file.close();
}

void InitGraph2(vector<Node> & nodes)
{   
    // example 1
    Node a("A");
    Node b("B");
    Node c("C");
    Node d("D");
    nodes.push_back(b);
    nodes.push_back(a);
    nodes.push_back(c);
    nodes.push_back(d);
    // link in node
    // a <- b, c, d
    nodes[1].InsertLinkdInNode(&nodes[0]);
    nodes[1].InsertLinkdInNode(&nodes[2]);
    nodes[1].InsertLinkdInNode(&nodes[3]);
    // b <- d
    nodes[0].InsertLinkdInNode(&nodes[3]);
    // c <- b, d
    nodes[2].InsertLinkdInNode(&nodes[0]);
    nodes[2].InsertLinkdInNode(&nodes[3]);

}

void print_graph(vector<Node> & nodes)
{
    for (int i = 0; i < nodes.size(); ++i)
    {
        nodes[i].PrintNode();
    }
    return ;
}

void TestPageRank()
{
    // build graph
    vector<Node> nodes;
	vector<Node> nodes2;
    //InitGraph(nodes);
	InitGraph2(nodes2);
    print_graph(nodes);
    PageRank pr;

    pr.Calc(nodes, 40);
    //cout << nodes.size() << endl;

    pr.PrintPageRank(nodes, "PR_Graph.txt");
}

int main()
{
    TestPageRank();
    return 0;
}

/*

*/