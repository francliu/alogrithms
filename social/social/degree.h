/*************************************************************************
> File Name: dregree.h
> Author: 刘建飞
> Mail: liujianfei526@163.com
> Created Time: 2015年04月06日 星期一 23时09分51秒
************************************************************************/
#include<iostream>
#include<vector>
#include"matrix.h"
using namespace std;
class degree
{
public:
	matrix m;

	bool is_has(vector<int> temp, int a)
	{
		if (temp.empty())
			return false;
		for (size_t i = 0; i<temp.size(); i++)
		{
			if (temp[i] == a)return true;
		}
		return false;
	}
	void degree_centrality(float Node[10], vector<vector<int> > adjacgraph, int n)
	{
		for (int i = 0; i<n; i++)
		{
			Node[i] = adjacgraph[i].size() / 2;
		}
		for (int i = 0; i<n; i++)
		{
			printf("%.2f ", Node[i]);
		}
		printf("\n");

	}
	void Katz_centrality(float Node[10], float vertex[][N], int n, float a, float b)
	{
		float I[10][10], temp[10][10];
		m.mutex(I, vertex, a, n);
		m.Gauss(I, temp, n);
		//矩阵与向量相乘
		for (int i = 0; i < n; i++)
		{
			float num = 0;
			for (int j = 0; j < n; j++)
			{
				num += temp[i][j];
			}
			Node[i] = b*num;
		}
		for (int i = 0; i < n; i++)
		{
			printf("%.2f ", Node[i]);
		}
		printf("\n");
	}
	void PageRank(float Node[10], float vertex[][N], int n, float a, float b)
	{
		float I[10][10], temp[10][10], invD[10][10], D[10][10];
		//for(int i=0;i<10;i++)
		//	cout<<Node[i]<<endl;
		m.dialog(D, Node);
		m.Gauss(D, invD, n);
		//print(vertex,n);
		//print(D,n);
		//print(invD,n);
		m.muti_matric(temp, invD, vertex);
		//print(temp,n);
		m.mutex(I, temp, a, n);
		m.Gauss(I, temp, n);
		//print(temp,n);
		//矩阵与向量相乘
		for (int i = 0; i < n; i++)
		{
			Node[i] = 0;
			for (int j = 0; j < n; j++)
			{
				Node[i] += temp[i][j];
			}
			Node[i] *= b;
		}
		for (int i = 0; i < n; i++)
		{
			printf("%.2f ", Node[i]);
		}
		printf("\n");
	}
	void betweenness_centrality(vector<vector<vector<vector<int> > > > p_all, float Node[], int n)
	{
		for (int k = 0; k<n; k++)
		{
			Node[k] = 0;
			//printf("%f",Node[k]);
			for (int i = 0; i<n; i++)
			{
				if (i == k)continue;
				for (int j = i + 1; j<n; j++)
				{
					if (j == k)continue;
					float count = 0;
					if (!p_all[i][j].empty())
					{
						for (int m = 0; m<p_all[i][j].size(); m++)
						{
							if (is_has(p_all[i][j][m], k))count++;
						}
					}
					//printf("%.2f",Node[k]);
					if (count>0)Node[k] += (count / (float)p_all[i][j].size());
					Node[k] += 0;
				}
			}
			Node[k] *= 2;
			//printf("%.2f",Node[k]);
		}
		for (int i = 0; i<n; i++)
		{
			printf("%.2f ", Node[i]);
		}
		printf("\n");
	}
	void closeness_centrality(vector<vector<vector<vector<int> > > > p_all, float Node[], int n)
	{
		for (int k = 0; k<n; k++)
		{
			Node[k] = 0;
			for (int i = 0; i<n; i++)
			{
				if (i == k)continue;
				Node[k] += (float)(p_all[k][i].size()>0 ? p_all[k][i][0].size() + 1 : 1);
			}
			Node[k] = n / Node[k];
			//printf("%.2f",Node[k]);
		}
		for (int i = 0; i<n; i++)
		{
			printf("%.2f ", Node[i]);
		}
	}


};
