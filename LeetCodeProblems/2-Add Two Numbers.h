#include <iostream>
#include <vector>

using namespace std;

/*
* You are given two non - empty linked lists representing two non - negative integers.
* The digits are stored in reverse order and each of their nodes contain a single digit.
* Add the two numbers and return it as a linked list.
* You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output : 7 -> 0 -> 8
*/


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int x = l1->val + l2->val;
		int flag = x / 10;
		ListNode *sumListNode = new ListNode(x % 10);
		l1 = l1->next; l2 = l2->next;
		ListNode *head = sumListNode;
		while (true){
			if (l1 == NULL && l2 != NULL)
			{
				x = flag + l2->val;
				l2 = l2->next;
			}
			else if (l1 != NULL && l2 == NULL)
			{
				x = flag + l1->val;
				l1 = l1->next;
			}
			else if (l1 != NULL && l2 != NULL)
			{
				x = flag + l1->val + l2->val;
				l1 = l1->next; l2 = l2->next;

			}
			else{
				if (flag != 0)
					sumListNode->next = new ListNode(flag);
				break;
			}
			sumListNode->next = new ListNode(x % 10);
			flag = x / 10;
			sumListNode = sumListNode->next;
		}
		return head;
	}

	void test(){
		ListNode *p1, *p2, *p;

		p = p1 = p2 = NULL;

		vector<int> a = { 2, 4, 3 }, b = { 5, 6, 4 };

		p1 = new ListNode(a[0]);
		p2 = new ListNode(b[0]);

		p = p1;
		for (int i = 1; i < a.size(); i++){
			p->next = new ListNode(a[i]);
			p = p->next;
		}

		p = p2;
		for (int i = 1; i < b.size(); i++){
			p->next = new ListNode(b[i]);
			p = p->next;
		}

		p = addTwoNumbers(p1, p2);

		while (p != NULL){
			cout << p->val;
			p = p->next;
			if (p != NULL)
				cout << "->";
			else
				cout << endl;
		}
	}

};