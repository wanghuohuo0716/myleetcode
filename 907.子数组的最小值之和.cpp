/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */
#include <vector>
#include <stack>
using namespace std;
// 此题的难点是如何找建立最小值栈，和计算最小值的次数，这道题不理解
// 维护一个最小值栈，栈中存这些值的索引，按照递增的顺序储存
// 然后记录每个最小值的次数，两者之积最后累加求和就是结果
// @lc code=start
class Solution {
public:
    const long M = 1e9 + 7;
    int sumSubarrayMins(vector<int>& A) {
        int N = A.size();
        stack<int> st;
        vector<long> sums(N, 0);
        for (int i = 0; i < N; ++i) {
            while (!st.empty() && A[st.top()] >= A[i]) {
                st.pop();
            }
            if (st.empty()) {
                sums[i] = A[i] * (i + 1);
            } else {
                sums[i] = sums[st.top()] + A[i] * (i - st.top());
            }
            sums[i] %= M;
            st.push(i);
        }
        long res = 0;
        for (auto x : sums) {
            res += x;
            res %= M;
        }
        return res;
    }
};
// @lc code=end

