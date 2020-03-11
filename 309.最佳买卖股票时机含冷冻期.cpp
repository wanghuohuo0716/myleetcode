/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */
#include <vector>
#include <algorithm>
using namespace std;
// 股票问题系列之一
// 状态定义：dp[i][0]和dp[i][1]分别代表第i天持有股票和不持有股票的最大收益

// 这个leetcode回答，详细的说明了代码实现动态规划的一些细节
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/solution/dong-tai-gui-hua-shen-ru-fen-xi-by-wang-yan-19/

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0 or prices.size() == 1) {
            return 0;
        }
        vector<int> hold(prices.size());
        //需要初始化到2，因为n - 2
        hold[0] = -prices[0];
        hold[1] = max(-prices[0], -prices[1]);
        vector<int> unhold(prices.size());
        //需要初始化到2，因为n - 2
        unhold[0] = 0;
        unhold[1] = max(prices[1] - prices[0], 0);
        if (prices.size() == 2) {
            return max(hold[1], unhold[1]);
        }
        int result = INT_MIN;
        for (int i = 2; i < prices.size(); ++i) {
            //0，1已经赋值了，从2开始
            hold[i] = max(hold[i - 1], unhold[i - 2] - prices[i]);
            unhold[i] = max(hold[i - 1] + prices[i], unhold[i - 1]);
            int cur_max = max(hold[i], unhold[i]);
            if (cur_max > result) {
                result = cur_max;
            }
        }
        return result;
    }
};
// @lc code=end

