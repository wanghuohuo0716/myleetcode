/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <vector>
#include <unordered_set>
using namespace std;
// 思路1是把0和非零元素拿出来，分开后再组合到一起
// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    int n = nums.size();

    // Count the zeroes
    int numZeroes = 0;
    for (int i = 0; i < n; i++) {
        numZeroes += (nums[i] == 0); //计算某个元素的数量的tips
    }

    // Make all the non-zero elements retain their original order.
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            ans.push_back(nums[i]); //把非连续index的数组元素变成连续index，并且保持元素相对顺序不变的tips，不用双指针法
        }
    }

    // Move all zeroes to the end
    while (numZeroes--) { //末尾补0
        ans.push_back(0);
    }

    // Combine the result
    for (int i = 0; i < n; i++) {
        nums[i] = ans[i];
    }
    // 双指针法，空间复杂度为O（n）
    // int lastNonZeroFoundAt = 0;
    // // If the current element is not 0, then we need to
    // // append it just in front of last non 0 element we found.
    // for (int i = 0; i < nums.size(); i++) {
    //     if (nums[i] != 0) {
    //         nums[lastNonZeroFoundAt++] = nums[i];
    //     }
    // }
    // // After we have finished processing new elements,
    // // all the non-zero elements are already at beginning of array.
    // // We just need to fill remaining array with 0's.
    // for (int i = lastNonZeroFoundAt; i < nums.size(); i++) {
    //     nums[i] = 0;
    // }

    }
};
// @lc code=end

