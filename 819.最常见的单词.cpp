/*
 * @lc app=leetcode.cn id=819 lang=cpp
 *
 * [819] 最常见的单词
 */
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// 此题是充分的利用了各个数据类型自带的函数来大幅简化代码

// 步骤很清晰
// 1.提前单个单词，并转换成小写字母。单词的分割条件是前一个元素是字母，后一个元素不是字母，
// 2.判断单词是否在禁用表中
// 3.对单词出现的数目进行累加
// 4.统计各个单词出现的次数

// @lc code=start
class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet(banned.begin(), banned.end()); // 放入hash表中，便于查找单词是否在禁忌表中
        unordered_map<string, int> cnt;
        int temp = 0;
        string res;
        cnt.reserve(paragraph.size());
        string word;
        for (size_t i = 0; i < paragraph.size(); i++) {
            auto& c = paragraph[i];
            if (isalpha(c)) {
                word.push_back(tolower(c));
                if (i == paragraph.size() - 1 || !isalpha(paragraph[i + 1])) {
                    if (!bannedSet.count(word)) {
                        cnt[word]++;
                    }
                    word.clear();
                }
            }
        }
        for (auto c:cnt){ // hash表元素遍历无法像数组那样直接索引，但是可以使用auto的迭代器进行遍历
            if(c.second > temp){
                temp = c.second;
                res = c.first;
            }
        }
        return res;
    }
};
// @lc code=end

