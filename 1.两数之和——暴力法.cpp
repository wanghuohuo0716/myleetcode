/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
using namespace std;
#include <unordered_map>
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++)
        {
            int temp = target - nums[i];
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (temp == nums[j] && j != i)
                {
                    return {i,j};
                }
            }
        }
        return {0, 0};
    }
};
// @lc code=end

