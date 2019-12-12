/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] 爱生气的书店老板
 */
#include <vector>
#include <algorithm>
using namespace std;
// 此题用固定长度滑动窗口法
// 窗口体现在W是连续X个数据的累加值，当元素数目小于X时，累加，当元素数目大于X时，则减去第一个元素值，从而完成窗口滑动
// 先把店主不生气时，满意的人数累加起来，然后用W维护持续X分钟内生气人数的窗口，选择最大的W即可，然后加上之前不生气的人

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        const int N = grumpy.size();
        int W = 0;
        int ans = 0;
        int max_W = 0;

        for(int i = 0;i<N;++i){
            if(!grumpy[i])
                ans += customers[i];
            else
                W += customers[i];

            if(i >= X) // 超出滑动窗口范围，则移动窗口
                W -= grumpy[i-X] ? customers[i-X] : 0;
            max_W = max(max_W,W);
        }
        return ans + max_W;
    }
};
// @lc code=end

