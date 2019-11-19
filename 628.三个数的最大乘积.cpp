/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */
#include <vector>
using namespace std;
// 最大数可能是两种情况，1.三个最大的正数 2.两个最小的负数一个最大的正数

// 有两种思路来找出这5个数，1是排序 2是线性扫描，维护5个变量即可
// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//        int n = nums.size();
//        return max(nums[0] * nums[1] * nums[n - 1], nums[n - 1] * nums[n - 2] * nums[n - 3]);

        int n = nums.size();
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        for (int i = 0; i < n;i++)
        {
            if (nums[i] <= min1) {
                min2 = min1;
                min1 = nums[i];
            }else if (nums[i] <= min2) {     // n lies between min1 and min2
                min2 = nums[i];
            }

            if (nums[i] >= max1) {            // n is greater than max1, max2 and max3
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            } else if (nums[i] >= max2) {     // n lies betweeen max1 and max2
                max3 = max2;
                max2 = nums[i];
            } else if (nums[i] >= max3) {     // n lies betwen max2 and max3
                max3 = nums[i];
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
// @lc code=end