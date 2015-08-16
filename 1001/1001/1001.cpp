// 1001.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <unordered_map>
#include <stack>
#include <map>
using namespace std;


unordered_map<long long, int> map_temp;
string fractionToDecimal(int numerator, int denominator) {
	if (denominator != 0)
	{
		string res = "";
		long long int n = numerator, d = denominator;
		if (n == 0)return res + "0";
		res += (n>0) ^ (d>0) ? "-" : "";
		res += to_string(abs(n / d));
		n %= d;
		n = abs(n);
		d = abs(d);
		if (n == 0)return res;
		res += ".";
		map_temp[n] = res.size();
		while (n != 0)
		{
			res += to_string((10 * n) / d);
			n = (10 * n) % d;
			if (map_temp.find(n) != map_temp.end())
			{
				int index = map_temp[n];
				res.insert(index, "(");
				res += ")";
				break;
			}
			map_temp[n] = res.size();
		}
		return res;
	}
}
int main()
{

	int n=0;
	while (scanf_s("%d", &n) != EOF)
	{
		if (n == 0)break;
		int len = 0;
		for (int i = 1; i <=n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				double k = 0;
				k = double(j)/ i;
				if (k != 0)
				{
					int val = fractionToDecimal(i, j).size();
					map_temp.clear();
					len = len > val ? len : val;
				}
			}
		}
		printf("%d\n",len);
	}
	return 0;

}



/**
//-----1006
int n = 0;
cin >> n;
while (n--)
{
string s="";
cin >> s;
stack<string> duilie;
for (int i = 0; i < s.size(); i++)
{
if (s[i] != '*')
{
if (s[i] != '+')
{
string str = "";
str += s[i];
while (i + 1<s.size()&&s[i + 1] != '+'&&s[i + 1] != '*')
{
str += s[i+1];
i++;
}
duilie.push(str);
}
}
else if (s[i] == '*')
{
long long  temp = stoi(duilie.top());
duilie.pop();
long long  val = 0;
string str = "";
while (i + 1<s.size()&&s[i + 1] != '+'&&s[i + 1] != '*')
{
str += s[i + 1];
i++;
}
val = (temp * (stoi(str)))%10000;
duilie.push(to_string(val));
}
}
long long  sum = 0;
if (duilie.size() == 1)
{
sum = stoi(duilie.top());
printf("%d\n", sum % 10000);
}
else
{
while (!duilie.empty())
{
long long  a = stoi(duilie.top());
duilie.pop();
long long  b = stoi(duilie.top());
duilie.pop();
long long  val = (a + b) % 10000;
if (!duilie.empty())duilie.push(to_string(val));
else
{
sum = val;
}
}
printf("%d\n", sum);
}
}
//-----1001
while (scanf_s("%d %d", &n, &m) != EOF)
{
unordered_map<int,int> s;
int sum = 0;
for (int i = n; i <= m; i++)
{
int temp = i;
int flag = 1;
while (temp)
{
int val = temp % 10;
temp = temp / 10;
if (s.find(val) != s.end())
{
flag = 0;
break;
}
else
{
s[val] = 1;
}
}
if (flag == 1)sum++;
s.clear();
}
printf("%d\n", sum);
}
*/