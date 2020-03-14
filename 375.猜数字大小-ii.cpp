/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// 相对于easy的猜数字，medium的是不能用二分查找的，因为找到的是针对某个值，计算的金额是针对某个值的，题目要求是确保赢这个游戏，意味着需要足够金额保证，无论怎么猜(最坏的情况)都会赢
// 需要动态规划遍历所有的结果才知道最坏的情况猜需要的金额

// 状态：dp[i][j]，在i到j区间中猜对数字需要的金额

// 状态转移方程：dp(i,j) = min​(pivot+max(dp(i,pivot−1),dp(pivot+1,n))),piovt遍历所有的i到j元素

// 输出dp[1][n]
// 先求长度为1的dp，然后长度为2....最后求长度为n
// 看图理解，https://leetcode-cn.com/problems/guess-number-higher-or-lower-ii/solution/cai-shu-zi-da-xiao-ii-by-leetcode/

// @lc code=start
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i <= n; ++i)
            dp[i][i] = 0;
        for (int len = 2; len <= n; ++len) {
            for (int i = 1; i <= n && i + len - 1 <= n; ++i) {
                int j = i + len - 1;
                dp[i][j] = min(i + dp[i + 1][j], j + dp[i][j - 1]);
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

