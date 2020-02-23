/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文字符串 Ⅱ
 */
#include <string>
using namespace std;
// 回文串验证的操作：通过首尾双指针向中间缩进，知道l=r时才满足
// 当某个字符不满足回文要求时，删除操作可以是跳过操作，l1=l+1，继续进行回文比较

// @lc code=start
class Solution {
public:
    bool validPalindrome(string s) {
        // 不需修改就是回文串
        int l = 0;
        int r = s.size() - 1;
        while (l < r && s[l] == s[r]) {
            ++l;
            --r;
        }
        if (l >= r) return true;

        if (l < r) {
            // 删除坐标字符后变成回文串
            int l1 = l + 1;
            int r1 = r;
            while (l1 < r1 && s[l1] == s[r1]) {
                ++l1;
                --r1;
            }
            if (l1 >= r1) return true;

            // 删除右边字符后变成回文串
            int l2 = l;
            int r2 = r - 1;
            while (l2 < r2 && s[l2] == s[r2]) {
                ++l2;
                --r2;
            }
            if (l2 >= r2) return true;
        }
        return false; // 删除字符后仍然不是回文串
    }
};
// @lc code=end

