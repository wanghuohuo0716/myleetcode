/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */
#include <vector>
#include <algorithm>
using namespace std;
// 复制原来的数组，然后进行排序，比较新数组与原来数组最左边和最右边不同的索引，两个差值就是结果

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> snums(nums);
        sort(snums.begin(),snums.end());
        int start = snums.size(), end = 0;
        for (int i = 0; i < snums.size(); i++) {
            if (snums[i] != nums[i]) {
                start = min(start, i); // start进来一次就行了，在最左边，利用了隐含的顺序解决了标志位的问题，简洁
                end = max(end, i); // 但是end要取到最大，所以用max
            }
        }
        return (end - start >= 0 ? end - start + 1 : 0);
    }
};
// @lc code=end

