/*
 * @lc app=leetcode.cn id=345 lang=cpp
 *
 * [345] 反转字符串中的元音字母
 */
#include <string>
using namespace std;
// 反转元音字母是，交换字符串中首尾对应的元音字母，所以要用双指针法寻找元音字母
// 交换的条件是双指针没有交错的条件下，两个指针找到的元素均为元音字母

// 下面这种首尾向中间查找的框架可以关注下

// @lc code=start
class Solution {
public:
    bool find(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
        ||c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            while(!find(s[i])&&i<j)
                i++;
            while(!find(s[j])&&i<j)
                j--;
            swap(s[i++],s[j--]);
        }
        return s;
    }
};
// @lc code=end

