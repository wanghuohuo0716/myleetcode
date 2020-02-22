/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */
#include <string>
using namespace std;
// 核心思想是如何判断单词的个数，而单词的个数和单词内容无关，与空格有关
// 单词的个数是由空格决定的,可以考虑统计空格的个数来计算单词的个数，但是测试用例有个case是“      ”，都由空格组成，结果会出错

// 由mark作为记录是否有空格，当检测到空格时置位true，检测到单词时置位false，而不是统计空格的个数！
// 每个空格加上紧邻空格后面的字符是否不是空格作为判断一个单词

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        bool mark = true;
        int count = 0;
        for(int i = 0 ;i<s.length();i++)
        {
            if(s[i]!=' '&&mark){ // 每个空格加上紧邻空格后面的字符是否不是空格作为判断一个单词
                count++;
                mark = false;
            }
            else if(s[i]==' ')
                mark = true;
        }
        return count;
    }
};
// @lc code=end
