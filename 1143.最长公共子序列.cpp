/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */
#include <string>
#include <vector>
#include <sstream>
using namespace std;
// 最长公共子序列问题是经典的动态规划问题，(还有一种最长公共子序列问题是要求字符是连续的，像两把尺子滑动去比较一样)
// 关键在于寻找状态变量和状态转移方程，使用// 双层循环遍历所有子串来计算公共子串最长的长度
// 两个字符串进行动态规划一般用二维的dp数组来表示，dp[i][j]表示字符串s1从0到i与字符串s2从0到j之间的最长公共字符串长度
// 在原有字符后同时添加一个字符，求dp[i][j]与dp[i-1][j-1]之间的关系，如果两个字符相同，则dp[i][j] = dp[i-1][j-1] + 1;，
// 如果不同，那至少要丢弃一个字符(因为要保持原字符串的相对序列，所以会由不同位置的相同字符来补上)，dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
// 空串与任何字符串的公共子串结果都为0，所以初始化的时候，把状态都设为0

// @lc code=start
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0)); // 状态初始化，不能使用二维数组来定义dp表
        for(int i = 1;i <= n1; ++i){ // 双层循环遍历所有子串
            for(int j = 1;j <= n2; ++j){
                if(text1[i-1] == text2[j-1]){ // 字符相同，因为索引是n-1所以for循环限制条件有等于
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];

    }
};
// @lc code=end

