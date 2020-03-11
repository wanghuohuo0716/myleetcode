/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <vector>
using namespace std;
// 这道题不太好懂的是题意。
// 1、每一个位置都有 2 个阶梯，1 个阶梯上一层楼，另 1 个阶梯上两层楼；
// 2、上两个阶梯的体力值耗费是一样的，但是在不同位置消耗的体力值是不一样的；
// 3、楼层顶部在数组之外。如果数组长度为 len，那么楼顶就在索引为 len 这个位置。

// 状态：dp[i] 表示到索引为 i 位置再选择向上爬一共需要的最小体力开销。(不是爬到顶层，而是在i层也要消耗体力)

// 状态转移方程：dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]

// 初始化：dp[0] = cost[0]; dp[1] = cost[1];

// 输出： min(dp[len - 1], dp[len - 2])


// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t size = cost.size();
        vector<int> dp(size, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < size; ++i) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }
        return min(dp[size - 1], dp[size - 2]);
    }
};
// @lc code=end

