/*
 * @lc app=leetcode.cn id=848 lang=cpp
 *
 * [848] 字母移位
 */
#include <string>
#include <vector>
using namespace std;
// 后缀和！！！

// 不难分析出来，第一个字母总共要被变化shifts.size()次(不是移位次数)，第二个字母变化shifts.size()-1次...第S.size()-1个字母变化1次
// 可以把单次移位，看做一次性移位。每个字母每次变化的位数可以累加，统计每个字母累计移位的次数，一次移位完成
// 从后往前更新shifts[i]的次数， shifts[i] = (shifts[i] + shifts[i + 1]) % 26;

// @lc code=start
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
    for (int i = shifts.size() - 1; i >= 0; i--) {
        if (i != shifts.size() - 1)
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        S[i] = 'a' + (S[i] - 'a' + shifts[i]) % 26;
    }
    return S;
    }
};
// @lc code=end

