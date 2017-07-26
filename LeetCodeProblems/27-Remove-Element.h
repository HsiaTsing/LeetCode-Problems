#include <iostream>
#include <vector>


using namespace std;

/*
* Given an array and a value, remove all instances of that value in place and return the new length.
*
* Do not allocate extra space for another array, you must do this in place with constant memory.
*
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*
* Example:
* 
* Given input array nums = [3,2,2,3], val = 3
*
* Your function should return length = 2, with the first two elements of nums being 2.
**/


class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int len = 0;
		int k = nums.size() - 1;
		for (int i = 0; i <= k; i++){
			if (nums[i] == val){
				len++;
				swap(nums[i], nums[k]);
				i--; k--;
			}
		}
		return nums.size() - len;
	}
	void swap(int& a, int& b){
		int c = a;
		a = b;
		b = c;
	}
	void test(){
		vector<int> nums = { 3, 2, 2, 3 };
		int val = 3;
		int res = removeElement(nums, val);
		cout << res << endl;
		for (int i = 0; i < res; i++){
			cout << nums[i];
			if (i != res - 1)
				cout << ",";
			else
				cout << endl;
		}
	}

};