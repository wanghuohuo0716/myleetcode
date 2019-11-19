/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
#include <vector>
#include <iostream>
using namespace std;
//此题与53题类似，53题是连续子序列之和最大，此题是开头和末尾之差最大，都属于动态规划题,构成递推公式，维护两个变量
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int min_val = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            min_val = min(min_val, prices[i]);
            res = max(res, prices[i] - min_val);
        }
        return res;
    }
};
// @lc code=end

