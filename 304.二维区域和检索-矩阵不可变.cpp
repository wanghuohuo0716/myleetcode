/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */
#include <vector>
using namespace std;
// 前缀和的二维版本

// 状态定义:dp[i][j]为矩阵中从(0,0)到(i,j)的矩形内所有元素之和
// 状态转移方程：sumRegion(row1, col1, row2, col2) = dp[row2][col2] - dp[row2][col1 - 1] - dp[row1 - 1][col2] + dp[row1 - 1][col1 - 1]
// 状态方程的理解，参考https://leetcode-cn.com/problems/range-sum-query-2d-immutable/solution/dong-tai-gui-hua-by-powcai-10/


// @lc code=start
class NumMatrix {
private:
    int row, col;
    vector<vector<int>> dp;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        row = matrix.size();
        col = row>0 ? matrix[0].size() : 0;
        dp = vector<vector<int>>(row+1, vector<int>(col+1, 0)); // 多一行0和一列0，避免索引到-1

        // 同时求行列的前缀和
        for(int i=1; i<=row; i++) {
            for(int j=1; j<=col; j++) {
                dp[i][j] = matrix[i-1][j-1] +dp[i-1][j] +dp[i][j-1] -dp[i-1][j-1]; //由于dp比matrix拓展了一行和一列，所以matrix[i-1][j-1]其实就是在dp[i][j]的位置

        // // 列的前缀和
        // for (int i = 1; i <= col;i++)
        //     for (int j = 1; j <= row;j++)
        //         dp[j][i] = dp[j-1][i] + matrix[j-1][i-1];

        // // 行的前缀和
        // for (int i = 1; i <= row;i++)
        //     for (int j = 1; j <= col;j++)
        //         dp[i][j] += dp[i][j-1];
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row2+1][col1] - dp[row1][col2+1] + dp[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

