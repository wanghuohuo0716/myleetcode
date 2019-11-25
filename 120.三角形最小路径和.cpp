/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

#include <vector>
#include <algorithm>
using namespace std;
// 自顶而下的最小路径和与自下而上的最小路径和是相同的，所以既可以从上往下，也可以从下往上递推

// 这种最小路径题一般都是动态规划题，用二维数组dp[i][j]表示到当前节点的最小路径和，注意不是贪心的思想，如果是贪心的思想求出来的结果是错的
// 从上往下递推公式：dp[i][j] = min(dp[i-1][j-1],dp[i-1][j])+triangle[i][j]
// 从下往上递推公式：dp[i][j] = min(dp[i+1][j-1],dp[i+1][j])+triangle[i][j]

// 如果是从上往下递推，还得计算达到最后一行n个点中，那个点的路径和最小，从一个点分叉走到n个点；
// 如果是从下往上递推，由于达到的终点是dp[0][0]，所以直接就知道了最下面n个点到顶点的最小路径就是dp[0][0]的值，从n个点汇聚到一个点

// 其实我们dp时候每次只用到上一层数据(上上层及之前的数据都未用到，类似马尔科夫一阶过程),可以优化成O(n)空间复杂度

// DP问题解决的一般步骤：1.找到重复性 2.定义状态数组 3.DP方程 4.初始化数据
// @lc code=start
class Solution{
public:
    int minimumTotal(vector<vector<int>> &triangle){
        int n = triangle.size();
        vector<int> line(triangle[n - 1]);
        for (int i = n - 2; i >= 0; i--)
            for (int j = 0; j <= i; j++)
                line[j] = triangle[i][j] + min(line[j], line[j + 1]);
        return line[0];
    }
};
// @lc code=end
