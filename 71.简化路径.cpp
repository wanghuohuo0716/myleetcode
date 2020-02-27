/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */
#include <string>
#include <vector>
#include <sstream>
using namespace std;
// 这道题用栈来处理思路比较清晰
// 简化的方法实际上就是通过pop和push操作来完成的，根据是否有..进行pop
// 利用数据结构可以简化单个目录的提取，使用sstream和getline函数，每次提取出来单个目录，然后进行处理
// 核心两点 1.简化方法使用push和pop 2.使用数据结构和内置函数来提取单层路径


// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stringstream is(path);
        vector<string> new_path; // 类似于栈的数据结果
        string res = "", tmp = "";
        // getline(is, tmp, '/'),从字符串流is中读取字符串，遇到/结束，读取的结果存放在tmp中，下一次读取的时候，会接着上一次读取的位置进行读取
        // 理解getline函数，https://blog.csdn.net/xw20084898/article/details/21377709
        while(getline(is, tmp, '/')) { // getline函数下一次读取的时候会接着上一次读取的结束位置开始读取
            if(tmp == "" || tmp == ".")
                continue;
            else if(tmp == ".." && !new_path.empty())
                new_path.pop_back();
            else if(tmp != "..")
                new_path.push_back(tmp);
        }
        for(string str:new_path)
            res +=  "/" + str;
        if(res.empty())
            return "/";
        return res;
    }
};
// @lc code=end

        path += "/";
        stack<string> st;
        string dir; // 单个路径
        for (auto c : path) {
            if (c == '/') { // 以c为终点，路径为dir
                if (dir == ".." && !st.empty()) {
                    st.pop();
                }
                else if (dir != ".." && dir != "." && !dir.empty()) {
                    st.push(dir);
                }
                dir.clear();
            }
            else {
                dir += c;
            }
        }
        string res;
        while (!st.empty()) {
            auto t = st.top();
            st.pop();
            res += string(t.rbegin(), t.rend()) + "/";
        }
        reverse(res.begin(), res.end());
        if (res.empty()) res = "/";
        return res;