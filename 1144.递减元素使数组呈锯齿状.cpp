/*
 * @lc app=leetcode.cn id=1144 lang=cpp
 *
 * [1144] 递减元素使数组呈锯齿状
 */
#include <vector>
#include <algorithm>
using namespace std;
// 暴力法，维护两种操作的次数，直接减就是最小的次数了
// 分两种情况讨论，要么将奇数位置的元素减少到刚好比相邻的偶数位置元素小，要么将偶数位置的元素减少到刚好比相邻的奇数位置元素小。返回两种情况操作较少的作为答案。
// 分别计算每种情况操作的次数
// tip:如果出现索引为负，可以用条件判断语句解决端点问题。int l = (i > 0) ? nums[i - 1] : INT_MAX;

// @lc code=start
class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        if (nums.size() < 2)
            return 0;
        int s1 = 0;
        int s2 = 0;
        int N = nums.size();
        for (int i = 0; i < N; ++i) {
            int l = (i > 0) ? nums[i - 1] : INT_MAX;
            int r = (i < N - 1) ? nums[i + 1] : INT_MAX;
            if (i & 1) { // 偶数位置大，nums[i]为奇数，要降到小于两边的偶数，选择两边中小的那个，如果本来就小就不用降，否则为负数
                s1 += max(0, nums[i] - min(l, r) + 1);
            } else { // 奇数位置大，nums[i]为偶数，要降到小于两边的奇数，选择两边中小的那个
                s2 += max(0, nums[i] - min(l, r) + 1);
            }
        }
        return min(s1, s2);
    }
};
// @lc code=end

