/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <vector>
#include <algorithm>
using namespace std;
// 乘积 = 当前数左边的乘积 * 当前数右边的乘积
// 数组起始处左边可以看作有一个元素是1，末尾处右边也可以看作有一个元素是1，相当于填了2个元素1

// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        int k = 1;
        for(int i = 0; i < res.size(); i++){
            res[i] = k;
            k = k * nums[i]; // 此时数组res和k存储的是除去当前元素左边的元素乘积
        }
        k = 1;
        for(int i = res.size() - 1; i >= 0; i--){
            res[i] *= k; // 此时数组等于左边的 * 该数右边的。
            k *= nums[i]; // k为该数右边的乘积。
        }
        return res;
    }
};
// @lc code=end

