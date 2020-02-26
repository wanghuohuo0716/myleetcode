/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 暴力法计算每个子串，然后将子串翻转，与原串进行比较，相同则是回文串

// 动态规划，填二维的动态规划表
// 检测长度为3的子串是否为回文串，然后检测长度为4的子串，然后长度5,6,7...，一直检测到到整个字符串
// 动态规划体现在，检测长度为5的子串是否为回文串需要用到该子串去掉首位剩下长度为3的子串是否为回文串
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len==0||len==1)
            return s;
        int start=0;//回文串起始位置
        int max=1;//回文串最大长度
        vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组，dp[i][j]表示字符串从s[i]到s[j]是否为回文串
        for(int i=0;i<len;i++)//初始化状态
        {
            dp[i][i]=1;
            if(i<len-1&&s[i]==s[i+1]) // 如果存在2个相同的字符，重新定义回文串初始位置和初始长度
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for(int l=3;l<=len;l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for(int i=0;i+l-1<len;i++) // j=i+l-1是终止字符位置
            {
                int j=l+i-1;// j=i+2,j=i+3,j=i+4，表明dp[i][j]的子串长度是j-i=2,3,4...
                if(s[i]==s[j]&&dp[i+1][j-1]==1)//状态转移，根据定义dp[i+1][j-1]表示的字符串是dp[i][j]的子串
                {
                    dp[i][j]=1;
                    start=i;
                    max=l;
                }
            }
        }
        return s.substr(start,max);//获取最长回文子串
        }
};
// @lc code=end
        // 暴力法也是很实用的
        string res="";//存放结果
        string temp="";//存放子串
        for(int i=0;i<s.length();i++)
        {
            for(int j=i;j<s.length();j++)
            {
                temp=temp+s[j];
                string tem=temp;//tem存放子串反转结果
                reverse(tem.begin(),tem.end());//反转
                if(temp==tem)
                    res=res.length()>temp.length()?res:temp;
            }
            temp="";
        }
        return res;

    // 动态规划法(进行了状态压缩)
    int n = s.size();
    int max_s = 0, max_l = 0;
    for (int i = 0; i < n;) {
        int start = i, end = i;
        while (end + 1 < n && s[end] == s[end+1]) end++;
        i = end + 1;
        while (start - 1 >= 0 && end + 1 < n && s[start-1] == s[end+1]) {
            start--;
            end++;
        }
        if (end - start + 1 > max_l) {
            max_l = end - start + 1;
            max_s = start;
        }
    }
    return s.substr(max_s, max_l);
