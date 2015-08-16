// music.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

vector<int> music_list(vector<vector<int> > test, vector<int> time)
{
	int len = 0;
	map<int, int> list;
	for (int i = 0; i < test.size(); i++)
	{
		int temp = len;
		len += test[i][0] * test[i][1];

		for (int k = temp+1; k <= len; k++)
		{
			list[k] = i+1;
		}
	}
	vector<int> res;
	for (int i = 0; i < time.size(); i++)
	{
		res.push_back(list[time[i]]);
	}
	return res;
}
int main()
{
	int n = 0, m = 0;

	while (scanf_s("%d %d", &n, &m)!=EOF)
	{
		vector<vector<int> > test;
		vector<int> time;
		while (n--)
		{
			int c, t;
			scanf_s("%d %d\n", &c, &t);
			vector<int> res;
			res.push_back(c);
			res.push_back(t);
			test.push_back(res);
		}
		while (m--)
		{
			int c = 0;
			scanf_s("%d", &c);
			cout << c;
			time.push_back(c);
		}
		vector<int> result = music_list(test, time);
		for (int i = 0; i < result.size(); i++)
		{
			cout << result[i] << " "<<endl;
		}
	}
	return 0;
}

