/*
 * @lc app=leetcode.cn id=873 lang=cpp
 *
 * [873] 最长的斐波那契子序列的长度
 */
#include <vector>
#include <unordered_set>
using namespace std;
// 暴力法求解
// 寻找公式f(n+2)=f(n)+f(n+1)中f(n+2)是否存在，维护一个记录历史最大长度的值，使用set数据结构来快速查找也可以用二分查找
// j更新的条件是以i，j为起始paior的找完了，才会更新j
// i更新的条件是以i为第一个元素的序列更新完了

// @lc code=start
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int N = A.size();
        unordered_set<int> S(A.begin(), A.end());

        int ans = 0;
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j) {
                /* With the starting pair (A[i], A[j]),
                 * y represents the future expected value in
                 * the fibonacci subsequence, and x represents
                 * the most current value found. */
                int x = A[j], y = A[i] + A[j];
                int length = 2;
                while (S.find(y) != S.end()) {
                    int z = x + y;
                    x = y;
                    y = z;
                    ans = max(ans, ++length);
                }
            }
        return ans >= 3 ? ans : 0;
    }
};
// @lc code=end

