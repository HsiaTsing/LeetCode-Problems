#include <iostream>
#include <vector>
#include <string>


using namespace std;

/*
* Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
**/

//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *l, *head;

		if (l1 == NULL)
			return l2;
		if (l2 == NULL)
			return l1;

		if (l1->val < l2->val){
			l = l1;
			l1 = l1->next;
		}
		else{
			l = l2;
			l2 = l2->next;
		}

		head = l;

		while (l1 != NULL && l2 != NULL){
			if (l1->val < l2->val){
				l->next = l1;
				l = l->next;
				l1 = l1->next;
			}
			else{
				l->next = l2;
				l = l->next;
				l2 = l2->next;
			}
		}
		if (l1 == NULL && l2 != NULL) l->next = l2;
		else if (l1 != NULL && l2 == NULL) l->next = l1;
		else;
		return head;
	}

	void test(){
		ListNode *p1, *p2, *p;

		p1 = p2 = p = 0;

		vector<int> a = { 1, 3, 5, 7, 9 };
		vector<int> b = { 2, 4, 6, 8, 10 };

		p1 = new ListNode(a[0]);

		p = p1;
		for (int i = 1; i < a.size(); i++){
			p->next = new ListNode(a[i]);
			p = p->next;
		}

		p2 = new ListNode(b[0]);

		p = p2;
		for (int i = 1; i < b.size(); i++){
			p->next = new ListNode(b[i]);
			p = p->next;
		}
		
		p = mergeTwoLists(p1, p2);

		while (p != NULL){
			cout << p->val;
			if (p->next != NULL)
				cout << ",";
			else
				cout << endl;
			p = p->next;
		}
	}

};