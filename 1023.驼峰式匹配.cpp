/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */
#include <string>
#include <vector>
#include <regex>
using namespace std;
// 看到匹配就容易想到正则表达式进行匹配，把pattern中的每个字符都单独进行匹配
// 先拼接匹配的字符，再对queries中的每个单词进行匹配

// @lc code=start
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        if (pattern.empty())
            return{};
        string regPat;
        for (int i = 0; i < pattern.length(); i++) {
            regPat += "[a-z]*";
            regPat.push_back(pattern[i]);
        }
        regPat += "[a-z]*";
        regex reg(regPat);
        vector<bool> ans(queries.size(), false);
        for (int i = 0; i < queries.size(); i++) {
            if (regex_match(queries[i], reg))
                ans[i] = true;
        }
        return ans;
    }
};
// @lc code=end

