/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */
#include <vector>
using namespace std;
// 状态：dp[i]为以nums[i]为结尾的子序列的最大长度，注意包含nums[i]
// 状态转移方程：在索引 i 之前严格小于 nums[i] 的所有状态中的最大者 + 1，因为这个状态转移与前面所有的状态都有关系，要找到最大的一个状态
// 初始化：每个字符都是长度为1的子序列

// https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int N = nums.size();
        vector<int> dp(N, 1); // 每个字符都是长度为1的子序列
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) { // 状态转移方程
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
// @lc code=end

