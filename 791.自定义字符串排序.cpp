/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */
#include <string>
#include <unordered_map>
using namespace std;
// 1.先统计T中每个字符的数目
// 2.按照S中的字母顺序，把T中的字母输出，同时删除该字母（把S中的字母当做索引来得到该字母在T中出现的次数）
// 3.把剩余的字母插到尾部

// tip:使用append函数可以一次插入多个相同的字符，2.使用erase函数去掉map中的数据

// @lc code=start
class Solution {
public:
    string customSortString(string S, string T) {
        unordered_map<char, int> m;
        string res;
        for (auto s:T)
            m[s]++;
        for (auto s:S){
            res.append(m[s], s);
            m.erase(s);
        }
        for (auto t:m)
            res.append(t.second, t.first);
        return res;

    }
};
// @lc code=end

