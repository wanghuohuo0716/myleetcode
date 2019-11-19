/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <vector>
#include <algorithm>
using namespace std;
// 与三数之和类似，少了重复数的处理，多了维护一个历史最大的和当前最大的变量
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); i++){
            int start = i + 1, end = nums.size() - 1;
            while(start < end) {
                int sum = nums[start] + nums[end] + nums[i];
                if(abs(target - sum) < abs(target - ans))
                    ans = sum;

                if(sum > target) //移动指针
                    end--;
                else if(sum < target)
                    start++;
                else
                    return ans; // 唯一
            }
        }
        return ans;
    }
};
// @lc code=end

