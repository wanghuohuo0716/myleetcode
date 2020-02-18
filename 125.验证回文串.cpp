/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include <string>
using namespace std;
// 双指针，从字符串前后进行比较，如果一直到i和j相同时，字符都是相同的，则是回文串
// 难点在于排除非数字和字母，以及字母的大小写干扰，用内置函数解决这个问题

// isalnum(char c):判断字符变量c是否为字母或数字，若是则返回非零，否则返回零。l:letter
// tolower(char c):把字母字符转换成小写,非字母字符不做出处理。

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        // 双指针
        if(s.size() <= 1) return true;
        int i = 0, j = s.size() - 1;
        while(i < j){
            while(i < j && !isalnum(s[i])) // 排除所有非字母或数字的字符
                i++;
            while(i < j && !isalnum(s[j]))
                j--;
            if(tolower(s[i++]) != tolower(s[j--])) //统一转换成小写字母再比较
                return false;
        }
        return true;
    }
};
// @lc code=end

