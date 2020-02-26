/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <string>
#include <sstream>
using namespace std;
// C++引入了ostringstream、istringstream、stringstream这三个类，要使用他们创建对象就必须包含sstream.h头文件。
// 这些string的流可以帮助解决一些问题，如果需要后面可以了解下
// https://blog.csdn.net/JoeBlackzqq/article/details/7032703

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        while(*str.begin() == ' ') str.erase(str.begin());
        if(str == "") return 0;
        stringstream ss;
        ss<<str;
        int n;
        ss>>n;
        return n;
    }
};
// @lc code=end

