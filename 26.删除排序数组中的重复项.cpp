/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		vector<int>::size_type nSize = nums.size(); //只有一个元素不需要排列
		if (nSize <= 1)
			return nSize;

		vector<int>::size_type p = 1; // 双指针，快慢指针，把重复的元素放到数组的后面即可。
		for (vector<int>::size_type i = 1; i < nSize; ++i) {
			if (nums[i] != nums[i - 1])
				nums[p++] = nums[i];
		}

		return p;
    }
};
// @lc code=end
