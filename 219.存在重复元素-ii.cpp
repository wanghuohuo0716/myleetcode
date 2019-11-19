/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */
#include <vector>
#include <unordered_set>//还有unordered_map
using namespace std;
// 一种思路是滑动窗口法，将每个元素与它之前的 k 个元素中比较查看它们是否相等。
// 另一种思路是用hash表，用hash表来维护这个k大小的滑动窗口，从头到尾遍历建立hash表，hash表的键的数目是k个，在hash表中搜索当前元素，如果找到了，说明在两者之差k以内，就返回 true
// 如果当前hash表的数目超过了 k， 说明旧的键距离最新的键距离超过k了，删除hash表中最旧的元素。
// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> set;
    for (int i = 0; i < nums.size(); ++i) {
        if (set.find(nums[i])!=set.end()) return true;
        set.insert(nums[i]);
        if (set.size() > k) {
            set.erase(nums[i - k]);
        }
    }
    return false;
    }
};
// @lc code=end

