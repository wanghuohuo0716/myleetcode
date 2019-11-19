/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// 在边界上运动，与54题类似

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int l = 0, r = n - 1, t = 0, b = n - 1;
        vector<vector<int>> mat(n, vector<int>(n));
        int num = 1, tar = n * n;
        while(num <= tar){
            for(int i = l; i <= r; i++) mat[t][i] = num++; // left to right.
            t++;
            for(int i = t; i <= b; i++) mat[i][r] = num++; // top to bottom.
            r--;
            for(int i = r; i >= l; i--) mat[b][i] = num++; // right to left.
            b--;
            for(int i = b; i >= t; i--) mat[i][l] = num++; // bottom to top.
            l++;
        }
        return mat;
    }
};
// @lc code=end

