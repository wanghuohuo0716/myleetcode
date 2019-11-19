/*
 * @lc app=leetcode.cn id=697 lang=cpp
 *
 * [697] 数组的度
 */
#include <vector>
#include <unordered_map>
using namespace std;
// 使用hash表来记录数组元素的属性，如次数，第一次出现的索引，最后一次的索引等等，是最简单的了！！！

// @lc code=start
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int numsSize = nums.size(), res = INT_MAX, degree = 0;
        unordered_map<int, int> numsCnt;//记录各个数字出现的次数
        unordered_map<int, pair<int, int>> pos;//记录各个数字第一次、最后一次出现的下标
        for (int i = 0; i < numsSize; ++i) {
            if (++numsCnt[nums[i]] == 1) {
                //元素第一次出现
                pos[nums[i]] = {i, i};
            }
            else {
                //更新最后出现的下标
                pos[nums[i]].second = i;
            }
            //更新出现次数最多的元素次数
            degree = max(degree, numsCnt[nums[i]]);
        }

        // 计算子序列长度
        for (auto &item : numsCnt) {
            if (degree == item.second) {//此元素出现的次数等于数组的度，找到此元素了
                //包含数组中出现的所有item.first需要的最少长度就是[pos[item.first].first, pos[item.first].second],第一次出现、最后一次出现
                res = min(res, pos[item.first].second - pos[item.first].first + 1);
            }
        }
        return res;
    }
};
// @lc code=end

