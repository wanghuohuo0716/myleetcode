/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

#include <vector>
#include <algorithm>
using namespace std;
// 这种最小路径题一般都是动态规划题，贪心的思想，用二维数组dp[i][j]表示到当前节点的最小路径和
// 递推公式：dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j],由于每一行只有一个最小的值，可以把二维数组压缩成一维数组
// 可以从上往下走，也可以从下往上走，递推公式：dp[i][j] = min(dp[i+1][j-1],dp[i+1][j])+triangle[i][j]

// 从上往下走，一共

// 其实我们dp时候每次只用到上一层数据,如果我们倒着,从底向上可以优化成O(n)空间的
// @lc code=start
class Solution{
public:
    int minimumTotal(vector<vector<int>> &triangle){
        int sum = triangle[0][0], j = 0, temp = 0;
        for (int i = 0; i+1 < triangle.size(); i++){
            temp = min(triangle[i+1][j], triangle[i + 1][j + 1]);
            sum += temp;
        if (temp!=triangle[i+1][j])
            j = j + 1;
        }
        return sum;
    }
};
// @lc code=end
