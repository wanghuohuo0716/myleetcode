/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
#include <string>
#include <vector>
using namespace std;
// 题目分析关键词：所有可能的...即为全排列类型，需要使用回溯法来探索
// 难点
// 要注意提取的长度不能超过子串的长度
// 探索的ip如何用完所有的数字而不是用数字的一部分，比如25525511135不能是2.5.5.2，解决办法，不在过程中处理，在结果中判断下s是否为空即可
// 如何在ip段后面插入分隔符.，当弄好一个段之后，在段后面添加一个.再往递归函数中传递

// @lc code=start
class Solution {
private:
    vector<string> res;
public:
    vector<string> restoreIpAddresses(string s) {
        string ip;
        helper(s, 0, ip);
        return res;
    }
    void helper(string s, int n, string ip) { // s:剩余待处理的字符串，n：当前已经处理了n段(一共四段)，当前形成的ip地址
        if (n == 4) {
            if (s.empty()) // 必须全部利用完了所有的数才是正确的ip
                res.push_back(ip);
        }
        else {
            for (int k = 1; k < 4; ++k) { // 对
                if (s.size() < k) break; // s剩余部分的字符串长度不够设计k长度的ip，比如s=‘22’，而k=3，要求是3位长度的ip，而s显然位数不够，所以退出循环
                int val = stoi(s.substr(0, k));
                if (val > 255 || k != to_string(val).size()) continue; //剪枝，后面的条件是避免出现为会出现001这种ip段
                helper(s.substr(k), n + 1, ip + s.substr(0, k) + (n == 3 ? "" : ".")); // s.substr(k)是提取s中k位置到最后子串，同时把新的段后面直接加上.,避免了if操作
            }
        }
        return;
    }
};
// @lc code=end

