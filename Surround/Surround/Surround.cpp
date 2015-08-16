// Surround.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
	void solve(vector<vector<char>>& board) {
		queue<vector<int> > Queue;
		if (board.size() <= 2)return;
		for (int i = 0; i<board.size(); i++)
		{
			for (int j = 0; j<board[i].size(); j++)
			{
				if (i == 0 || j == 0 || i == board.size() - 1 || j == board[i].size() - 1)
				{
					if (board[i][j] == 'O')
					{
						vector<int> a;
						a.push_back(i);
						a.push_back(j);
						Queue.push(a);
						board[i][j] = 'E';
					}
				}
			}
		}

		while (!Queue.empty())
		{
			vector<int> t = Queue.front();
			Queue.pop();

			if (t[0]+1<board.size())
			{
				if (board[t[0] + 1][t[1]] == 'O')
				{
					board[t[0] + 1][t[1]] = 'E';
					vector<int> a;
					a.push_back(t[0] + 1);
					a.push_back(t[1]);
					Queue.push(a);
				}
			}
			if (t[0]-1>=0)
			{
				if (board[t[0] - 1][t[1]] == 'O')
				{
					board[t[0] - 1][t[1]] = 'E';
					vector<int> a;
					a.push_back(t[0] - 1);
					a.push_back(t[1]);
					Queue.push(a);
				}
			}
			if (t[1]+1<board[0].size())
			{
				if (board[t[0]][t[1] + 1] == 'O')
				{
					board[t[0]][t[1] + 1] = 'E';
					vector<int> a;
					a.push_back(t[0]);
					a.push_back(t[1] + 1);
					Queue.push(a);
				}
			}
			if (t[1]-1>=0)
			{
				if (board[t[0]][t[1] - 1] == 'O')
				{
					board[t[0]][t[1] - 1] = 'E';
					vector<int> a;
					a.push_back(t[0]);
					a.push_back(t[1] - 1);
					Queue.push(a);
				}
			}
		}
		for (int i = 0; i<board.size(); i++)
		{
			for (int j = 0; j<board[i].size(); j++)
			{
				if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
				else if (board[i][j] == 'E')
				{
					board[i][j] = 'O';
				}
			}
		}
	}

};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	vector<vector<char>> board;
	board.resize(3);
	for (int i = 0; i<board.size(); i++)
	{
		board[i].resize(3);
		for (int j = 0; j<board[i].size(); j++)
		{
			board[i][j] = 'O';
		}
	}
	s.solve(board);
	return 0;
}

