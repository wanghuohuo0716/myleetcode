/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */
#include <vector>
using namespace std;

// 状态：dp[i]，以diff[i](diff为相邻差数组)结尾的摆动子序列最长长度(不是前i个元素中，摆动子序列最长长度，这种需要遍历所有状态)
// 状态中dp[i]必须是以元素i结尾的，才能找到dp[i]与dp[i-1]的关系，如果是前i个的话，就需要遍历所有的元素

// 状态转移方程：如果数字之间的差 diff[i] 是异号，即 diff[i] × diff[i-1] < 0， 则有 dp[i] = dp[i-1] + 1，表示最长摆动序列的长度加 1。

// 输出：dp[n]

// https://leetcode-cn.com/problems/wiggle-subsequence/solution/pu-tong-ren-de-dp-by-peter_pan/

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    int N = nums.size();
    if (N <= 1) return N;

    vector<int> diff(N);
    int len = 0;
    for(int i = 1; i < N; i++) { //去除相邻的重复数
        if (nums[i] != nums[i-1])
            diff[len++] = nums[i] - nums[i-1];
    }

    if (len == 0) return 1;	//如果len==0，N >= 2证明相邻的N个数重复是重复的，不存在子序列
    vector<int> dp(len + 1,2); //数组至少有两个数可以组摆动数组
    for (int i = 1; i <= len; i++) {
        if (diff[i] * diff[i-1] < 0)
            dp[i] = dp[i-1] + 1;
        else
            dp[i] = dp[i-1];
    }
    return dp[len];
    }
};
// @lc code=end

