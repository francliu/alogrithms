// BestCode7_25.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <math.h>
#include <string>

#include <iostream>

int main()
{
	int num;
	std::cin >> num;
	std::string s="";
	std::string str = "anniversary";
	for (int i = 1; i <= num; i++)
	{
		bool ok = false;
		std::cin >> s;
		
		for (size_t i = 0; i < 11;i++)
		{
			if (s[i] == str[0])
			{
				int pos = 0;
				while (s[i] == str[pos]&&pos<str.size())
				{
					pos++; 
					i++;
				}
				if (pos == str.size()){ ok = 1;}
				for (size_t j = i+1; j < s.size(); j++)
				{
					if (s[j] == str[pos])
					{
						int pos_1 = pos;
						while (s[j] == str[pos_1] && pos_1 < str.size())
						{
							pos_1++;
							j++;
						}
						if (pos_1 == str.size()){ ok = 1; }
						for (size_t k = j + 1; k < s.size(); k++)
						{
							if (s[k] == str[pos])
							{
								int pos_2 = pos_1;
								while (s[k] == str[pos_2] && pos_2 < str.size())
								{
									pos_2++;
									k++;
								}
								if (pos_2 == str.size()){ ok = 1; }
								k--;
							}
						}
						j--;
					}
				}
				i--;
			}
		}
		if(ok)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/**
1001
#include <iostream>
int main()
{
int num;
std::cin >> num;
int n, m;
double p, q;
for (int i = 1; i <= num; i++)
{
std::cin>>n>>m>>p>>q;
int num_p = n%m;
int num_q = n / m;
int sum = 0;
if (p >= q)
{
if(num_p>0)sum = (1 + num_q)*q;
else sum = num_q*q;
}
else
{
if ((q / m) >= p)sum = n*p;
else
{
if (num_p*p>=q)sum = (1 + num_q)*q;
else sum = p*num_p + num_q*q;
}
}
printf("%d\n", sum);
}
return 0;
}
1003
inline double num_sqrt(double m)
{
return sqrt(9 + 12 * m) / 6 + 0.5;
}
int main()
{
int num;
std::cin >> num;
int m;
int sum;
for (int i = 1; i <= num; i++)
{
sum = 0;
std::cin >> m;
int n, an;
if (m < 7){ sum += m; m = 0; }
else
{
n = num_sqrt(m);
an = 3 * n*(n - 1) + 1;
sum += m / an;
m = m % an;
}
while (m)
{
n -= 1;
if (m < 7){ sum += m; break; }
an = 3 * n*(n - 1) + 1;
if (m>=an)
{
sum += m / an;
m = m%an;
}
}
printf("%d\n",sum);
}
return 0;
}
*/

