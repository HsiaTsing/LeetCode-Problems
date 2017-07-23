#include <iostream>
#include <vector>
#include <string>


using namespace std;

/*
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* 
*The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
**/


class Solution {
public:
	bool isValid(string s) {
		vector<char> brackets;
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '(' || s[i] == '{' || s[i] == '['){
				brackets.push_back(s[i]);
			}
			else if ((s[i] == ')' && brackets.empty()) || (s[i] == '}' && brackets.empty()) || (s[i] == ']' && brackets.empty())){
				return false;
			}
			else if ((s[i] == ')' && brackets.back() != '(') || (s[i] == '}' && brackets.back() != '{') || (s[i] == ']' && brackets.back() != '[')){
				return false;
			}
			else if ((s[i] == ')' && brackets.back() == '(') || (s[i] == '}' && brackets.back() == '{') || (s[i] == ']' && brackets.back() == '[')){
				brackets.pop_back();
			}
			else
				;
		}
		if (brackets.empty())
			return true;
		else
			return false;
	}

	void test(){
		string s = "()[]{}";
		cout << isValid(s) << endl;
	}

};