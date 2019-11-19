/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
#include <vector>
#include <iostream>
using namespace std;
//股票有三种涨跌情况，1.连续上涨 2.连续下跌 3.价格不变
//1 连续上涨时：连续上涨n天的股票价格是p1,p2,p3,p4,...,pn,则第一天买，最后一天卖收益最大即pn-p1，等价于每天都卖完手上的股票后又重新买了当天的股票即pn-p1=(p2-p1)+(p3-p2)+...+(pn-pn-1)
//2 连续下跌时，不买不卖
//3 价格不变时，不买不卖
//考的是对题目的理解能力，是贪心的思想！
//允许操作多次和只能操作一次是不同的，多次低买高卖 不会比 只操作一次，在最低点买和最高点卖 差，一般来说会更好
// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int tmp;
        for (int i = 1; i < prices.size();i++)
        {
            tmp = prices[i] - prices[i - 1];
            if (tmp > 0)
                profit += tmp;
        }
        return profit;
    }
};
// @lc code=end

