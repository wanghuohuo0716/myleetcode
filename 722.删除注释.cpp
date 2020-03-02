/*
 * @lc app=leetcode.cn id=722 lang=cpp
 *
 * [722] 删除注释
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
// 感觉不会面试这种题，用python的正则表达式似乎会简单许多

// @lc code=start
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string cur, status = "str";
        vector<string> res;
        for (string s : source) {
            for (char ch : s) {
                if (status == "str") {
                    if (ch == '/') {
                        status = "pre";
                    }
                    else cur += ch;
                }
                else if (status == "pre") {
                    if (ch == '/') {
                        status = "str";
                        break;
                    }
                    else if (ch == '*') {
                        status = "block";
                    }
                    else {
                        status = "str";
                        cur += '/';
                        cur += ch;
                    }
                }
                else if (status == "block") {
                    if (ch == '*') status = "block_end_pre";
                }
                else if (status == "block_end_pre") {
                    if (ch == '/') status = "str";
                    else if (ch != '*') status = "block";
                }
            }
            if (status == "pre") {
                cur += '/';
                status = "str";
            }
            else if (status == "block_end_pre") status = "block";
            //cout << status << endl;
            if (cur.size() != 0 && status == "str") {
                res.push_back(cur);
                cur = "";
            }
        }
        return res;
    }
};
// @lc code=end

