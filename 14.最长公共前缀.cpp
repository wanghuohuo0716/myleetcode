/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
#include <string>
#include <vector>
using namespace std;
// 有一个预备知识，LCP(s1,s2,s3...sn)=LCP(LCP(LCP(s1,s2),s3)...sn)，即两个子串比较后公共子串再与其它子串进行比较，最后所有子串比较完了就是最长公共子串了
// 核心：假设第一个字符串作为最长公共子串，开始比较，如果两个字符串不同，则去掉最长公共子串最后一个字符，再进行比较，直到找到公共子串，！更新！公共子串，然后比较下一个字符串。如果两个字符串没有公共子串，则直接返回

// C++有直接提取子串的api,s.substr(a,b)。直接拿字符串进行比较，而不是一个一个字符进行比较
// 一个个字符比较是从前往后找到公共子串，字符串比较是把公共子串的最后一个字符去掉找到公共子串
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string r = strs.size() ? strs[0] : ""; // r是最小公共前缀
        for(auto s: strs){
            while(s.substr(0, r.size()) != r){ // strs中的每个字符串的前r.size()个子字符是否与r这个最小公共前缀相同
                r = r.substr(0, r.size() - 1); // 如果不同，则减小最小公共前缀的长度，减去最后一个字符
                if(r == "") // 如果最小前缀字符串为空则返回，无公共前缀
                    return r;
            }
        }
        return r;
    }
};
// @lc code=end

