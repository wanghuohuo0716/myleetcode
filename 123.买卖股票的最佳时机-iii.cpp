/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
#include <vector>
#include <iostream>
using namespace std;
//这道题用动态规划的思想去做更套路，其它方法太tricky
//因为是可以清晰定义有限的状态，状态之间转换也是很明显的，所以用动态规划的方法很正常
//动态规划使用状态数组来解决这种问题
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 1) {
            return 0;
        }
        // 初始化 dp 数组,第 i 天，第 k 笔 交易，是否持有股票,1 持有，0 不持有
        int dp[prices.size()][3][2]={0};
        // 初始化第一天数据，买入股票
        for (int i = 1; i < 3; i++) {
            dp[0][i][1] = -prices[0];
        }
        for (int i = 1; i < prices.size(); i++) {
            for (int j = 1; j <= 2; j++) {
                // 买入再卖出为一笔交易，设卖出的时候完成第j-1笔交易
                // 第 i 天，第 j 笔 交易，不持有股票的最大值。
                // 前一天持有股票今天卖出 / 前一天不持有股票，保持不变
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                // 第 i 天，第 j 笔 交易，持有股票的最大值=
                // 前一天不持有股票今天买入 / 前一天持有股票，保持不变
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[prices.size() - 1][2][0];
    }
};
// @lc code=end

