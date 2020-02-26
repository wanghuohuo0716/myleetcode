/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */
#include <string>
using namespace std;
// 双指针反转，遇到不是字母的字符跳过

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string S) {
		int left = 0;
		int right = S.size() - 1;
		while (left < right)
		{
			while (left < right && !isalpha(S[left])) // 找到左指针字母字符的索引
			{
				++left;
			}
			while (left < right && !isalpha(S[right])) // 找到右指针字母字符的索引
			{
				--right;
			}
			if (left < right) // 交换
			{
				swap(S[left], S[right]);
				++left;
				--right;
			}
		}
		return S;
    }
};
// @lc code=end

