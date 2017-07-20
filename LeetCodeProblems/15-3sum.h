#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
*
* Note: The solution set must not contain duplicate triplets.
*
* For example, given array S = [-1, 0, 1, 2, -1, -4],
*
* A solution set is:
* [
*   [-1, 0, 1],
*   [-1, -1, 2]
* ]
**/


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {

		vector<vector<int>> results;

		if (nums.size() < 3)
			return vector<vector<int>>();

		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++){

			int l = i + 1; int r = nums.size() - 1;
			int v; int lv; int rv;

			while (l < r && r <= nums.size() - 1){

				v = nums[i]; lv = nums[l]; rv = nums[r];

				if (v + lv + rv == 0){
					vector<int> res3; res3.push_back(v); res3.push_back(lv); res3.push_back(rv);
					results.push_back(res3);
					while (l < r && nums[l] == lv) l++;
					while (l < r && nums[r] == rv) r--;
				}
				else if (lv + v + rv > 0){
					r--;
				}
				else{
					l++;
				}
			}

			while (i < nums.size() - 2 && nums[i + 1] == nums[i]) i++;

		}

		return 	results;
	}
	void test(){

		vector<int> nums = { -1, 0, 1, 2, -1, -4 };
		vector<vector<int>> res = threeSum(nums);

		cout << "[" << endl;
		for (int i = 0; i < res.size(); i++){
			cout << "  [";
			for (int j = 0; j < res[i].size(); j++){
				cout << res[i][j];
				if (j != res[i].size() - 1)
					cout << ", ";
			}
			cout << "]" << endl;
		}
		cout << "]" << endl;
	}

};