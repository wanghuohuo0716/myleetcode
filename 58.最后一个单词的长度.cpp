/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */
#include <string>
using namespace std;
// 这道题的难点在于如何确定最后一个单词逻辑
// 最后一个单词的特点是单词前面和后面都可能有空格，例如“hello”与“hello ”是不同的
// 要从字符串末尾向前遍历，有两种情况
// 1.从后向前遍历直到遇到头或者遇到空格为止，即为end
// 2.先将末尾的空格滤掉，然后从后到前遍历，直到遇到空格或者头，即为单词的start


// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
    if(s.empty() || s == "")
        return 0;
    int len = s.size();
    int i, j;
    for(i = len - 1; i >= 0 && s[i] ==' '; i--); // 找到end
    for(j = i; j >= 0 && s[j] != ' '; j--); // 找到start
    return i - j;
    }
};
// @lc code=end

