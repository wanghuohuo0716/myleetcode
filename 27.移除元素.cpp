/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 *
 * https://leetcode-cn.com/problems/remove-element/description/
 *
 *
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    int idx=0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i]!=val)
        {
            nums[idx] = nums[i];
            idx ++;
        }
    }
    return idx;
    }
};
// @lc code=end

