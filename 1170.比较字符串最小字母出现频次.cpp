/*
 * @lc app=leetcode.cn id=1170 lang=cpp
 *
 * [1170] 比较字符串最小字母出现频次
 */
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
// word[i]的长度不超过10，最小字母在word[i]可能出现的次数是0,1,2,3..,10，同一个字母出现的最大次数不大于10，统计word中出现每种次数的单词数目
// 计算出f(queries[i]),对比它的次数高的单词数进行求和就是结果
// 而题意就是要进行比较字母的次数，使用数组储存具有相同字母数目的单词数目，索引是相同字母的次数，值是单词的数目

// @lc code=start
class Solution {
public:
    int f(string s) // 统计字符串中最小字母的次数
        {
            sort(s.begin(),s.end());
            int count=1;
            for(int i=1;i<s.size();i++)
            {
                if(s[i]==s[i-1])
                    count++;
                else
                    break;
            }
            return count;
        }

    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> ans;
	    vector<int> count(12, 0); // words[i].length <= 10
	    for (int i = 0; i < words.size(); i++)
		    count[f(words[i])]++;
	    for (int i = 9; i >= 0; i--)
		    count[i] += count[i +1];
	    for (int i = 0; i < queries.size(); i++)
		    ans.push_back(count[f(queries[i])+1]);
	    return ans;
    }
};
// @lc code=end

