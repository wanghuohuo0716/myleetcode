/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include <vector>
using namespace std;

// 重点放在选择哪个数学变量作为程序变量，以及如何处理两者之间的关系
// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        if(numRows == 0)    return ans; //若numRows为空，返回空数组
        for(int i = 0; i < numRows; ++ i ) //给数组一个个赋值
        {
            for(int j = 0; j <= i; ++ j) //每行数组长度与行数相同，所以是小于等于
            {
                if(j == 0 || j == i) //若是左右两边的边界，赋值为1
                    ans[i].push_back(1);
                else
                    ans[i].push_back(ans[i-1][j-1] + ans[i-1][j]); //否则赋值为该位置左上与右上的和
            }
        }
        return ans;
    }
};
// @lc code=end

