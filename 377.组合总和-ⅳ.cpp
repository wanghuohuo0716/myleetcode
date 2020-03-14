/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */
#include <vector>
#include <algorithm>
using namespace std;
// 自顶而上进行dfs搜索是可以的，但是题目没要求具体的数字，也可以自底而下进行求

// 状态：dp[i]是以nums元素组成正整数i的的组合数目，而不是以i去找nums，i是变化的，nums不变

// 状态转移方程：dp[i]+=dp[i-nums[j]],dp[4]=dp[4-3]+dp[2]+dp[1]，三种之和（通过搜索树可以看出来）

// 输出dp[target]

// 难点：在于理解dp[0]=1,必须能凑出来整数，否则有些数是凑不出来的

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1; // dp[0] = 1，表示，如果那个硬币的面值刚刚好等于需要凑出的价值，这个就成为 1 种组合方案，否则就没有组合方案
    for (int i = 1; i <= target; i++){
        for (int j = 0; j < nums.size(); j++){
            if (i >= nums[j])
                dp[i] = (dp[i] >= INT_MAX - dp[i - nums[j]]) ? INT_MAX : dp[i] + dp[i - nums[j]]; // 这里要判断dp[i] + dp[i - nums[j]]相加之前是否超int范围，因为与最终的dp[target]无关
        }
    }
    return dp[target];
    }
};
// @lc code=end

