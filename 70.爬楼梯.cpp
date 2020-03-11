/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

#include <vector>
using namespace std;
// 斐波那契数列，经典动态规划题目，注意n可能小于3的情况
// 要求的是个序列，一维动态规划

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if (n<3)
            return n == 1 ? 1 : 2;
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n + 1; i++)
            dp[i] = dp[i - 1] + dp[i - 2];
        return dp[n];
    }
};
// @lc code=end

