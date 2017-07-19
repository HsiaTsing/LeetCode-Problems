#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
* (you may want to display this pattern in a fixed font for better legibility)
*
* P   A   H   N
* A P L S I I G
* Y   I   R
*
* And then read line by line: "PAHNAPLSIIGYIR"
* Write the code that will take a string and make this conversion given a number of rows:
*
* string convert(string text, int nRows);
* 
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/


class Solution {
public:
	string convert(string s, int numRows) {
		string cs(s);

		vector<vector<char>> rows(numRows);
		int rowIdx = 0; int inc = -1;
		for (int i = 0; i < s.size(); i++){
			rows[rowIdx].push_back(s[i]);
			if (rowIdx >= numRows - 1 || rowIdx <= 0){
				inc = -inc;
			}
			rowIdx += inc;
			if (rowIdx == numRows || rowIdx < 0){
				rowIdx = 0;
			}
		}

		int k = 0;
		for (int i = 0; i < numRows; i++){
			for (int j = 0; j < rows[i].size(); j++){
				cs[k++] = rows[i][j];
			}
		}
		return cs;
	}

	void test(){

		string s = "PAYPALISHIRING";
		cout << convert(s, 3) << endl;
	}

};