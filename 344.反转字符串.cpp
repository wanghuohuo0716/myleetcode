/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include <string>
#include <vector>
using namespace std;
// 双指针，交换头尾两个指针所指的两个位置的值，指针向中间移动一个位置，重复以上操作，直到两个指针交错；
// half是交换的次数，end是末尾的指针，i是头指针

// @lc code=start
class Solution {
public:
    void reverseString(vector<char>& s) {
        int end = s.size();
        const int half = end/2;
        end = end- 1;
        for (int i = 0 ; i < half && end >= 0; ++i, --end) {
            s[i] = s[i] ^ s[end];
            s[end] = s[end] ^ s[i];
            s[i] = s[i]^s[end];
        }
    }
};
// @lc code=end

