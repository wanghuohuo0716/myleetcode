/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include <vector>
using namespace std;
// 要求长度固定为k，求最大均值，其实相当于求k个连续数的最大值
// 立刻想到的就是滑动窗口法，减去最旧的数nums[i-1]，加上最新的数nums[i+k-1]
// @lc code=start
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        for (int i = 0; i < k; ++i)
        {
            sum+=nums[i];
        }

        //记录第一个i  和  i+k   sum+nums[i+k-1]-nums[i-1];
        int temp = sum;
        for (int i = 1; i + k - 1 < nums.size(); ++i)
        {
            temp = temp + nums[i + k - 1] - nums[i - 1];
            if(temp>sum)
                sum = temp;
        }

        return sum / (double)k;
    }
};
// @lc code=end

