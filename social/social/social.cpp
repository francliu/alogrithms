// social.cpp : 定义控制台应用程序的入口点。
/*************************************************************************
> File Name: social.cpp
> Author: 刘建飞
> Mail: liujianfei526@163.com
> Created Time: 2015年4月6日
************************************************************************/
#include "stdafx.h"
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<math.h>
using namespace std;
#define N 10
//邻接矩阵
float vertex[10][10];
//邻接图
vector<vector<int> > adjacgraph;
FILE *fd;
FILE *fout;
void readfile()
{
	char ch;
	int a, b;
	adjacgraph.resize(10);
	while (!feof(fd))
	{
		fscanf_s(fd, "%c %d %d", &ch, &a, &b,1,1,1);
		vertex[a][b] = 1;
		vertex[b][a] = 1;
		adjacgraph[a].push_back(b);
		adjacgraph[b].push_back(a);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	if (fopen_s(&fd,"Q4", "r")!=0)
	{
		printf("open error\n");
	}
	float Node[10];
	memset(Node, 0, sizeof(float)* 10);
	readfile();
	degree d;
	d.degree_centrality(Node, adjacgraph, 10);
	//d.Katz_centrality(Node,vertex,10,0.3,0.3);
	//d.PageRank(Node, vertex, 10, 0.3, 0.3);
	vector<vector<vector<int> > > path;
	Floyd s;
	//s.mulit_floyd(vertex, path, 10);
	vector<int> p;
	//s.path_one(0,9,p,path);
	vector<vector<vector<vector<int> > > > p_all;
	//s.path_all(path, p_all, 10);
	//d.betweenness_centrality(p_all, Node, 10);
	//d.closeness_centrality(p_all, Node, 10);
	/**
	for(int i=0;i<vertex.size();i++)
	{
	for(int j=0;j<vertex[i].size();j++)
	{
	printf("%d ",vertex[i][j]);
	}
	printf("\n");
	}
	for(int i=0;i<adjacgraph.size();i++)
	{
	for(int j=0;j<adjacgraph[i].size();j++)
	{
	printf("%d ",adjacgraph[i][j]);
	}
	printf("\n");
	}
	*/
	fclose(fd);
	return 0;
}

