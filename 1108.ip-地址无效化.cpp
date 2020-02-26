/*
 * @lc app=leetcode.cn id=1108 lang=cpp
 *
 * [1108] IP 地址无效化
 */
#include <string>
using namespace std;
// 先找到字符.的位置，然后在前后插入[]，需要注意的是，插入字符时，会改变原来字符的索引和整个字符串的长度，在循环计算时，要把循环的长度和索引变量的变化长度都加上

// @lc code=start
class Solution {
public:
    string defangIPaddr(string address) {
        int len = address.size();//直接计算出IP地址的长度
        for (int i = 0; i < len; i++)//遍历每一个字符
        {
            if (address[i] == '.')//如果当前字符为'.'
            {
                address.insert(i, "[");//在它的前面添加'['字符
                address.insert(i + 2, "]");//在它的后面添加']'字符
                i = i + 2;//由于添加了2个字符,因此当前位置应该加上2
                len = len + 2;//字符串长度也要加上2
            }
        }
        return address;//返回处理好的IP地址
    }
};
// @lc code=end

