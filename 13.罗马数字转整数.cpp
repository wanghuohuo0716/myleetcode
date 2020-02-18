/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <string>
#include <unordered_map>
using namespace std;
// 难点在于判断数字是由一个罗马字符组成还是两个罗马字符组成，判断的条件是 左边罗马数字比右边大，则是两个字符组合成的数
// 处理的方法也各有千秋，可以两个一起作为整体最后相加，也可以把小的作为负数，大的作为正数，最后分别累加即可。后一种代码上较简洁

// 提取字符，直接对string类型的变量进行索引，直接索引就可以得到对应位置的字符
// 字符一一映射到的相应数字，实现的方法，1.构造hash表，字符作为键，数字作为值 2.构造数组，把字符作为ASCII码，减去A的值作为索引，索引的值为对应数值

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int pos = 0, neg = 0;
        for (int i = 0;i < s.size()-1;++i){
            if (mp[s[i]] < mp[s[i+1]])
                neg -= mp[s[i]];
            else
                pos += mp[s[i]];
        }
        pos += mp[s.back()];

        return pos + neg;
    }
};
// @lc code=end

