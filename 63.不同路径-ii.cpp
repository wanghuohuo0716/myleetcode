/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// 相比上一题，思想改变点是如何体现障碍物阻断了路径的同时，推导新的动态规划递推公式
// 解决方法是判断为障碍物后，手动把路径置位0，这样就能保证状态方程不变
// 技巧：如何把第一行和第一列障碍物后面的路径都置位0，dp[i][j] = dp[i][j - 1];

// @lc code=start
class Solution{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid){
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    if (i == 0 && j == 0)
                        dp[i][j] = 1;
                    else if (i == 0)
                        dp[i][j] = dp[i][j - 1];
                    else if (j == 0)
                        dp[i][j] = dp[i - 1][j];
                    else
                        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }
        return dp.back().back();
    }
};
// @lc code=end
