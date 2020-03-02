/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */
#include <string>
#include <vector>
#include <sstream>
using namespace std;
// 最长公共子序列的变种问题，leetcode的1143题
// 找到最长公共子序列的长度，两个字符串长度分别减去子串长度，剩下的就是需要操作的次数，再求和即可。

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int N1 = word1.size();
        int N2 = word2.size();
        vector<vector<int> > dp(N1 + 1, vector<int>(N2 + 1));
        for (int i = 1; i <= N1; ++i) {
            for (int j = 1; j <= N2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return N1 + N2 - 2 * dp[N1][N2];
    }
};
// @lc code=end

