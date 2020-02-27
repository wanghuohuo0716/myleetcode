/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
// 字母异位词的字母都相同，因此，所有单词按字母顺序排列结果相同的都是字母异位词
// 可以将单词字母排序后的结果作为索引，原始单词作为值，每个索引对应的值就是同一类字母异位词
// 考虑上述需求，必须使用map数据结构才能满足要求

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string> > ma; // 第一个变量是索引，第二个是值
        vector<vector<string>> res;
        for(auto str:strs){
            string tmp = str;
            sort(tmp.begin(),tmp.end()); // 单词按字母顺序排序
            ma[tmp].push_back(str); // 单词的字母顺序作为索引，单词作为值
        }
        for(const auto& m:ma) // 遍历所有的索引即string变量的数目，这里m的累积数目其实是string的数目，所以map中变量的数目有多少个就是这么来的！！！
            res.push_back(m.second);
        return res;
    }
};
// @lc code=end

