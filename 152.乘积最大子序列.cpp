/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 */
#include <vector>
#include <algorithm>
using namespace std;
// 动态规划的题，子序列的值是以当前子序列为终点的最大连续子序列乘积
// 这与前面的题：求最大连续整数和类似，只不过前面那题的是加减法，这里是乘法
// 加减法都可以视为加法，而乘法有个特点是最小值乘以一个负数变成最大值，最大值乘以一个负数变成最小值
// 所以会需要维持三个变量，max，imax，imin，如果下一个值小于0，就交换imax与imin

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN, imax = 1, imin = 1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] < 0){
              int tmp = imax;
              imax = imin;
              imin = tmp;
            }
            imax = max(imax*nums[i], nums[i]); // 以nums[i]为终点的最大连续子序列的积
            imin = min(imin*nums[i], nums[i]);
            res = max(res, imax);
        }
        return res;
    }
};
// @lc code=end

