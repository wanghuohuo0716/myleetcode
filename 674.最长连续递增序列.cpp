/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */
#include <vector>
using namespace std;
// 解决方法：滑动窗口法，记录历史最大的和当前最大的比较
// @lc code=start
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 0, anchor = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i-1] >= nums[i]) anchor = i;
            ans = max(ans, i - anchor + 1);
        }
        return ans;
    }
};
// @lc code=end

