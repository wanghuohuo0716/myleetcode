/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        auto left = nums.begin(), right = nums.end(); //C++primer plus P677介绍了auto和begin，end函数
        while (left < right) {
            auto mid = left + ((right - left) >> 1); // 右移1位，等于除以2。如果差是奇数的话，相当于奇数+1再除以2.
            if (target > *mid) {
                left = mid + 1; // 二分法查找，难点在于边界条件+1的确定上
            } else {
                right = mid;
            }
        }
        return left - nums.begin(); //val比当前left处的元素小，比left-1的元素大。
    }
};
// @lc code=end

