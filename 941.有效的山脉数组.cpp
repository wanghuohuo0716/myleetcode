/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */
#include <vector>
using namespace std;
// 我们从数组的最左侧开始扫描，直到找到第一个不满足 A[i] < A[i + 1] 的 i，那么 i 就是这个数组的最高点。
// 如果 i = 0 或者不存在这样的 i（即整个数组都是单调递增的），那么就返回 false。
// 否则从 i 开始继续扫描，判断接下来的的位置 j 是否都满足 A[j] > A[j + 1]，若都满足就返回 true，否则返回 false。

// @lc code=start
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        int N = A.size();
        int i = 0;

        // walk up
        while (i+1 < N && A[i] < A[i+1])
            i++;

        // peak can't be first or last
        if (i == 0 || i == N-1)
            return false;

        // walk down
        while (i+1 < N && A[i] > A[i+1])
            i++;

        return i == N-1;
    }
};
// @lc code=end

