#include <iostream>
#include <vector>
#include <string>


using namespace std;

/*
* Given a digit string, return all possible letter combinations that the number could represent.
*
* A mapping of digit to letters (just like on the telephone buttons) is given below.
*
* 1		 2:abc	3:def
* 4:ghi	 4:jkl	6:mno
* 7:pqrs 8:tuv	9:wxyz

* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
* 
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
**/


class Solution {
public:
	vector<string> letterCombinations(string digits) {

		vector<string> res;

		string digitToString[] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

		for (int i = 0; i < digits.size(); i++){
			string str = digitToString[digits[i] - '0'];
			vector<string> tmp;
			for (int j = 0; j < str.size(); j++){
				if (i == 0)
					tmp.push_back(str.substr(j, 1));
				else
					for (int k = 0; k < res.size(); k++)
						tmp.push_back(res[k] + str[j]);
			}
			res = tmp;
		}

		return res;
	}

	void test(){
		string digits = "23";
		vector<string> res = letterCombinations(digits);
		cout << "[";
		for (int i = 0; i < res.size(); i++){
			cout << "\"" << res[i] << "\"";
			if (i != res.size() - 1)
				cout << ", ";
		}
		cout << "]" << endl;

	}

};