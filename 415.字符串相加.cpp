/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */
#include <string>
using namespace std;
// 思想是把数字中每一位的单个字符转换成数字，然后相加，记录进位，把相加的结果作为字符一个一个插入结果中
// 难点在三个地方
// 1.位数不同怎么办：从尾部个位相加，如果位数不同，则小的数前面补0
// 2.进位如何处理：设置个变量carry单独记录是否有进位
// 3.如何构造相加后的结果：使用insert方法，在首位插入字符

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        string ret;
        int carry = 0; // 两个数相加产生的进位
        for(int i = num1.size() - 1, j = num2.size() - 1; i >= 0 || j >= 0; i--, j--)
        {
            int sum = carry;
            sum += (i >= 0) ? num1[i] - '0' : 0; //从尾部个位相加，如果位数不同，则小的数前面补0
            sum += (j >= 0) ? num2[j] - '0' : 0;
            ret.insert(ret.begin(), '0' + sum % 10); // sum % 10是相加后可能有进位，保留个位数
            carry = sum / 10; // 计算是否有进位
        }
        if(carry == 1)
            ret.insert(ret.begin(), '1');

        return ret;
    }
};
// @lc code=end

