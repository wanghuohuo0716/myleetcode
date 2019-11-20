/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
#include <vector>
#include <algorithm>
using namespace std;
// 矩阵元素蛇形升序，其实就相当于是线性数组了，在这种升序查找中，二分查找效率最高
// 只要把数组索引从线性对应转换成行和列即可，数组索引index对应矩阵的，行：index/col，列：index%col

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    if (m == 0) return false;
    int n = matrix[0].size();

    // 二分查找
    int left = 0, right = m * n - 1;
    int pivotIdx, pivotElement;
    while (left <= right) {
        pivotIdx = (left + right) / 2;
        pivotElement = matrix[pivotIdx / n][pivotIdx % n];
        if (target == pivotElement)
            return true;
        else {
            if (target < pivotElement)
                right = pivotIdx - 1;
            else
                left = pivotIdx + 1;
        }
    }
    return false;
    }
};
// @lc code=end

