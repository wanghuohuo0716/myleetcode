/*
 * @lc app=leetcode.cn id=1208 lang=cpp
 *
 * [1208] 尽可能使字符串相等
 */
#include <string>
#include <algorithm>
using namespace std;
// 变长度窗口滑动法
// 窗口左边界更新的条件:窗口右边界向右滑动时窗口内字符串的差值超过了预算
// 窗口右边界更新的条件：只要窗口内字符串的差值不超预算就更新右边界
// 题意要求的是连续子字符串的最大长度，所以还需要维护一个窗口的最大长度变量

// @lc code=start
class Solution{
public:
    int equalSubstring(string s, string t, int maxCost){
        int left = 0, right = 0, result = 0, cost = 0, n = s.size();

        while (right < n){ //固定窗口的边界
            cost += abs(s[right] - t[right]);

            while (cost > maxCost){ //窗口溢出，需要缩小窗口
                cost -= abs(s[left] - t[left]);
                left++;
            }
            //窗内中cost小于等于maxCost时，我们需要记录最长的子字符串
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};
// @lc code=end
