/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <string>
using namespace std;
// 用数学的方法解决
// 前提知识：任何一个字符串都可以由s=nx表示，n>2，则s由某个子串重复表示，n=1，x=s
// 假设给定字符串s可由一个子串x重复n次构成，即s=nx。
// 现构造新字符串t=2s，即两个s相加，由于s=nx，则t=2nx。
// 去掉t的开头与结尾两位，则这两处的子串被破坏掉，此时t中包含2n-2个子串。

// 根据t中是否包含s可以判断n的大小，从而得知s是否由x重复n次！！！！

// 由于t中包含2n-2个子串，s中包含n个子串，若t中包含s，则有2n-2>=n，可得n>=2，由此我们可知字符串s可由一个子串x重复至少2次构成，即s=nx,n>2,则s由重复字符串组成；
// 若t中不包含s，则有2n-2<n，可得n<2，n只能为1，由此我们可知字符串s=x，假定的子串就为s本身，判定为false。

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str=s+s;
        str=str.substr(1,str.size()-2);
        if(str.find(s)==-1)
            return false;
        return true;
    }
};
// @lc code=end

