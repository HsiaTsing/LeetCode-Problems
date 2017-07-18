#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * 
 * Example:
 *   Given nums = [2, 7, 11, 15], target = 9,
 *	 Because nums[0] + nums[1] = 2 + 7 = 9,
 *	 return [0, 1].
 */

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target){
		unordered_map<int, int> hm;

		vector<int> res(2, -1);

		for (int i = 0; i < nums.size(); i++){
			int x = target - nums[i];
			if (hm.find(x) != hm.end()){
				res[0] = hm[target - nums[i]];
				res[1] = i;
				return res;
			}
			hm[nums[i]] = i;
		}
	}

	void test(vector<int> nums = { 2, 7, 11, 15 }, int target = 9){
		vector<int> res = twoSum(nums, target);
		cout << "[" << res[0] << ", " << res[1] << "]" << endl;
	}
};