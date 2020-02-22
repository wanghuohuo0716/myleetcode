/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */
#include <string>
#include <algorithm>
using namespace std;
// 实际有三种case 剩余的字符长度 1.小于k 2.小于2k，大于k 3.大于2k
// 当大于2k时再从1和2中选择，所以最后终结的条件肯定是1和2
// 区别也就是翻转k个和不足k时，翻转结尾

// @lc code=start
class Solution {
public:
    string reverseStr(string s, int k) {
	for (string::iterator it = s.begin(); it < s.end(); it += 2 * k)
		if (it + k < s.end())
            reverse(it, it + k);
		else
            reverse(it, s.end());
	return s;
    }
};
// @lc code=end

