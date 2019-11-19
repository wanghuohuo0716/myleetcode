/*
 * @lc app=leetcode.cn id=661 lang=cpp
 *
 * [661] 图片平滑器
 */
#include <vector>
using namespace std;
// 思路是新建一个二维数组，把平均值计算的结果存在对应位置上。
// 想象两个二维数组矩阵的图像，然后把其中一个求均值后赋值给对应位置的元素

// 难点是没想到边角的地方其实没有那么复杂！！原来一个if就可以把这些特殊情况过滤掉，只保留合适的元素累加
// @lc code=start
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int R = M.size(), C = M[0].size();
        vector<vector<int>> ans(R, vector<int>(C));

        for (int i = 0; i < R; ++i)
            for (int j = 0; j < C; ++j) {
                int count = 0;
                for (int ii = i-1; ii <= i+1; ++ii) // 累加周围的元素
                    for (int jj = j-1; jj <= j+1; ++jj) {
                        if (0 <= ii && ii < R && 0 <= jj && jj < C) { // 去掉不符合要求的元素
                            ans[i][j] += M[ii][jj];
                            count++; //累加的同时记录数目
                        }
                    }
                ans[i][j] /= count; //计算每个点的平均值
            }
        return ans;
    }
};
// @lc code=end

