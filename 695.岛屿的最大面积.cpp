/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */
#include <vector>
#include <algorithm>
using namespace std;
// 不用判断栅格是不是岛屿，直接按照岛屿的方式计算面积即可，题目理解的重点是如何计算岛屿面积，对栅格进行记录，避免重复访问
// 像这种拓展结点的方式计算面积一定要考虑避免重复访问的问题

// @lc code=start
class Solution {
public:
    int helper(vector<vector<int>>&  grid, int i, int j){
        //由于坐标每次 +1 ，所以判断是否等于数组长度即可
        if (i == grid.size() || i < 0)
            return 0;
        else if (j == grid[0].size() || j < 0)
            return 0; ;
        if (grid[i][j] == 1){
            grid[i][j] = -1;
            return 1 + helper(grid, i + 1, j) + helper(grid, i - 1, j ) + helper(grid, i, j + 1) + helper(grid, i, j - 1);
        }
        return 0;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int area = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    //以此为中心，向四周扩散
                    area = helper(grid, i, j);
                    maxArea = maxArea > area ? maxArea : area;
                }
            }
        }
        return maxArea;
    }
};
// @lc code=end

