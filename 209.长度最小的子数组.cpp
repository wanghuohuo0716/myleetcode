/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <vector>
#include <algorithm>
using namespace std;
// 每一个数终止的子序列都有一个元素和大于s的最小的子序列长度，然后找到所有数中，长度最小的那个
// 双指针滑动窗口，想象一下，在一个坐标上存在两个指针left 和i ，left 代表滑窗的左边框，i代表滑窗的右边框。两者通过分别向右滑动，前者能使窗口之间的和减小，后者能使窗口之间的和增大。开始时二者重合，窗口的和就是重合点所在的数。
// 1.开始i向右滑动，使和变大。
// 2.当恰好大于等于s时，记录滑窗所包括的子数组长度ans，若ans已有数值，需判断新值是否小于旧值，若是，更新ans。left向右滑动
// 3.判断是否仍大于等于s
// 若是，重复步骤2，3。若否，转步骤1。直到右边框到达最右边

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        while (sum >= s) {
            ans = min(ans, i + 1 - left);
            sum -= nums[left]; // 找到以left开头，同时大于等于s的最小子序列了，要换一个开头
            left++;
        }
    }
    return (ans != INT_MAX) ? ans : 0;
    }
};
// @lc code=end

    int n = nums.size();
    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) { // 这样的写法很赞！把所有的子序列都列出来
                sum += nums[k];
            }
            if (sum >= s) {
                ans = min(ans, (j - i + 1));
                break; //Found the smallest subarray with sum>=s starting with index i, hence move to next index
            }
        }
    }
    return (ans != INT_MAX) ? ans : 0;