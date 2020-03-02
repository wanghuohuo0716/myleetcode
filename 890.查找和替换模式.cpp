/*
 * @lc app=leetcode.cn id=890 lang=cpp
 *
 * [890] 查找和替换模式
 */
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;
// 难点在于如何比较相同字母的映射相同
// 使用hash表，以pattern中的字母为键，words单词为值，比较相同的键的值是否相同,以及相同的值键是否相同，这才保证一一对应
// 使用find函数，返回同一种字符的第一次出现的位置，比较位置是否相同，若相同则映射关系保持不变

// 一个思路是字母->字母，一个是字母的索引->字母的索引

// @lc code=start
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(int i=0;i<words.size();i++){
            if(check(words[i],pattern))
                res.push_back(words[i]);
        }
        return res;
    }
    bool check(string word,string pattern){
        if(word.length()!=pattern.length())
            return false;
        for(int i=0;i<pattern.length();i++){
            if(word.find(word[i])!=pattern.find(pattern[i])) // 第一次出现的的映射被保留下来，后面遇到相同的字符，find返回的是第一次出现字符的索引，则映射相同
                return false;
        }
    return true;
    }
};
// @lc code=end

