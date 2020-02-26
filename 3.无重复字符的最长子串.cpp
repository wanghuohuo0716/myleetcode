/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <string>
#include <vector>
#include <set>
using namespace std;
// 暴力法，两个for循环遍历，也是用桶对出现的字母计数
// 双指针滑动变长度窗口法，用桶来优化hash表，加快速度
// 前提：最终的长度至少要包含一个字符才是最长的长度，所以随便选一个即可，这里选的是首字母，最终的子串是一定包含首字母的字符
// 所以start可以选择为同一个字母不同的索引

// 输入的字符串是拓展的ASCII码，包括空格之类的，在插入字符

// 窗口左边界更新不是直接跳过子串，而是跳过重复字符，比如"abcabcbb",abca当遇到a重复时，下一个子串的是bcab，而不是abcb
// 下面这个链接讲解的比较清楚
// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/solution/wu-zhong-fu-zi-fu-de-zui-chang-zi-chuan-cshi-xian-/

// 计算两个重复字母之间的字符串长度，当出现重复字母时

// 像hash表插入字符这种，start的更新公式是错的，不应跳过子串更新！！
// if(dict.count(s[i]) != 0){
//     maxlen = max(maxlen, i - start);
//     start = i+1;
// }

// (不一定是第一个)

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1); // 作为桶，记录ASCII码在s中出现的索引，实际就是a-z这26个字母在s出现的索引
        int maxLen = 0, start = -1; // start记录滑动窗口的左边界即子串的起始索引
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start) // 子串中遇到了重复字母， 这个条件难以理解，其实暗含了s[i]这个字母第二次出现，即子串开始重复了。因为痛的默认值是-1,如果要比-1大，那之前必定更新过
                start = dict[s[i]]; // 更新子串左窗口位置
            dict[s[i]] = i; // 记录该字母出现在s中的位置为右窗口边界
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
};
// @lc code=end




