/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */
#include <vector>
using namespace std;
// 通常，涉及连续子数组问题的时候，我们使用前缀和来解决它们
// 前缀和：令 P[i+1] = A[0] + A[1] + ... + A[i]。那么，每个连续子数组就可以写成 P[j] - P[i]
// 若P[i] 与 P[j] 除以K后余数相同，则会有(P[j] - P[i]) % K = 0 因为余数相等就减掉了
// 假设P[a], P[b], P[c](a<b<c)除以K后余数相同，则从3种排列中选择2中进行组合就是C_3^2=3种可能
// 除以K后余数可能是1,2,3等，只要余数相同即可，把这些同余的求组合排列，最后累加就是结果，因为固定选择2个组合，因此是c*(c-1)/2种可能

// @lc code=start
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int N = A.size();
        vector<int> P(N+1);
        for (int i = 0; i < N; ++i)
            P[i+1] = P[i] + A[i];

        vector<int> count(K); // 余数从-K+1到K-1，记录每个余数出现的次数，因为是连续的，所以可以用数组，不用Hash表
        for (int x: P)
            count[(x % K + K) % K]++;

        int ans = 0;
        for (int v: count)
            ans += v * (v - 1) / 2; // 组合计算
        return ans;
    }
};
// @lc code=end

