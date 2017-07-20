#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
* Write a function to find the longest common prefix string amongst an array of strings.
*/


class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int len = strs.size();

		if (len == 1)
			return strs[0];

		for (int i = 0; len > 0; i++){ // i-th char
			for (int j = 0; j < len - 1; j++){ //for each string
				if (i >= strs[j].size() || i >= strs[j + 1].size() || strs[j][i] != strs[j + 1][i])
					return strs[0].substr(0, i);
			}
		}
		return string();
	}

	void test(){

		vector<string> strs = { "abcd", "abde", "abca" };
		cout << longestCommonPrefix(strs) << endl;
	}

};