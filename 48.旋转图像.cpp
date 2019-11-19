/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <vector>
#include <algorithm>
using namespace std;
// 先转置再反转

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // transpose matrix
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
      }
    }
    // reverse each row
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n / 2; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][n - j - 1]; // 当j=0时，就知道了n需要-1
        matrix[i][n - j - 1] = tmp;
      }
    }
  }
};
// @lc code=end

