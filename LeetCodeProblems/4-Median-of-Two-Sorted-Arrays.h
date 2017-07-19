#include <iostream>
#include <vector>

using namespace std;

/*
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*
* Example 1:
*   nums1 = [1, 3]
*   nums2 = [2]
*   The median is 2.0
* 
* Example 2:
*   nums1 = [1, 2]
*   nums2 = [3, 4]
*   The median is (2 + 3)/2 = 2.5
*/


class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int totalN = nums1.size() + nums2.size();

		if (totalN % 2 != 0)
			return findMedian(nums1, nums2, totalN / 2 + 1);
		else
			return (findMedian(nums1, nums2, totalN / 2) + findMedian(nums1, nums2, totalN / 2 + 1)) / 2.0;
	}

	double findMedian(vector<int>& nums1, vector<int>& nums2, int target){
		if (nums1.empty())
			return nums2[target - 1];
		else if (nums2.empty())
			return nums1[target - 1];
		else if (target == 1)
			return fmin(nums1[0], nums2[0]);

		int tmp = target / 2;
		if (fmin(nums1.size(), nums2.size()) < tmp)
			tmp = fmin(nums1.size(), nums2.size());

		if (nums1[tmp - 1] >= nums2[tmp - 1]){
			vector<int> nums2_new(nums2.begin() + tmp, nums2.end());
			return findMedian(nums1, nums2_new, target - tmp);
		}
		else if (nums1[tmp - 1] < nums2[tmp - 1]){
			vector<int> nums1_new(nums1.begin() + tmp, nums1.end());
			return findMedian(nums1_new, nums2, target - tmp);
		}
	}

	void test(){
		vector<int> nums1 = { 1, 2 };
		vector<int> nums2 = { 3, 4 };

		cout << findMedianSortedArrays(nums1, nums2) << endl;
	}

};