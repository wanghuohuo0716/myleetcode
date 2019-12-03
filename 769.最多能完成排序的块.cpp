/*
 * @lc app=leetcode.cn id=769 lang=cpp
 *
 * [769] 最多能完成排序的块
 */
#include <vector>
#include <algorithm>
using namespace std;
// 如果前 k 个元素为 [0, 1, ..., k-1]，可以直接把他们分为一个块。当我们需要检查 [0, 1, ..., n-1] 中前 k+1 个元素是不是 [0, 1, ..., k] 的时候，只需要检查其中最大的数是不是 k 就可以了。
// 说实话没理解题目...不过问题不大，这只是针对这道题的trick，而刷题的目的不在于一题的得失，而是对算法思路的整体把控
// 实力安慰自己~
// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = 0, max_val = 0;
        for (int i = 0; i < arr.size(); ++i) {
            max_val = max(max_val, arr[i]);
            if (max_val == i) ans++;
        }
        return ans;
    }
};
// @lc code=end

