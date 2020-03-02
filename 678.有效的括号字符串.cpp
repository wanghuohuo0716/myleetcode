/*
 * @lc app=leetcode.cn id=678 lang=cpp
 *
 * [678] 有效的括号字符串
 */
#include <string>
using namespace std;
// 其实还是不太明白为什么左括号数目不能小于0

// 类似第20题，维护括号的数目，但是引入了*可以变成左右括号，那么就维护左括号的取值范围[L,R]
// 如果遇到左括号，L++，R++；如果遇到右括号，L--,R--；如果遇到*，L--(把*看为右括号)，R++(把*看做左括号)，其实R也会减1，但因为是取值范围，R++包含了R--

// 还有个隐藏的前提，左括号一定要在右括号左边，不能出现")("，则左括号的最大数目一定不能为负数
// 即左括号的最小数目不能小于0(小于0)，但是最大数目可以小于0

// @lc code=start
class Solution {
public:
    bool checkValidString(string s) {
        int L = 0, R = 0; // 维护当前左括号的数量范围：[L, R]
        for (char ch : s) {
            if (ch == '(') {
                ++L;
                ++R;
            }
            else if (ch == ')') {
                if (L > 0) // 在边界拓展的过程中，左括号最小数目不能小于0，但是最大数目可以小于0，意味着右括号比左括号多了，出错
                    --L;
                if (R > 0)
                    --R;
                else // 左括号最大数目为负数，括号格式出错
                    return false;
            }
            else if (ch == '*') {
                ++R;
                if (L > 0)
                    --L;
            }
        }
        return L == 0; // 最后要能取到0
    }
};
// @lc code=end

