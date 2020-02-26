/*
 * @lc app=leetcode.cn id=824 lang=cpp
 *
 * [824] 山羊拉丁文
 */
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;
// 使用set数据类型，便于快速查找
// 构造字符串流istringstream的时候，空格会成为字符串参数的内部分界,因而成为以空格分开每个单词的有效工具

// @lc code=start
class Solution {
public:
    string toGoatLatin(string S) {
        unordered_set<char> vowels={'a','A','e','E','i','I','o','O','u','U'};
        istringstream ss(S);
        string temp,ans;
        string str="ma";
        while(ss>>temp){ // 从字符串流从弹出一个单词
            str+="a"; // 每个单词都加一个a
            if(vowels.find(temp[0])!=vowels.end())     //单词首字母是元音
                ans+=temp+str+" ";
            else
                ans+=temp.substr(1)+temp[0]+str+" ";       //单词首字母不是元音
        }
        ans.pop_back(); // 最后面多了一个a
        return ans;
    }
};
// @lc code=end
class Solution {
public:
    string toGoatLatin(string S) {
        S.append(1, ' ');
        int len = S.length();
        int order = 1;
        string temp = "";
        string ans = "";
        for(int i = 0; i < len; i++) {
            if (S[i] == ' ') {
                if (!(temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u' || temp[0] == 'A' || temp[0] == 'E' || temp[0] == 'I' || temp[0] == 'O' || temp[0] == 'U')) {
                    temp.append(1, temp[0]);
                    temp.erase(0, 1);
                }
                ans = ans + temp + "ma";
                ans.append(order, 'a');
                ans.append(1, ' ');
                order++;
                temp = "";
            }
            else
                temp.append(1, S[i]);
        }
        ans.pop_back();
        return ans;
    }
};
