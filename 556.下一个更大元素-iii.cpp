/*
 * @lc app=leetcode.cn id=556 lang=cpp
 *
 * [556] 下一个更大元素 III
 */
#include <string>
#include <algorithm>
using namespace std;
// 这道题是一个系列，用画山峰图的方法来分析最清楚，分为两步：交换字符i和改变升降序i+1！

// 分析从最后一个字符s[end]到第一个字符s[0]，从后到前，数字是降序还是升序，降序才找到交换的i。理解升降序的概念对下一个更大元素是核心
// 把从i到末尾的字符从升序变成降序（这个升序和降序也是从末尾往前比较字符得到的升降序）
// 找到刚刚好出现降序的位置，就找到了交换字符的位置！！

// tip：使用string转换方便提取整数的每一位数字
// STL中有现成的函数next_permutation()
// string s=to_string(n);
// next_permutation(s.begin(),s.end())

// @lc code=start
class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int i = s.size() - 2;
        while(i >= 0 && s[i] >= s[i+1]) // 找到s[i]<s[i+1]的i，从后往前遍历是从低位往高位找
            --i;
        if(i < 0)
            return -1;
        int j = s.size() - 1;
        while(j >= 0 && s[j] <= s[i]) // 在s[i..end]中即数字从低到高位，找到比s[i]大的一个数
            --j;
        swap(s[i],s[j]);
        reverse(s.begin()+i+1,s.end()); // 因为前面找i时，知道了从s[i...end]的每一位是从大到小排列的，因此翻转得到其最小序列
        long long r = stoll(s);
        if(r > INT_MAX)
            return -1;
        return r;
    }
};
// @lc code=end

