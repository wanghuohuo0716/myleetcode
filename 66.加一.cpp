/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] ĺ ä¸
 */

// 有三种情况需要处理：
// 末位无进位，则末位加一即可，因为末位无进位，前面也不可能产生进位，比如 45 => 46
// 末位有进位，在中间位置进位停止，则需要找到进位的典型标志，即为当前位 %10后为 0，则前一位加 1，直到不为 0 为止，比如 499 => 500
// 末位有进位，并且一直进位到最前方导致结果多出一位，对于这种情况，需要在第 2 种情况遍历结束的基础上，进行单独处理，比如 999 => 1000

// 所以只需要判断有没有进位并模拟出它的进位方式，如十位数加1，个位数置为0，如此循环直到判断没有再进位就退出循环返回结果。
// 然后还有一些特殊情况就是当出现9999、999999之类的数字时，循环到最后也需要进位，出现这种情况时需要手动将它进一位。


// 其实也可以把数组转换为数字，乘10,100,1000，然后再%10取余数，转换为数组，这样太复杂。

// 核心思想是判断在哪里进位，如何处理进位。


#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            if (digits[i] != 0) return digits;
        }
        vector<int> digits_(digits.size() + 1); //直接新建一个长度+1的数组，999进位为1000，无法在原数组上改
        digits_[0] = 1;
        return digits_;
    }
};
// @lc code=end

