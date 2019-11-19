/*
 * @lc app=leetcode.cn id=566 lang=cpp
 *
 * [566] 重塑矩阵
 */
#include <vector>
using namespace std;
// 核心思想是新矩阵的第i行，第j列的元素，对应到原矩阵中的哪行(i * c + j) / col]，哪列(i * c + j) % col。这个数学转换公式
// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int row = nums.size();
		int col = nums[0].size();
		if (row * col != r * c)
			return nums;
		else {
			vector<vector<int>> ans(r, vector<int>(c));
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++)
					ans[i][j] = nums[(i * c + j) / col][(i * c + j) % col];
			}
			return ans;
		}
    }
};
// @lc code=end

