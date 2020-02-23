/*
 * @lc app=leetcode.cn id=686 lang=cpp
 *
 * [686] 重复叠加字符串匹配
 */
#include <string>
using namespace std;
// 关键是发现一个条件，重复多次A后形成的新字符串长度要比B长，刚好超过B，或者刚好超过B后再加一个A即可在新字符串中找到B
// 换句话说，A重复的次数是固定的，根据B的长度确定！！！

// @lc code=start
class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        if (A.empty()) {
            return -1;
        }
        string T = A;
        int i = 1;
        while (T.size() < B.size()) {
            T.append(A);
            ++i;
        }
        if (T.find(B) != string::npos) {
            return i;
        }
        T.append(A);
        ++i;
        if (T.find(B) != string::npos) {
            return i;
        }
        return -1;
    }
};
// @lc code=end

