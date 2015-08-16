/*************************************************************************
> File Name: floyd.cpp
> Author: 刘建飞
> Mail: liujianfei526@163.com
> Created Time: 2015年04月06日 星期一 20时29分04秒
************************************************************************/

#include<iostream>
#include<vector>
#define MAX 100
using namespace std;
class Floyd
{
public:
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
	void mulit_floyd(float A[][10], vector<vector<vector<int> > > &path, int n)
	{
		float D[10][10];
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				D[i][j] = A[i][j]>0 ? A[i][j] : MAX;
			}
		}
		path.resize(n);
		for (int i = 0; i<n; i++)
		{
			path[i].resize(n);
		}
		for (int k = 0; k<n; k++)
		{
			for (int i = 0; i<n; i++)
			{
				for (int j = 0; j<n; j++)
				{
					if (D[i][j]>D[i][k] + D[k][j])
					{
						D[i][j] = D[i][k] + D[k][j];
						path[i][j].clear();
						path[i][j].push_back(k);
					}
					if ((D[i][j] == D[i][k] + D[k][j]) && k != i&&k != j)
					{
						if (!is_has(path[i][j], k))path[i][j].push_back(k);
					}
				}
			}
		}
		/**
		for(int i=0;i<path.size();i++)
		{
		if(path[i].empty())continue;
		for(int j=0;j<path[i].size();j++)
		{
		if(path[i][j].empty())continue;
		for(int k=0;k<path[i][j].size();k++)
		{
		if(i!=j)printf("[%d,%d] %d ",i,j,path[i][j][k]);
		}
		printf("\n");
		}
		printf("\n");
		}
		*/
	}
	void path_one(int start, int end, vector<int> &p, int k, vector<vector<vector<int> > > path)
	{
		if (!is_has(p, k))p.push_back(k);
		if (!path[start][k].empty())path_one(start, k, p, path[start][k][0], path);
		if (!path[k][end].empty())path_one(k, end, p, path[k][end][0], path);
	}

	void path_all(vector<vector<vector<int> > > path, vector<vector<vector<vector<int> > > > &p_all, int n)
	{
		p_all.resize(n);
		for (int i = 0; i<n; i++)
		{
			p_all[i].resize(n);
		}
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				for (int k = 0; k<path[i][j].size(); k++)
				{
					vector<int> temp;
					if (!path[i][j].empty())
					{
						path_one(i, j, temp, path[i][j][k], path);
						p_all[i][j].push_back(temp);
					}
				}
			}
		}
		/**
		for(int i=0;i<n;i++)
		{
		for(int j=0;j<n;j++)
		{
		if(p_all[i][j].empty())
		{
		printf("[%d,%d] \n",i,j);
		continue;
		}
		for(int k=0;k<p_all[i][j].size();k++)
		{
		for(int m=0;m<p_all[i][j][k].size();m++)
		{
		printf("[%d,%d]%d ",i,j,p_all[i][j][k][m]);
		}
		printf("\n");
		}
		printf("\n");
		}
		}
		*/
	}

};
