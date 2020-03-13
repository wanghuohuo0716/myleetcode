/*
 * @lc app=leetcode.cn id=357 lang=cpp
 *
 * [357] 计算各个位数不同的数字个数
 */
#include <vector>
using namespace std;
// 数学的排列组合问题，A_n_m，无放回的抽取，注意首位不能为0
// 可以计算个位，十位，百位，千位的数字，然后所有的数相加

// 状态：dp[i]为从10^i-1到10^i中有多少个，各个位数不同的数字

// 状态转移方程：dp[i]=dp[i-1]*（11-i）,9*9*8*7*6*5...因为每多一位，就会乘一个数

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        vector<int> dp(n+1, 1);
        dp[0] = 1;
        dp[1] = 9;
        int sum = dp[0] + dp[1];
        for (int i = 2; i <= min(n, 10); i++) {
            dp[i] = dp[i-1]*(11-i);
            sum += dp[i];
        }

        return sum;
    }
};
// @lc code=end

