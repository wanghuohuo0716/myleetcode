/*
 * @lc app=leetcode.cn id=495 lang=cpp
 *
 * [495] 提莫攻击
 */
#include <vector>
#include <algorithm>
using namespace std;
// 我们只需要对数组进行一次扫描就可以计算出总的中毒持续时间，关键在于间隔的时间与2s之间的关系。

// 考虑相邻两个攻击时间点 A[i] 和 A[i + 1] 以及中毒持续时间 t，如果 A[i] + t <= A[i + 1]，那么在第 i + 1 次攻击时，第 i 次攻击造成的中毒的持续时间已经结束，即持续时间为 t；如果 A[i] + t > A[i + 1]，那么在第 i + 1 次攻击时，第 i 次攻击的中毒仍然在持续，由于中毒状态不可叠加，因此持续时间为 A[i + 1] - A[i]。
// 注意最后一次的持续时间肯定是2s
// @lc code=start
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        if (n == 0) return 0;

        int total = 0;
        for(int i = 0; i < n - 1; ++i)
          total += min(timeSeries[i + 1] - timeSeries[i], duration);
        return total + duration;
    }
};
// @lc code=end

