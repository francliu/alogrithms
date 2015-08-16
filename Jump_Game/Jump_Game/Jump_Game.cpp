#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		if (words.size() <= 0 || maxWidth <= 0)return words;
		string s = "";
		bool line_start = true;
		int word_num = 0;
		for (size_t i = 0; i<words.size(); i++)
		{
			if (words[i].size()>maxWidth)return res;
			if ((line_start && s.size() + words[i].size() <= maxWidth) || (!line_start && s.size() + words[i].size() + 1 <= maxWidth))
			{
				if (line_start){ s += words[i]; line_start = false; }
				else s += ' ' + words[i];
				word_num++;
			}
			if ((i + 1<words.size() && line_start && s.size() + words[i + 1].size()>maxWidth) || (i + 1<words.size() && !line_start && s.size() + words[i + 1].size() + 1>maxWidth) || i == words.size() - 1)
			{
				if (word_num>1 && i<words.size() - 1 && maxWidth > s.size())
				{
					int space_len = maxWidth - s.size();
					s += string(space_len, ' ');
					int share_space = space_len / (word_num - 1);
					int from_start_space = space_len % (word_num - 1);
					for (size_t k = s.size() - 1, j = s.size() - 1; k > 0 && j > 0; k--)
					{
						if (word_num>1 && s[k] != ' ')
						{
							while (s[k] != ' ')
							{
								s[j--] = s[k];
								s[k--] = ' ';
							}
							if (j > 0)j -= share_space;
							if (j>0 && from_start_space>0 && from_start_space == word_num - 1){ j--; from_start_space--; }
							word_num--;
						}
					}
				}
				else
				{
					s += string(maxWidth - s.size(), ' ');
				}
				res.push_back(s);
				line_start = true;
				s = "";
				word_num = 0;
			}

		}
		return res;
	}
};
int main()
{
	Solution s;
	vector<string> nums{"Listen", "to", "many,", "speak", "to","a", "few."};
	s.fullJustify(nums,6);

}