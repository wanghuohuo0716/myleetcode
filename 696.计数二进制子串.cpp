/*
 * @lc app=leetcode.cn id=696 lang=cpp
 *
 * [696] 计数二进制子串
 */
#include <string>
using namespace std;
// 核心难点在于子串如何计算，只有两种字符，0和1，要求子串的0的数量与1的数量相同，短板效应，选择较小的那个字符的数量才能使得子串的0和1的数目相同，因为要求子串是连续的，所以必须是相邻的两个子串进行组合
// 先统计连续的0和1分别有多少个，如：111100011000，得到4323；在4323中的任意相邻两个数字，取小的一个加起来，就是3+2+2 = 7.

// @lc code=start
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int res = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                ++curr;
            }
            else {
                res += min(prev, curr);
                prev = curr;
                curr = 1;
            }
        }
        res += min(prev, curr);
        return res;
    }
};
// @lc code=end

