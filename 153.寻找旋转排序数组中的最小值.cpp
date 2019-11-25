/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include <vector>
#include <algorithm>
using namespace std;
// 这道题本质就是找一个数组中的最小值，直接遍历整个数组，维护一个最小值即可，甚至可以不用二分查找，感觉更合适，别让思维陷入了误区

// 旋转之后，最小的数肯定在右半边，关键是判断mid是不是在哪边的升序子序列中
// 判断mid是在左边的升序子序列还是右边的升序子序列，通过比较mid与第一个值和最后一个值的大小
// 如果nums[mid] < nums[right],说明mid在右边升序子序列，最小数在mid左边，nums[mid] > nums[left]，说明mid在左边升序子序列，最小数在mid右边，说明mid要往右移
// 核心在mid如何移动才能找到最小值！
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid]<nums[right]){
                right = mid;
            }
            else {
                left = mid+1;
            }
        }
        return nums[left-1]; //最后跳出来的时候是left>right，而我们要找的是left=right那个值，不会出现死循环的现象，因为left=right时，nums[mid]不可能等于nums[right]，即nums[right]不可能等于nums[right]
    }
};
// @lc code=end
