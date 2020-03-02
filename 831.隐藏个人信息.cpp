/*
 * @lc app=leetcode.cn id=831 lang=cpp
 *
 * [831] 隐藏个人信息
 */
#include <string>
#include <regex>
using namespace std;
// 惊！C++的STL库中有正则表达式的库regex
// for_each是对顺序储存的每个元素都应用函数，使得每个字母都变成小写字母
// 使用正则表达式进行匹配，然后去寻找符合要求的字符串，把匹配的结果的子串拼接起来就是结果了

// 对字母的处理是使用正则表达式的括号提取出三个部分，最后组合在一起
// 对数字的处理是去掉其它字符(使用isdigit函数)，只保留数字，根据数字的长度进行拼接

// @lc code=start
class ToLower {
public:
    void operator()(char &ch)
    {
        ch = tolower(ch);
    }
};

class Solution {
public:
    string maskPII(string S) {
        for_each(S.begin(), S.end(), ToLower());
        // 括号的作用是在后面match时，返回匹配的值
        // \w用于匹配字母，数字或下划线字符；+表示前面的字符出现一次或多次，\.是转义了，后面的正确读法是@ \w+ \. \w+，四个部分
        regex maixRule(R"(([a-z])[a-z]*([a-z])(@\w+\.\w+))"); // s首字母+中间字母重复*次+末尾字母@+word+.+word

        string rst;
        smatch m;
        bool fund = regex_match(S, m, maixRule);
        if (fund) {
            if (S.size() < 8) {
                return rst;
            }
            rst += m[1].str(); // 首字母
            rst += "*****";
            rst += m[2].str(); // 末尾字母
            rst += m[3].str(); // @之后的字母
            return rst;
        }

        // 下面处理Phone
        string phone;
        for (const auto &ch : S) {
            if (isdigit(ch)) {
                phone.push_back(ch);
            }
        }

        if (phone.size() < 10 || phone.size() > 13) {
            return rst;
        }
        if (phone.size() == 10) {
            rst += "***-***-";
        }
        else {
            string tmp(phone.size() - 10, '*'); // 取号可能有2个或者3个
            rst = "+" + tmp + "-***-***-";
        }
        rst += phone.substr(phone.length() - 4);
        return rst;
    }
};
// @lc code=end

