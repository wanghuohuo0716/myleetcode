/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <vector>
#include <algorithm>
using namespace std;
// 思路1：排列组合，从start到finish的步骤是由“向下”和“向右”两个动作组成，每条路都是这些动作的顺序组合，不同的路区别在于同一序列点上的步骤是哪个动作
// 从左上角到右下角，一共要走m+n-2步，然后选出其中的m-1步向右走排列就是，C_(m+n-2)^(m-1)种组合

// 思路2：动态规划，选择横纵坐标的索引作为2种状态，数组的值为到达该状态最多路径的数目，则递推公式为dp[i][j] = dp[i - 1][j] + dp[i][j - 1];

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        for (int i = 0; i < n; i++) dp[0][i] = 1; // 边界处的路径为1
        for (int i = 0; i < m; i++) dp[i][0] = 1; // 边界处的路径为1
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // 动态规划公式
            }
        }
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

