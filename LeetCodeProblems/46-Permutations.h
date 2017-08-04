#include <iostream>
#include <vector>

using namespace std;

/*
* Given a collection of distinct numbers, return all possible permutations.
*
* For example,
*
* [1,2,3] have the following permutations:
*
* [
*  [1,2,3],
*  [1,3,2],
*  [2,1,3],
*  [2,3,1],
*  [3,1,2],
*  [3,2,1]
* ]
**/


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;	
		permuteR(nums, 0, res);
		return res;
	}

	void permuteR(vector<int> &nums, int pos, vector<vector<int>> &res){
		if (pos >= nums.size()){
			res.push_back(nums);
			return;
		}

		for (int i = pos; i < nums.size(); i++){
			swap(nums[pos], nums[i]);
			permuteR(nums, pos + 1, res);
			swap(nums[pos], nums[i]);
		}
	}

	void test(){
		vector<int> nums = { 1, 2, 3 };

		vector<vector<int>> res = permute(nums);

		cout << "[" << endl;
		for (int i = 0; i < res.size(); i++){
			cout << " [";
			for (int j = 0; j < res[i].size(); j++){
				cout << res[i][j];
				if (j != res[i].size() - 1)
					cout << ",";
				else
					cout << "]" << endl;

			}
		}
		cout << "]" << endl;
	}
};