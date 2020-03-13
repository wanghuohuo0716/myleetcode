/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include <vector>
using namespace std;
// 与凑硬币的类似，这个是用1,2,4,8...去凑，但是这就很复杂了。可以发现数字中1的规律
// 奇数的二进制中1的个数=它上一位偶数的二进制中1的个数+1
// 偶数中二进制1的个数等于这个偶数除以2后的数二进制1的个数,因为偶数的2倍相当于左移1位，末尾填0,1的个数不变。

// 状态:dp[i]为数字i中含有1的数目

// 状态转移方程：dp[i]与i的奇偶有关，i为奇数时候，dp[i] = dp[i - 1] + 1;i为偶数时，dp[i] = dp[i / 2];

// @lc code=start
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for (int i = 1; i <= num; ++i)
            if(i%2==1)
                dp[i] = dp[i - 1] + 1;
            else
                dp[i] = dp[i / 2];
        return dp;
    }
};
// @lc code=end

