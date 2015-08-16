#include <iostream>
#include <vector>
#include <string>
#include <stdio.h>
#include <map>
using namespace std;

#define scanf scanf_s 

int main()
{

	int num = 0;
	cin >> num;
	int sum = num;
	while (num--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<int> > ips;
		while (n--)
		{
			int a, b, c, d;
			vector<int> mid;
			scanf("%d.%d.%d.%d", &a, &b, &c, &d);
			mid.push_back(a);
			mid.push_back(b);
			mid.push_back(c);
			mid.push_back(d);
			ips.push_back(mid);
		}
		vector<vector<int> > ip_mask;
		int len = m;
		while (m--)
		{
			int a, b, c, d;
			vector<int> mid;
			scanf("%d.%d.%d.%d", &a, &b, &c, &d);
			mid.push_back(a);
			mid.push_back(b);
			mid.push_back(c);
			mid.push_back(d);
			ip_mask.push_back(mid);
		}
		vector<int> res;
		res.resize(len);
		for (int i = 0; i < ip_mask.size(); i++)
		{
			map<string, int> temp;
			for (int j = 0; j < ips.size(); j++)
			{
				string s = "";
				int a = (ip_mask[i][0] & ips[j][0]);
				int b = (ip_mask[i][1] & ips[j][1]);
				int c = (ip_mask[i][2] & ips[j][2]);
				int d = (ip_mask[i][3] & ips[j][3]);
				s += a;
				s += b;
				s += c;
				s += d;
				if (temp.find(s) == temp.end())
				{
					temp[s] = 1;
				}
			}
			res[i] = temp.size();
		}
		printf("Case #%d:\n", sum - num);
		for (int i = 0; i < res.size(); i++)
		{
			printf("%d\n", res[i]);
		}
	}
	return 0;


}