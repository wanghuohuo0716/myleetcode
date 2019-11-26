/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */
#include <vector>
#include <algorithm>
using namespace std;
// 鸽子洞原理，又被称为抽屉原理
// nums 中的每个数字都是一个 “鸽子”，nums 中*可以*出现的每个不同的数字都是一个 “鸽子洞”。因为有n+1个数是n个不同的可能数，鸽子洞原理意味着至少有一个数是重复的。

// 排序后，比较相邻两个数是否相等

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                return nums[i];
            }
        }
        return -1;
    }
};
// @lc code=end

