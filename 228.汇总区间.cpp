/*
 * @lc app=leetcode.cn id=228 lang=cpp
 *
 * [228] 汇总区间
 */
#include <vector>
#include <algorithm>
using namespace std;
// 双指针法
// 慢指针指向区间的左边，快指针指向区间的右边，当数组的值不满足快指针的值+1则记录快指针的位置作为有边界，同时更新快指针和慢指针的值
// @lc code=start
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<string> res;
        int left = nums[0], right = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != right + 1){
                if (left == right)
                    res.push_back(to_string(left));
                else
                    res.push_back(to_string(left) + "->" + to_string(right));
                left = nums[i];
                right = left;
            }
            else
                right = nums[i];
        }
        // 最后一个需要单独处理下
        if (left == right)
            res.push_back(to_string(left));
        else
            res.push_back(to_string(left) + "->" + to_string(right));
        return res;
    }
};
// @lc code=end

