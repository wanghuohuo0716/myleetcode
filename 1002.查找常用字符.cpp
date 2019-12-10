/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找常用字符
 */
#include <vector>
#include <string>
using namespace std;
// 本题可以理解为求每个字符串之间字符数量的交集,。用数组的下标i表示是哪个字符，用[i]表示该字符出现的次数
// 第一个字符串的字符数量列表为：{b:1, e:1,l:2, a:1}
// 第二个字符串的字符数量列表为：{l:2, a:1, b:1, e:1}
// 第三个字符串的字符数量列表为：{r:2, o:1, l:2, e:1}
// 求交集，{e:1, l:2}

// @lc code=start
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> out;
        int num[100][26]={0};                  //行数是单词数目，列数是26个字母
        for(int i =0;i<A.size() ;i++)
            for(int j=0;j<A[i].size();j++)
                num[i][(A[i][j]-'a')]++; //记录每个单词中包含的字母及字母出现的次数，(A[i][j]-'a')将字符串中的字母转换为数组中的索引，这个技巧是写代码的核心竞争力

        for(int j=0;j<26;j++)                  //将每列的最小值存到列首，找出所有字母在该字母下共同出现的字数
            for(int i=1;i<A.size();i++)
                num[0][j] = min (num[0][j],num[i][j]);

        string temp;                           //按照第一行保存的次数输出相应字母
        for(int j=0;j<26;j++){
            while(num[0][j]--)
            {
                temp.clear();
                temp.push_back((char)('a'+j)); // 将索引转换为字符
                out.push_back(temp);
            }
        }
        return out;
    }
};
// @lc code=end

