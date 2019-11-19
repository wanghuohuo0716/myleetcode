/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 求众数
 */
#include <vector>
using namespace std;
//众数要求的是某个数的重复次数大于一半，可以暴力求解，有重复不要紧，对每个数字从头到尾搜索一遍，计算这个数字的次数，选择最大的那个
//可以用摩尔投票法。因为肯定是有众数存在的，那么遍历整个数组，如果前者和后者相同，则计数器加1，不同则减1，记录当计数器是正值的时候那个数字，虽然会减到负值，但是最终会加到正值，因为众数的重复次数大于一半。
// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums)
    {
        int candidate = nums[0], count = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                candidate = nums[i];
                count = 1;
            }
            else if (nums[i] == candidate)
                {
                    count++;
                }
                else
                {
                    count--;
                }
        }
        return candidate;
    }
};
// @lc code=end

