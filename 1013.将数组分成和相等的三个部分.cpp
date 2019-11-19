/*
 * @lc app=leetcode.cn id=1013 lang=cpp
 *
 * [1013] 将数组分成和相等的三个部分
 */
#include <vector>
using namespace std;
// 首选算A的累加和能否被3整除，不可以那分不了3等分。
// 从头累加数组的值，判断是否是累加和的1/3，如果是，则记录case出现次数，重新再计算。
// 当累计次数等于3时则说明可以等分

// 避免同时寻找累加和为1/3的数组序列，有先后顺序的寻找，符合计算机程序思维。
// @lc code=start
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = 0;
        for (int i : A) { // 这也是C++的写法
            sum += i;
        }

        if (sum % 3 != 0) {
            return false;
        }
        int subSum = sum / 3;
        int tempSum = 0;
        int okCount = 0;

        for (int i : A) {
            tempSum += i;
            if (tempSum == subSum) {
                okCount++;
                tempSum = 0;
            }
        }
        return okCount == 3;
    }
};
// @lc code=end

