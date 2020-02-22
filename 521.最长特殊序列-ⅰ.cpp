/*
 * @lc app=leetcode.cn id=521 lang=cpp
 *
 * [521] 最长特殊序列 Ⅰ
 */
#include <string>
using namespace std;
// 此题关键在于理解题意，1.字符串独有的最长子序列，2.任何字符串为其自身的子序列，所以可以直接比较两个字符串长度
// 长度长的为结果，长度相同，字符串相同，返回-1，长度相同字符串不同，返回字符串长度

// @lc code=start
class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size() != b.size())
            return max(a.size(),b.size());
        if(a == b)
            return -1;
        return a.size();
    }
};
// @lc code=end

