/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <vector>
#include <algorithm>
using namespace std;
// 本质也是双指针，先排序，才能判断大小，移动指针才有用。
// 保持其中一个数从头到尾遍历，另外两个数是指针，一个从左边向中间寻找，一个从右边向中间寻找
// 三数之和小于0，则left++；大于0，则right--；若等于0，left++，right--。
// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();
        vector<vector<int> > res;
        for (int i = 0; i < N - 2; ++i) { //遍历数组
            if (nums[i] > 0) break; // 三数之和为0，必然最小数小于等于0，i就是最小数
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1;
            int r = N - 1;

            while (l < r) { //对每个元素i，在剩余元素中找是否有存在三个数之和为0，可能有多个组合
                int s = nums[i] + nums[l] + nums[r];
                if (s > 0) {
                    --r;
                } else if (s < 0) {
                    ++l;
                } else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[++l]); // 找到三数之和为0后，才会去除重复的nums[l]
                    while (l < r && nums[r] == nums[--r]); // 去除重复的nums[r]
                }
            }
        }
        return res;
    }
};
// @lc code=end

