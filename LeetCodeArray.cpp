#include "LeetCodeArray.h"

/* LeetCode #35 
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
*/

int LeetCodeArray::searchInsert(vector<int>& nums, int target) {
	int index = 0;
	for (int i : nums) {
		if (target <= i)
			break;
		else
			index++;
	}
	return index;
}
/* LeetCode #35 End */