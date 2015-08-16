#include<iostream>
#include<vector>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL)return NULL;
		if (k <= 1)return head;
		ListNode* reverse_head = new ListNode(0);
		reverse_head->next = head;
		ListNode* reverse_end = head;
		ListNode* reverse_before = reverse_head;
		ListNode* temp = NULL;
		int num = 1;
		while (reverse_end->next)
		{
			reverse_end = reverse_end->next;
			num++;
		}
		if (num<k)return head;
		reverse_end = reverse_before;
		int mulit = num / k;
		ListNode* end = reverse_before->next;
		while (reverse_end)
		{
			if (mulit == 0)break;
			if (reverse_before == reverse_end)
			{
				for (int i = 1; i <= k; i++)
				{
					reverse_end = reverse_end->next;
				}
				--mulit;
			}
			end = reverse_before->next;
			while (reverse_before->next != reverse_end)
			{
				temp = reverse_end->next;
				reverse_end->next = reverse_before->next;
				reverse_before->next = reverse_before->next->next;
				reverse_end->next->next = temp;
			}
			reverse_before = reverse_end = end;

		}
		return reverse_head->next;
	}
};
int main()
{
	ListNode* head = new ListNode(1);
	ListNode* p = head;
	p->next = new ListNode(2);
	p = p->next;
	p->next = new ListNode(3);
	p = p->next;
	Solution s;
	s.reverseKGroup(head, 2);
}