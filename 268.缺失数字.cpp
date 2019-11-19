/*
 * @lc app=leetcode.cn id=268 lang=cpp
 *
 * [268] 缺失数字
 */
// 一个思想是先排序，利用快排，然后检测前一个数与后一个数之差是否为1
// 另一个思想是用hash表，先把数放到hash表中，然后从1-n循环直接查询每个数是否在数组中出现过来找出缺失的数字。如果使用哈希表，那么每一次查询操作都是常数时间的。
// 数列求和后减去所有数之和就是缺失的数了

#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int i = 0; i < nums.size();i++)
            numSet.insert(nums[i]);

        int expectedNumCount = nums.size() + 1;
        for (int number = 0; number < expectedNumCount; number++) {
            if (numSet.find(number)==numSet.end()) { //判断是等于而不是不等于
                return number;
            }
        }
        return -1;
    }
};
// @lc code=end

