#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
*
* For example,
* 
* [1,1,2] have the following unique permutations:
* 
* [
*  [1,1,2],
*  [1,2,1],
*  [2,1,1]
* ]
**/


class Solution {
public:
	void permuteUniqueR(vector<int> nums, int pos, vector<vector<int> > &res) {
		if (pos == nums.size() - 1) {
			res.push_back(nums);
			return;
		}
		for (int k = pos; k < nums.size(); k++) {
			if (pos != k && nums[pos] == nums[k]) continue;
			swap(nums[pos], nums[k]);
			permuteUniqueR(nums, pos + 1, res);
		}
	}
	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());
		vector<vector<int> >res;
		permuteUniqueR(num, 0, res);
		return res;
	}

	void test(){
		vector<int> nums = { 1,1,2,2 };

		vector<vector<int>> res = permuteUnique(nums);

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