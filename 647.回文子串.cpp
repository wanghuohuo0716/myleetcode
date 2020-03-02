/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */
#include <string>
#include <vector>
using namespace std;
// 题目有个特点是，即使是由相同的字符组成，也会被计为是不同的子串。（如果去掉这个限制可以使用hash表处理）
// for循环来调整中心位置，奇数和偶数都要比较

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int res=0;
        //当前位置（i）作为中心位置向两边扩散或（i,i+1）向两边扩散
        for(int i=0;i<s.size();i++){ // for循环实现了不同的中心进行拓展，解决了即使字符相同，位置不同的可以区分开
            res+=help(s,i,i+1);// 偶数，（i,i+1）向两边扩散,但是不能只拓展一个，比如aaa有6个子串，如果从奇数进行拓展就只有4个，忽略了aa
            res+=help(s,i,i);// 奇数，（i）作为中心位置向两边扩散
        }
        return res;
    }

    int help(string s,int start,int end){
        int count=0;
        while(start>=0&&end<s.size()){
            if(s[start]==s[end]){
                start--;
                end++;
                count++;
            }
            else
                break;
        }
        return count;
    }
};
// @lc code=end

