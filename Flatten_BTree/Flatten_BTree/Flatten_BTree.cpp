// Flatten_BTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "iostream"
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL)return;
		if (root->left == NULL&&root->right == NULL)return;
		if (root->left != NULL)
		{
			TreeNode* left = root->left;
			printf("%d  0\n", root->left->val);
			while (left->right)
			{
				left = left->right;
			}
			left->right = root->right;
			root->right = root->left;
			root->left = NULL;

			flatten(root->left);
		}
		if (root->right != NULL)flatten(root->right);
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	Solution s;
	TreeNode *root,*t = new TreeNode(1);
	root = t;
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(4);
	s.flatten(root);
	while (root)
	{
		printf("%d\n",root->val);
		root = root->right;
	}
	return 0;
}

