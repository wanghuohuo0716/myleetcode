/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为K的子数组
 */
#include <vector>
#include <algorithm>
using namespace std;
// 把每个元素的子数组都找一遍
// 双指针法
// 慢指针遍历每个元素，快指针遍历一遍所有元素，然后累加计算为k出现的次数

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    int count = 0,sum = 0;
    for (int start = 0; start < nums.size(); start++) {
        for (int end = start; end < nums.size(); end++) {
            sum += nums[end];
            if (sum == k)
                count++;
        }
        sum = 0;
    }
    return count;
    }
};
// @lc code=end

