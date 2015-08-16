// repeat.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int repeat_word(vector<string> s, int k)
{
	map<char, int> t;
	int length = 0;
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s[i].size(); j++)
		{
			if (t.find(s[i][j]) == t.end())
			{
				t[s[i][j]] = 1;
			}
			else if (t.find(s[i][j]) != t.end())
			{
				t[s[i][j]] += 1;
			}
		}
		int max = 0;
		for (auto i = t.begin(); i != t.end(); i++)
		{
			if (i->second >=max)
			{
				max = i->second;
			}
		}
		t.clear();
		if (max >= k)
		{
			length++;
		}
	}
	return length;
}
int main(int argc, _TCHAR* argv[])
{
	int t = 0;
	int n = 0;
	int k = 0;

	scanf_s("%d\n", &t);
	if (t > 20)return 0;
	while (t--)
	{
		scanf_s("%d %d\n", &n, &k);
		if (n > 1000)return 0;
		if (k > 10)return 0;
		vector<string> s;
		int i = 0;
		while (n--)
		{
			string str="";
			cin >> str;
			if (str.size() > 35)return 0;
			s.push_back(str);
			
		}
		int len = repeat_word(s,k);
		printf("%d\n",len);
	}
	return 0;
}

