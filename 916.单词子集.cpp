/*
 * @lc app=leetcode.cn id=916 lang=cpp
 *
 * [916] 单词子集
 */
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;
// 没要求相对字母的顺序，可以采用hash表来处理，统计B中单词的每个字母出现的次数是否小于等于A中的单词相应字母的次数
// 可以使用字母桶构造hash表，加速
// 单词a中同时出现所有的单词组B，且相应字母的出现次数也要满足(同种字母取次数最大的！！)，其实就是统计字母出现的次数
// 细节：最B终单词字母出现的最大次数，而不是所有字母之和

// @lc code=start
class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        int B_info[26] = {};
        for(int i = 0 ;i <B.size();++i) {
            int t_info[26] = {};
            for(auto c : B[i]){
                t_info[c-'a']++;
                B_info[c-'a'] = max(B_info[c-'a'],t_info[c-'a']); // 同种字母保留次数大的次数
            }
        }
        vector<string> ret;
        for(auto s: A){
            //caculate the fature
            int t_info[26] = {};
            for(auto c: s)
                t_info[c-'a']++;
            int j = 0;
            while(j<26&&t_info[j]>=B_info[j]) // B中的26个字母次数是否满足小于等于A中相应字母出现的次数
                j++;
            if(j==26) // 只有26个都满足的单词才符合要求
                ret.push_back(s);
        }
        return ret;
    }
};
// @lc code=end

