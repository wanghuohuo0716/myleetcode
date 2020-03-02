/*
 * @lc app=leetcode.cn id=966 lang=cpp
 *
 * [966] 元音拼写检查器
 */
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;
// 解决问题的思路比较清晰，执行的步骤也很明确，难点在于如何实现上
// 有一个核心需求是如何便捷储存，wordlist中的单词和小写后的单词和去掉元音后的单词，哪个是键，哪个是值
// 确定哪个是键：选择键的原则是，把待查询的单词作为键，查询的结果作为值，比如小写单词作为键和元音替换成*后的单词作为键

// 对于处理元音字母，使用的技巧很赞，题目要求是所有元音字母可以随意替换，那都替换成一样的进行比较就行！

// @lc code=start
class Solution {
public:
    void trans(string& s) {
        for (auto& c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> hash1(wordlist.begin(), wordlist.end()); // 用于查询wordlist中是否有这个单词
        unordered_map<string, string> hash2;
        unordered_map<string, string> hash3;
        vector<string> res(queries.size());
        string str = "";
        for (auto s : wordlist) {
            str = s;
            transform(str.begin(), str.end(), str.begin(), ::tolower); // 把wordlist中的一个单词都变成小写，存到str中
            if (hash2.find(str) == hash2.end()) // 把小写单词作为键，wordlist对应的单词作为值
                hash2[str] = s;
            trans(str); // 把wordlist单词中的元音字母统一替换成*
            if (hash3.find(str) == hash3.end()) // 把元音替换成*的小写单词作为键，wordlist对应的单词作为值
                hash3[str] = s;
        }
        for (int i = 0; i < queries.size(); ++i) {
            if (hash1.count(queries[i])) { // 单词拼写正确则直接插入到结果res中
                res[i] = queries[i];
                continue;
            }
            str = queries[i];
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            if (hash2.count(str)) // 先进行小写检测，再进行元音检测
                res[i] = hash2[str];
            else {
                trans(str);
                if (hash3.count(str))
                    res[i] = hash3[str];
            }
        }
        return res;
    }
};
// @lc code=end

