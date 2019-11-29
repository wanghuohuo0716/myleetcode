/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */
#include <vector>
#include <algorithm>
using namespace std;
// 动态规划
// 当DP公式不容易看出来的时候，分析找到状态和选择，穷举状态对应的选择就递推出DP公式
// 此题是一维动态规划问题，可以压缩空间，只使用一个变量记录上次的结果即可

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for (int i = 0; i < n; i++) {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
    }
    return dp_i_0;
    }
};
// @lc code=end

