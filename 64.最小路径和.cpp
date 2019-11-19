/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <vector>
#include <algorithm>
using namespace std;
// 题目要求只能向下和向右走，与最小生成树还是有区别的
// 动态规划的思想是找到递推公式，递推公式的构建在于如何选取什么变量作为动态的值
// 这里的动态值为——到当前点的最小路径值，所以递推公式为：dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);到当前点路径最小的值为上一个点到当前点最小的值+当前点的值

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j ++)
            {
                if(i == 0 && j == 0)
                    dp[i][j] = grid[i][j]; // 边界处理
                else if(i == 0 )
                    dp[i][j] = grid[i][j] + dp[i][j-1]; // 边界处理
                else if(j == 0)
                    dp[i][j] = grid[i][j] + dp[i-1][j]; // 边界处理
                else
                    dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]); // 递推公式：
            }
        }
        return dp[m-1][n-1];
    }
};
// @lc code=end

