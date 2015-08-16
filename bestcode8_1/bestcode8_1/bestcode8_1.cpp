// bestcode8_1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int b[100000];
int cmp(int a, int b)
{
	return a > b;
}
void dfs(int n,int& res,int& value)
{
	if (value==0||n == -1)return;
	if (value < b[n])
	{
		dfs(n - 1, res, value);
		return;
	}
	for (int i = 1; i >= 0; i--)
	{
		if (i == 1)
		{
			int temp = value;
			value %= b[n];
			res++;
			dfs(n - 1, res, value);
			if (value == 0)break;
			value = temp;
			res--;
		}
		else
		{
			dfs(n - 1, res, value);
		}
	}
}
int main()
{
	int num;
	scanf_s("%d", &num);
	for (int i = 1; i <= num; i++)
	{
		int n, a;
		scanf_s("%d%d",&n,&a);
		for (int i = 0; i < n; i++)
		{
			scanf_s("%d", &b[i]);
		}
		sort(b, b + n);
		int res = 0;
		dfs(n-1,res,a);
		if(res)printf("%d\n", res);
		else printf("-1\n");
	}
	return 0;
}
/**
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
char s[20000];
int pre[20000];
int end_s[20000];
int pre_pos, end_pos;
void Init()
{
memset(pre, 0, sizeof(pre));
memset(end_s, 0, sizeof(end_s));
pre_pos = end_pos = 0;
}
bool isPal(int start, int end)
{
if (end < start)return 0;
while (start <= end)
{
if (s[start] != s[end])return 0;
start++;
end--;
}
return 1;
}

int main()
{
int n;
scanf("%d", &n);
for (int i = 1; i <= n; i++)
{
Init();
string s;
scanf("%s",s);
int min_pos = s.size();
int len = min_pos;
bool flag = 0;
for (size_t i = 0; i < len; i++)
{
if (isPal(0, i))
{
pre[pre_pos++]=i;
if (i < min_pos)min_pos = i;
if (i == s.size() - 3)
{
flag = 1;
goto hh;
}
}
}
for (size_t i = len - 1; i >= 0; i--)
{
if (i <= min_pos)break;
if (isPal(i, len - 1))
{
end_s[end_pos++] = i;
if (i == 2)
{
flag = 1;
goto hh;
}
}
}
for (size_t i = 0; i < pre_pos; i++)
{
for (size_t j = 0; j < end_pos; j++)
{
if (pre[i] + 1 >= end_s[j])break;
if (isPal(pre[i] + 1, end_s[j] - 1, s))
{
flag = 1;
break;
}
}
if (flag)break;
}
hh:if (flag)printf("Yes");
else printf("No");
}
return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
int n;
cin >> n;
for (int i = 1; i <= n; i++)
{
string s;
cin >> s;
vector<vector<int> > a;
a.resize(s.size());
for (size_t i = 0; i < s.size(); i++)
{
a[i].resize(s.size() - i);
for (size_t j = 0; j <s.size() - i; j++)
{
a[i][j] = 0;
}
}
for (size_t i = 0; i < s.size(); i++)
{
for (size_t j = 0; j <= i; j++)
{
if (i == j)
{
a[j][i - j] = 1;
continue;
}
if (s[j] == s[i])
{
if ((i - j <= 2) || a[j + 1][i - j - 2] == 1)a[j][i - j] = 1;
}
}
}
bool flag = 0;
for (size_t i = 0; i < s.size() - 2; i++)
{
if (a[0][i] == 1)
{
for (int j = i + 1; j < s.size() - 1; j++)
{
if (a[i + 1][j - i - 1] == 1 && a[j + 1][s.size() - j - 2] == 1)
{
flag = 1;
break;
}
}
if (flag)break;
}
}
if(flag)printf("Yes");
else printf("No");
}
return 0;
}
*/