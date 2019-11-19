/*
 * @lc app=leetcode.cn id=485 lang=cpp
 *
 * [485] 最大连续1的个数
 */
#include <vector>
#include <unordered_set>
using namespace std;
// 和最大连续数之和那道题类似，维持两个变量，一个是当前最大连续1的次数max，一个是当前连续1的次数count
// 比较两个大小，较大的保存到max中，count清零，继续遍历，考虑特殊情况，到了结尾全部都是1，不能只是遇到了0才判断count和max
// @lc code=start
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0, max = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                max = max > count ? max : count;
                count = 0;
            }
        }
        max = max > count ? max : count;
        return max;
    }
};
// @lc code=end

