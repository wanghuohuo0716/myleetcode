/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <vector>
using namespace std;
// 可以分为偷第一家和不偷第一家两个链状数组，然后取较大的

// 状态：dp[i]为前i个房屋能偷盗金额最大值(含第i户)
// dp1[i]和dp2[i]的起点是不同的，dp1[0]=dp1[1]=0，dp1[2]=nums[0]。而dp2[0]dp2[1]=0,dp2[2]=nums[1]，两者的起点是不同的

// 两个dp数组只是借用了同一个i，而i的含义也是不同的，起点是不同的！！！

// dp的i与nums的i不是同一个，前者比后者大1，dp[n]是第n户的，而nums最大到n-1
// 相对于房屋直线排列，环形排列可以分为两个直线排列问题，核心思想在于偷盗第一家不偷最后一家，不偷第一家，偷最后一家，两种偷法，然后选择最大值

// 其实思路是比较清晰的，但是代码实现上的优化技巧很trick！
// 状态转移方程与链状是一致的：dp[i]= max(dp[i-1],dp[i-2]+nums[i])，这里的nums[i-2]和nums[i-1]其实就是相当于nums[i]，索引是多少没关系，只要把所有的元素遍历了就行，在打家劫舍(单链)题中，虽然也是i从2开始，但是对dp[0]和dp[1]进行了初始化，也是完全遍历了所有的元素

// @lc code=start
class Solution
{
public:
    int rob(vector<int> &nums){
        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        vector<int> dp1(n + 1), dp2(n + 1); // dp1偷第一家，dp2不偷第一家
        for (int i = 2; i < n + 1; i++){
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i - 2]); // 当i=2时，nums[0],偷第一家，当i=n时，nums[n-2],不偷最后一家
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i - 1]); // 当i=2时，nums[1],不偷第一家，当i=n时，nums[n-1],偷最后一家
        }
        return max(dp1[n], dp2[n]);
    }
};
// @lc code=end
