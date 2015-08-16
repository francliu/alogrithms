#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		if (nums.size() <= 0)return 1;
		int n = 1;
		int bits[1];
		memset(bits, 0, sizeof(bits));
		for (size_t i = 0; i<nums.size(); i++)
		{
			int value = nums[i] - 1;
			if (nums[i] >= 0)bits[value / 32] |= 1 << (value % 32);
		}
		for (int i = 0; i<n; i++)
		{
			if (bits[i]<INT_MAX)
			{
				for (int j = 0; j<32; j++)
				{
					int off = 1 << j;
					int a = bits[i] & off;
					if (a == 0)return j + 1 + 32 * i;
				}
			}
		}
		return nums.size();
	}
};
int main()
{
	Solution s;
	vector<int> res;
	res.push_back(1);
	cout<<s.firstMissingPositive(res)<<endl;

}