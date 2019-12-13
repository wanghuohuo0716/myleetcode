/*
 * @lc app=leetcode.cn id=1177 lang=cpp
 *
 * [1177] 构建回文串检测
 */
#include <vector>
#include <string>
using namespace std;
// 其实本题与回文串关系不大，核心是分析出来k应该满足什么条件
// 注意题目说可以重新排列子串，因此影响回文串能否形成是字符串中出现次数为奇数的字母的个数，每个出现次数为奇数的字母就会多出来一个字母(把奇数分为偶数+1，偶数重排列为回文方式)，核心就是计算有多少个奇数的字母
// 使用s的前缀和dp[i+1]记录从s[0]到s[i](包含s[i])的子串区间内出现的字母的次数，要计算从s[l]到s[r]中26个字母各个出现的次数，dp[r]-dp[l]直接做差即可得到！
// 算法的难点就在于如何快速计算字符串中26个字母每个字母出现的次数，从而引出前缀和计算方式
// 使用桶记录26个字母的次数，二维前缀和，对于每个i都要计算26个字母的次数
// dp[i + 1] = dp[i];
// dp[i + 1][s[i] - 'a']++;

// @lc code=start
class Solution{
public:
    int replace(vector<int> &l, vector<int> &r, int sz){
        int odd = 0;

        for (int i = 0; i < 26; ++i){
            if ((r[i] - l[i]) % 2){ // 维护26个字母在子串中出现基数词的个数odd
                odd++;
            }
        }
        if (sz % 2 == 0)
            return odd / 2; // 偶数时，要换成回文串的次数k
        else
            return (odd - 1) / 2; // 奇数时，要换成回文串的次数k
    }

    vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries){
        int m = queries.size();
        vector<bool> ans(m, false); // 维护能否变成回文串
        vector<vector<int>> dp(s.size() + 1, vector<int>(26, 0)); // 维护每个子串中出现同一个字母的次数

        for (int i = 0; i < s.size(); ++i){ // 使用s的前缀和dp[i+1]记录从s[0]到s[i](包含s[i])的子串区间内出现的字母的次数，要计算从s[l]到s[r]中26个字母各个出现的次数，直接做差即可得到！
            dp[i + 1] = dp[i];
            dp[i + 1][s[i] - 'a']++; // 第二个维度类似桶，记录该字母出现的次数
        }

        for (int i = 0; i < m; ++i){
            int l = queries[i][0];
            int r = queries[i][1];
            int rep = replace(dp[l], dp[r + 1], r + 1 - l);
            if (rep <= queries[i][2]) // 换成回文需要的k是否小于给定的k
                ans[i] = true;
        }
        return ans;
    }
};
// @lc code=end
