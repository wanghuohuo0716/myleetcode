/*
 * @lc app=leetcode.cn id=1040 lang=cpp
 *
 * [1040] 移动石子直到连续 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// 难点在于对题意的理解，考验语文能力
// 求最小值时需要构建滑动窗口，滑动窗口的长度可以分为固定长度和变长度，其中变长度需要维护两个循环变量i，j来记录窗口的起止位置！
// 把石头放到一起，在坐标上是连续的，题目给的数组没排序，得先排序
// 由于限制了端点石子移动后不能再是端点石子，所以在第一次移动A[0]的时候，必然会越过A[0]与A[1]之间的空隙，
// 在第二次移动时，假设第一次A[0]移动到A[1]+1处，A[1]就可以移动到A[1]+2处，从而可以交替往里移动石子，每次移动一位
// 注意：在第一次移动的时候，那个A[0]与A[1]之间的空隙是必然要舍弃的，否则违反规则
// 求最大值，就要选第一次移动时两端空隙小的那个，首先计算石子可以放置的空间，等于左右两端石子之间的未占用位置s1=stones[n−1]−stones[0]+1−n，s2=min(stones[n−1]−stones[n−2]−1,stones[1]−stones[0]−1)
// 求最小值就是以某个石子为中心的n个刻度中石子数目最多为m，那么需要移动n-m次即可。
// 有一种特例，比如1，2，3，4，7，得移动2次才行，1 先移动到 6，然后 7 移动到 5 。这种case的特征是滑动窗口的中间石子都是连续的，边缘有空位，即有n-1个石子

// @lc code=start
class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        int mx = stones[n - 1] - stones[0] + 1 - n;
        mx -= min(stones[n-1]-stones[n-2] - 1, stones[1]-stones[0] -1);
        int mi = mx;
        int i = 0;
        int j = 0;
        for(i = 0; i < n; ++i) // 构建以i为起点的变长度滑动窗口
        {
            while(j + 1 < n && stones[j + 1] - stones[i] + 1 <= n) // 窗口的末尾
                ++j;
            int cost = n - (j - i + 1);
            if(j - i + 1 == n - 1 && stones[j] - stones[i] + 1 == n - 1) // 石子的个数与坐标的长度都为n-1，这样的条件一定是未占位置在边缘，不可能在中间，否则坐标的长度就为n
                cost = 2;
            mi = min(mi, cost);
        }
        return vector<int>{mi, mx};
    }
};
// @lc code=end

