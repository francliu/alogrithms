// Reversestring.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class Solution {
public:
	void reverseWords(string &s) {
		string str = "";
		int i = 0;
		while (s[i] == ' ')i++;
		s = s.substr(i);
		if (s == "")return;
		int len = s.size() - 1;
		while (s[len] == ' ')len--;
		s = s.substr(0, len + 1);
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] == ' ')
			{
				if (s.substr(i) != " ")str += s.substr(i + 1) + ' ';
				if (i - 1 >= 0)while (s[i - 1] == s[i])i--;
				s = s.substr(0, i);
			}
		}
		if (s.size()>0)str += s;
		else s = str.substr(0, str.size() - 1);
		s = str;
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	string str = "a";
	s.reverseWords(str);
	cout << str;
	return 0;
}

