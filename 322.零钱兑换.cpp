/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <vector>
using namespace std;
// 很经典的题目，正常的想法是贪心，尽可能使用较大的面额，但是纯粹的贪心会出错，因为最先找到的并不一定是最优解，所以还要dfs进行搜索

// 动态规划的方法来看更简单
// 发现最优子结构：对于金额n，减去某个面额m1后，剩下的金额n-m1还需要所有的面额去凑n-m1,从而形成最优子结构
// 不难发现，f(n)只与f(n-1),f(n-2),f(n-5)有关

// 状态：dp[i]凑成总金额i所需的最小的硬币数

// 状态转移方程：假如面值是1,2,5，则f(n)=min(f(n-1)+1, f(n-2)+1, f(n-5)+1)

// 输出f(n)

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int Max = amount + 1;
        vector<int> dp(amount + 1, Max);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) { // 遍历所有的coin面额
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end

