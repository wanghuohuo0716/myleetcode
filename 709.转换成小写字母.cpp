/*
 * @lc app=leetcode.cn id=709 lang=cpp
 *
 * [709] 转换成小写字母
 */
#include <string>
using namespace std;
// 利用ASCII值大小写之间相差32的性质，遇到大写的字母，加上32就是相应的小写字母。
// 其实也可以-‘A’ + ‘a’，结果也是32

// @lc code=start
class Solution {
public:
    string toLowerCase(string str) {
        int len = str.size();
        char c = 'a';
        char b = toupper('c');
        for(int i = 0; i < len; ++ i){
            if(str[i] <= 'Z' && str[i] >= 'A'){
                str[i] = str[i] + 32;
            }
        }
        return str;
    }
};
// @lc code=end

