/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include <vector>
#include <string>
using namespace std;
// 状态：dp[i]为以s[i]结尾的子串是否可以被空格拆分为多个在字典中出现的单词

// 为什么是动态规划?此时s被划分成了两部分，s[0:i],s[i:end]，前者是个子串，可以被多次划分，构成了子问题，最后dp[n]就是结果了
// 状态转移方程：dp[i]的转移关系，如果dp[i - j]是true并且s[j:i]在wordDict里, 那么dp[i] = true;

// 看图理解,https://leetcode-cn.com/problems/word-break/solution/dong-tai-gui-hua-python-dai-ma-by-liweiwei1419-2/
// 状态转移方程，https://leetcode-cn.com/problems/word-break/solution/dong-tai-gui-hua-zi-ding-xiang-xia-he-zi-di-xiang-/

// @lc code=start
class Solution{
public:
    bool wordBreak(string s, vector<string> &wordDict){
        vector<int> dp(s.size()+1, 0);
        dp[0] = 1;
        for(int i=0; i<=s.size(); ++i) {
            for(auto word: wordDict) {
                int ws = word.size();
                if(i - ws >= 0) { // i - ws相当于j
                    int cur = s.compare(i-ws, ws, word);
                    if (cur==0 && dp[i-ws]==1) {
                        dp[i] = 1;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end
