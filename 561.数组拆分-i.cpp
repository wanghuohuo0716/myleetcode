/*
 * @lc app=leetcode.cn id=561 lang=cpp
 *
 * [561] 数组拆分 I
 */
#include <vector>
#include <algorithm>
using namespace std;
// 这道题类似田忌赛马，由于最后求的是总和最大，所以要尽可能保存大的数，不能让小的和大的在一起，两个数越相近，在一起就越合适。
// (a,b) 可能会产生的最大损失 a−b (如果a>b)。如果这类配对产生的总损失最小化，那么总金额现在将达到最大值。
// 只有当为配对选择的数字比数组的其他元素更接近彼此时，才有可能将每个配对中的损失最小化。

// @lc code=start
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
           sort(nums.begin(),nums.end());
           int sum = 0;
           for(int i =0;i<nums.size();i+=2)
               sum+=nums[i];
           return sum;
    }
};
// @lc code=end

