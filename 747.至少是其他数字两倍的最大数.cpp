/*
 * @lc app=leetcode.cn id=747 lang=cpp
 *
 * [747] 至少是其他数字两倍的最大数
 */
#include <vector>
using namespace std;

// 线性扫描
// 扫描数组找到唯一的最大元素 m，并记录它的索引 maxIndex
// 再次扫描数组，如果我们找到 x != m，m < 2*x，我们应该返回 -1
// 否则返回 maxIndex

// @lc code=start
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (maxIndex != i && nums[maxIndex] < 2 * nums[i])
                return -1;
        }
        return maxIndex;
    }
};
// @lc code=end

