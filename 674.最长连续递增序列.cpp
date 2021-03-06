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
        int anchor=0, right=0, res=0;
        for (; right < nums.size(); right++){
            if (right > 0 && nums[right - 1] >= nums[right]){
                anchor = right;
            }
            res = max(res, right - anchor + 1);
        }
        return res;
    }
};
// @lc code=end

