#include <iostream>
#include <vector>

using namespace std;

/*
* Given a linked list, swap every two adjacent nodes and return its head.
* 
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
**/

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *p1, *p2, *pre;

		if (head == NULL || head->next == NULL)
			return head;

		p1 = p2 = head;
		p2 = p2->next;

		swap(p1, p2, head);

		while (p2->next != NULL){
			pre = p2; p1 = p2->next;
			if (p1->next == NULL) break;
			p2 = p1->next;

			swap(p1, p2, pre->next);
		}

		return head;
	}

	void swap(ListNode* &p1, ListNode* &p2, ListNode* &pre){
		p1->next = p2->next; p2->next = p1;	pre = p2;
		ListNode* tmp = p1;	p1 = p2; p2 = tmp;
	}

	void test(){
		ListNode *p1, *p;

		p = p1 = NULL;

		vector<int> a = { 1, 2, 3, 4 };

		p1 = new ListNode(a[0]);
		p = p1;
		for (int i = 1; i < a.size(); i++){
			p->next = new ListNode(a[i]);
			p = p->next;
		}

		p = swapPairs(p1);

		while (p != NULL)
		{
			cout << p->val;
			p = p->next;
			if (p != NULL)
				cout << "->";
			else
				cout << endl;
		}
	}

};