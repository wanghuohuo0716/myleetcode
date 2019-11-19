/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <vector>
#include <algorithm>
using namespace std;
// target要么在左侧，要么在右侧，分成两半去查找，左侧和右侧都是有序的，首先判断mid是在左侧还是在右侧，然后比较target与mid就知道了target在左侧还是右侧，然后二分查找即可。
// 核心思想是如何移动left和right指针

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left)/2);
            if (nums[mid] == target) {
                return mid;
            }
            //mid位于右半部分
            if (nums[mid] < nums[right]) {
                //target <= nums[right],说明target位于右半部分
                //nums[mid] < target,说明target位于右半部分的右半部分,left = mid + 1
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                }
                //target > nums[right],说明target位于左半部分,right = mid - 1
                //target < nums[mid],说明target位于右半部分的左半部分,right = mid - 1
                else {
                    right = mid - 1;
                }
            }
            //mid位于左半部分
            else if (nums[mid] >= nums[right]) {
                //nums[left] <= target,说明target位于左半部分
                //target < nums[mid],说明target位于左半部分的左半部分,right = mid - 1
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                //nums[left] > target,说明target位于右半部分,left = mid + 1
                //target > nums[mid],说明target位于左半部分的右半部分,left = mid + 1
                else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

