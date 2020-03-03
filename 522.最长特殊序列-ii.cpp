/*
 * @lc app=leetcode.cn id=522 lang=cpp
 *
 * [522] 最长特殊序列 II
 */
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;
// 难点在于查找子串
//1，字符串从长到短逐渐考察是否满足条件
//2，只要当前字符串没有与之相同的其他字符串，且也不是任何比它长的字符串的子序列，则满足条件

// tip:用set保存子串，快速进行查找和去重

// @lc code=start
class Solution {
public:
    bool valid(unordered_set<string>& v, vector<string>& q) {
        sort(q.begin(), q.end());
        int i = 0;
        for (int j = 0; j < q.size(); ++j) {
            if (j > 0 && q[j] == q[j - 1]) // 子串相同
                continue;
            if (j < q.size() - 1 && q[j] == q[j + 1]) // 子串相同
                continue;
            if (v.empty())
                return true;
            auto& x = q[j]; // 子串
            for (auto& y : v) { // set中的子串和vector中的子串进行比较是否有相同的
                int i = 0;
                int j = 0;
                while (i < x.size() && j < y.size()) {
                    if (x[i] == y[j]) {
                        ++i;
                        ++j;
                    }
                    else
                        ++j;
                }
                if (i != x.size()) // 子串不完全相同
                    return true;
            }
        }
        return false;
    }
    int findLUSlength(vector<string>& strs) {
        map<int, vector<string> > m;
        for (auto& w : strs)
            m[w.size()].push_back(w); // 字符串的长度为键，单词为值
        unordered_set<string> v;
        for (auto it = m.rbegin(); it != m.rend(); ++it) { // 对每个子串计算其最长的子串
            if (valid(v, it->second)) // v是字符串集合，后者是字符串子列表
                return it->first; // 子串长度
            v.insert(it->second.begin(), it->second.end()); // 字符串插入set中
        }
        return -1;
    }
};
// @lc code=end
