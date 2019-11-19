/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心索引
 */
// 利用整个数组之和保持不变，同时不断累加左侧的和，用总和减去左侧和计算右侧的和，避免对右侧和计算

#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0, leftsum = 0;
        for (int x: nums) sum += x;

        for (int i = 0; i < nums.size(); ++i) {
            if (leftsum == sum - leftsum - nums[i]) return i; //返回的也是最左侧的索引
            leftsum += nums[i]; //如果不满足的话就累加左侧的和
        }
        return -1;
    }
};
// @lc code=end

