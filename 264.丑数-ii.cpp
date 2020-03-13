/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include <vector>
using namespace std;
// 状态：dp[i]为第i个丑数的值

// 状态转移，dp[i]与三个状态有关，dp保存按序排列的丑数，三指针分别是*2，*3，*5，找出下一个丑数
// 状态转移方程：dp[i]=min(dp[t2]*2,min(dp[t3]*3,dp[t5]*5))

// 状态初始化：dp[0]=1,第一个丑数是1，序列是固定的，关键是如何生成

// tip:2,3,5三个指针的乘积有可能存在重复，重复的时候，指针也要自增

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 0) return false; // get rid of corner cases
        if(n == 1) return true; // base case
        int t2 = 0, t3 = 0, t5 = 0; //pointers for 2, 3, 5
        vector<int> dp(n);
        dp[0] = 1;
        for(int i  = 1; i < n ; i ++){
            dp[i] = min(dp[t2]*2,min(dp[t3]*3,dp[t5]*5));
            if(dp[i] == dp[t2]*2) t2++; // 有可能存在重复的数，所以不能用else
            if(dp[i] == dp[t3]*3) t3++;
            if(dp[i] == dp[t5]*5) t5++;
        }
        return dp[n-1];
    }
};
// @lc code=end

