/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// 与33题类似，区别是数组中可能会有重复的元素，唯一的区别是存在重复元素时，可能旋转后，两端都是相同的元素，如果这个元素不同target，l和r都得往里面缩

// @lc code=start
class Solution{
public:
    bool search(vector<int> &nums, int target){
        if (nums.size() <= 0 || (nums.size() == 1 && nums[0] != target))
            return false;

        int l = 0, r = nums.size() - 1, m;
        while (l <= r){
            m = (l + r) / 2;
            if (nums[m] == target)
                return true;

            if (nums[m] == nums[l] && nums[m] == nums[r]){ //中间与两边相等时舍弃两边,因为中间已经不是target了，所以两边自然要缩减，区别所在
                l++;
                r--;
            }
            else if (target > nums[m]){
                if (nums[m] <= nums[r] && target > nums[r]) // nums[m] <= nums[r]代表从m到r是连续不减的，而此时的target仍然大于r，说明target不在右半边
                    r = m - 1;
                else
                    l = m + 1;
            }
            else if (target < nums[m]){ // 正常来说应该是r=m-1，但是处在特殊情况下回是l=m+1
                if (nums[m] >= nums[l] && target < nums[l]) // nums[l] <= nums[m]代表从l到m是连续不减的，而此时的target仍然小于l，说明target不在左半边
                    l = m + 1;
                else
                    r = m - 1;
            }
        }
        return false;
    }
};
// @lc code=end
