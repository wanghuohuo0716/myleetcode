/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <vector>
#include <algorithm>
using namespace std;
// 为什么双指针法可以降低复杂度？这在数学上是可以证明的，通过消去一些状态减少计算量。理解：面积与短边有关，与长边无关！
// 双指针指向内移动的规则：线段较短的指针向内移动，虽然这会消去一些状态，但这些状态可以证明是小于等于较短指针的线段构成的矩形面积：这些状态下的短板高度不会增加，底边宽度更短
// 为什么不移动长指针？假设移动后线段更长了，矩形区域的面积仍然将受限于之前较短的线段而不会获得任何增加。
// 消去的这些状态以及计算的状态构成了所有完备的状态，所以算法是可行的！

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 暴力法超时
        // int maxarea = 0;
        // for (int i = 0; i < height.size(); i++)
        //     for (int j = i + 1; j < height.size(); j++)
        //         maxarea = max(maxarea, min(height[i], height[j]) * (j - i));
        // return maxarea;
        int maxarea = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
};
// @lc code=end

