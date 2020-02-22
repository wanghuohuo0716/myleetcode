/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */
#include <string>
using namespace std;
// 核心思想与383类似，都是计算字母出现的次数，这种情况用桶排序最为合适
// 使用包含26个元素的数组构成字母桶，统计每个字母出现的次数

// @lc code=start
class Solution {
public:
    int firstUniqChar(string s) {
        int v[26] = {0};
        if(s.empty())
            return -1;
        for(int i = 0; i< s.length(); ++i) //0-25代表字母 见到一个字母就+1
        {
            v[s[i]-'a']++;
        }

        for(int i =0; i <s.length();++i) //遍历原字符串，找到词频只有一次的就直接返回i
        {
            if(v[s[i]-'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

