#include <iostream>
#include <vector>


using namespace std;

/*
* Given a linked list, remove the nth node from the end of list and return its head.
*
* For example,
*
* Given linked list: 1->2->3->4->5, and n = 2.
* 
* After removing the second node from the end, the linked list becomes 1->2->3->5.
* 
* Note:
* Given n will always be valid.
* Try to do this in one pass.
**/

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p1, *p2, *p2p;
		p1 = p2 = p2p = head;

		for (int i = 0; i < n; i++){
			p1 = p1->next;
		}

		if (p1 == NULL)
			return head->next;

		while (p1 != NULL){
			p1 = p1->next;
			p2p = p2;
			p2 = p2->next;
		}

		p2p->next = p2p->next->next;

		return head;
	}

	void test(){

		ListNode *p1, *p2, *p;

		p = p1 = NULL;

		vector<int> a = { 1, 2, 3, 4, 5 };

		p1 = new ListNode(a[0]);

		p = p1;
		for (int i = 1; i < a.size(); i++){
			p->next = new ListNode(a[i]);
			p = p->next;
		}

		p2 = removeNthFromEnd(p1, 2);

		while (p2 != NULL){
			cout << p2->val;
			if (p2->next != NULL)
				cout << "->";
			else
				cout << endl;
			p2 = p2->next;
		}

	}

};