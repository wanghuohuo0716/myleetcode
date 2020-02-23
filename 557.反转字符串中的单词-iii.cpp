/*
 * @lc app=leetcode.cn id=557 lang=cpp
 *
 * [557] 反转字符串中的单词 III
 */
#include <string>
#include <algorithm>
using namespace std;
// 通过双指针记录单词的首尾位置，然后使用reverse函数进行字符串反转
// 通过检测空格来判断是否为单词的分界线

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        auto begin = s.begin() , back = begin ;
        for ( ; back < s.end() ; ++back )
        {
            if ( *back == ' ' )
            {
                reverse( begin , back ) ;
                begin = back + 1 ;
            }
        }
        reverse( begin , back ) ;
        return s ;
    }
};
// @lc code=end

