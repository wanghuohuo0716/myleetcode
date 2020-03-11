/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>
using namespace std;
// 要求的是个序列，一维动态规划
// 难点在于前i个元素的最大和的状态表达式，dp[i]与dp[i-1]的关系
// 状态转移方程：dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);
// 状态转移方程很明显不可能是dp[i] = dp[i - 2] + nums[i]，因为是偶数相加，少了奇数的元素

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 3)
            return nums.size()==0 ? 0 :
                   nums.size()==1 ? nums[0] : max(nums[0], nums[1]);
        vector<int> dp(nums.size()); // dp[i]代表偷前i套房屋的最高金额
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++)
            dp[i] = max(dp[i - 2] + nums[i], dp[i-1]);
        return dp[nums.size() - 1];
    }
};
// @lc code=end

