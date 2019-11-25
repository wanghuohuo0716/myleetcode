/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include <vector>
#include <algorithm>
using namespace std;
// 感觉用二分查找有画蛇添足的感觉，不如直接for循环遍历，比较每个元素的左右值
// 若nums[mid]>nums[mid+1]，说明左侧的值更大，则nums[mid]或者左侧一定存在峰值，因为考虑了nums[−1]=nums[n]=−∞
// “遍历会到达第i个元素”本身就说明上一个元素（第i- 1个）不满足 nums[i] > nums[i + 1]这一条件，也就说明nums[i−1]<nums[i]


// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        for (; left < right; ) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end

