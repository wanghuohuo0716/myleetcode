/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 */
#include <string>
#include <vector>
#include <sstream>
using namespace std;
// 主要是利用sstream来实现自动对字符串进行分割
// 其实本题也可以用栈来做，但是需要手动对空格和单词进行分割！！！
// 多一个空格的解决办法有很多，但是不同位置解决的难度不同
// 两种思路：1.在过程中解决 2.在结果中解决

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string ans, str;
        vector<string> tmp;
        stringstream ss(s);
        while (ss >> str)
            tmp.push_back(str);
        for (int i = tmp.size() - 1; i >= 0; i--)
            ans += tmp[i] + " "; // 在最后一个单词后面会固定多一个空格，在过程中并不多做处理，而是在结果中处理，因为造成的结果是固定不变的
        return ans.size() ? ans.substr(0,ans.size() - 1) : ""; // 因为空格是固定的，在返回结果时直接提取子字符串就能去掉空格
    }
};
// @lc code=end

        stack<string> st;
        int pos = 0;

        while (true) {
            pos = s.find_first_not_of(' ', pos);    // 指向单词首字母
            if (pos == string::npos)
                break;
            st.push(s.substr(pos, s.find(' ', pos) - pos));    // 储存单词
            pos = s.find(' ', pos);    // 找到单词后的位置
        }
        string out;
        while (!st.empty()) {
            out += st.top() + " ";
            st.pop();
        }
        out.pop_back();    //删除多余空格
        return out;
