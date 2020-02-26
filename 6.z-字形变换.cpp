/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 设置n个行string来分别储存每行的结果，按照Z形变换索引的规则，每行储存从s从提出来的字符，最后把n行的字符串再相加就是结果了
// 核心是如何从s按照Z变换规则把字符放到n行中
// 核心：按顺序遍历s时，每个字符c在Z变换中的行索引先从1增大到n，再从n减小到1，...，如此反复

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows < 2) return s;
        vector<string> rows(numRows);
        int i = 0, flag = -1;
        for(char c : s) {
            rows[i].push_back(c);
            if(i == 0 || i == numRows -1) flag = - flag;
            i += flag;
        }
        string res;
        for(auto row : rows) res.append(row);
        return res;
    }
};
// @lc code=end

