/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <vector>
#include <algorithm>
using namespace std;
// 对于每个i，它都可以表达为，存在一个j，使得i等于i-j*j与j*j的和
// 状态：dp[i]为组成i的完全平方数的最小个数

// 这道题是自顶而下进行拆分的

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        if (n<0)
            return 0;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j*j <= i; j++)
                dp[i] = min(dp[i], dp[i - j*j] + 1);
        return dp.back();
    }
};
// @lc code=end

