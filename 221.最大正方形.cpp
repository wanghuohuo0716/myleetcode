/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */
#include <vector>
using namespace std;
// 状态：dp[i][j]为以(i,j)为右下角的最大正方形的边长(不是面积)

// 不难发现，dp[i][j]与其周围的三个状态有关，可以通过画图分析出来
// 状态转移关系：dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1

// 状态初始化：第一行和第一列，元素是1，则dp为1。dp[i][j] = matrix[i][j] - '0'

// 输出：dp中最大的元素

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size(), n = matrix[0].size(), sz = 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!i || !j || matrix[i][j] == '0') // 相当于初始化
                    dp[i][j] = matrix[i][j] - '0';
                else
                    dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                sz = max(dp[i][j], sz);
            }
        }
        return sz * sz; // 面积
    }
};
// @lc code=end

