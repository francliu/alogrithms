// largestRecent.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
#include<vector>
#include<stack>
using namespace std;
struct node{
	int value;
	int num;
};
class Solution {
public:
	int largestRectangleArea(vector<int>& height) {
		if (height.empty())return 0;
		if (height.size() == 1)return height[0];
		stack<node> high;
		int res = 0;
		int len = height.size();
		height.push_back(-1);
		for (size_t i = 0; i<height.size(); i++)
		{
			node k;
			k.value = height[i];
			k.num = 0;
			if (high.empty())high.push(k);
			else if (high.top().value<height[i])high.push(k);
			else
			{
				int num = 0;
				node temp;
				while (!high.empty() && high.top().value >= height[i])
				{
					temp = high.top();
					high.pop();
					num++;
					int value = 0;
					value = temp.value*(num + temp.num+1);
					if (temp.value==height[i])value += temp.value;
					if (res<value)res = value;
					num += temp.num;
				}
				k.num = num;
				high.push(k);
			}
		}
		return res;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<int> height{4, 2, 0, 3, 2, 4, 3, 4};
	s.largestRectangleArea(height);
	return 0;
}

