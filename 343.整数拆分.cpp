/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include <vector>
using namespace std;
// 这道题就不是一眼看出来能用动态规划，一眼看不出来状态，但是可能发现存在最优子结构，就可能存在多种解题思路。
// 状态：dp[i]为整数i拆分后因数的最大乘积

// 很难发现是与之前的某个状态有关，似乎所有的状态都会影响，那就是和之前全部状态有关
// 状态转移方程：与之前所有的状态都有关，从i中拆出j，使得dp[i-j]和i-j中较大的数与j相乘，找到所有拆的j中最大的那个
// tip:拆分j后dp[i-j]与j不一定谁大，需要比较下，这个细节很重要

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
		vector<int> dp(n + 1, 0);
		dp[1] = 1;
		for (int i=2;i<=n;i++)
			for (int j=1;j<i;j++) // j作为拆分值，i拆分为j和i-j
				dp[i] = max(dp[i], max(dp[i-j], i-j) * j); // 比如2拆分1*1与2相比，i-j就大!
		return dp[n];
    }
};
// @lc code=end

