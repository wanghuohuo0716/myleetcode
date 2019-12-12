/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */
#include <vector>
#include <algorithm>
using namespace std;
// 本质：把区间操作转换为端点操作，降低复杂度
// 暴力法很容易想到，外层循环遍历每条预定记录，内层循环记录每条的预定的航班位置数目即可
// 暴力法时间复杂度是O(N*K)，采用线性扫描法的时间复杂度为O(N)
// 线性扫描的核心在于记录的不是预定位置之和，而是记录预定位置的变化
// 讲道理，线性扫描对于这道题有点突兀，换成高赞回到的公交站可能好理解。
// 但也揭示了这个问题的本质，本质是把区间操作转换为端点操作，降低复杂度，这类问题都可以用线性扫描的方法解决，虽然没有物理意义，但是结果是对的
// https://leetcode-cn.com/problems/corporate-flight-bookings/solution/qian-zhui-he-fa-python-java-shi-jian-fu-za-du-on-b/

// @lc code=start
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> counters(n); // 记录每个航班的预定位置，类似一个桶操作，i代表航班编号
        for (vector<int> booking : bookings) {
            counters[booking[0] - 1] += booking[2];
            if (booking[1] != n) { // 排除booking[1]==n的情况
                counters[booking[1]] -= booking[2];
            }
        }
        for (int i = 1; i < n; ++i) {
            counters[i] += counters[i - 1];
        }
        return counters;
    }
};
// @lc code=end

vector<int> ans(n);
int len = bookings.size();
for(int i = 0; i < len; i++){
    int len2 = bookings[i][1];
    int value = bookings[i][2];
    for(int j = bookings[i][0] - 1; j < len2; j++){
        ans[j] += value;
    }
}
return ans;