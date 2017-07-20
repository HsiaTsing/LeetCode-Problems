#include <iostream>
#include <string>

using namespace std;

/*
* Given a roman numeral, convert it to an integer.
*
*Input is guaranteed to be within the range from 1 to 3999.
*/


class Solution {
public:
	int romanToInt(string s) {

		int sum = romanToIntSingle(s.back());
		for (int i = s.size() - 2; i >= 0; i--){
			if (romanToIntSingle(s[i]) < romanToIntSingle(s[i + 1]))
				sum -= romanToIntSingle(s[i]);
			else
				sum += romanToIntSingle(s[i]);
		}
		return sum;
	}

	int romanToIntSingle(char c){
		switch (c){
		case 'M': return 1000;
		case 'D': return 500;
		case 'C': return 100;
		case 'L': return 50;
		case 'X': return 10;
		case 'V': return 5;
		case 'I': return 1;
		default: return 0;
		}
	}

	void test(){

		string s = "XIII";
		cout << romanToInt(s) << endl;
	}

};