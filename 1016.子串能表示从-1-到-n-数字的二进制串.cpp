/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
 */
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;
// 朴素的想法，遍历从1到N所有的整数，将其转换为二进制字符串，看S中是否存在
// tip:查询二进制字符串是否在S中存在，可以直接用find函数！！！Amazing！

// @lc code=start
class Solution {
public:
    bool queryString(string S, int N) {
        for(int i=1; i<=N; i++)
            if(S.find(toBinary(i)) == string::npos)
               return false;
        return true;
    }

    string toBinary(int n){ // 十进制转换为表示的二进制，int->string
        string res = "";
        while(n){
            res = (to_string(n%2)) + res;
            n = n/2;
        }
        return res;
    }
};
// @lc code=end

