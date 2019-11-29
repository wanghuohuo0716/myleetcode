/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于K的子数组
 */
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// 双指针法
// 双指针法的核心是更新慢指针的条件如何选择
// 慢指针遍历整个数组，快指针指的位置中间的数的乘积大于等于k时，更新慢指针，计算子数组的个数（此时慢指针指向起点，快指针指向终点）
// 为加快乘积计算速度，可以以慢指针指向的位置最为子数组的终点，快指针作为起点，保存之前的计算结果

// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int now = 1, times = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            now *= nums[right];
            while (now >= k) now /= nums[left++];
            times += right - left + 1;
        }
        return times;
    }
};
// @lc code=end

