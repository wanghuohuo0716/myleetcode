/*
 * @lc app=leetcode.cn id=792 lang=cpp
 *
 * [792] 匹配子序列的单词数
 */
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// 字符串的题目中使用桶排序的情况还是比较常见的，此题是根据字符串去匹配word，而不是根据word去找字符串，能够提升效率
// 因为 S 很长，所以寻找一种只需遍历一次 S 的方法，避免暴力解法的多次遍历。
// 将所有单词根据首字母不同放入不同的桶中。例如当 words = ['dog', 'cat', 'cop']，根据首字母不同可以分为 'c' : ('cat', 'cop'), 'd' : ('dog',)。换句话说，每个桶中的单词就是该单词正在等待匹配的下一个字母。在遍历 S 的同时，将匹配到单词根据下一个需要匹配的字母移动到不同的桶中。
// 使用长度为 26 的数组 heads 做桶，每个字母对应一个桶。访问 S 中的每个字母时，将该字母对应桶中的所有单词，根据下一个等待匹配字母放入到不同的桶中。如果已经匹配到单词的最后一个字母，那么子序列单词数加 1。

// 暴力法：在 S 上遍历每个 word，首先找到第一个字母 word[0]，然后接着找第二个字母 word[1]，以此类推，直到在 S 中找到 word 的全部字母为止。

// @lc code=start
class Solution {
public:
    int pos[50005][27];
    int numMatchingSubseq(string S, vector<string>& words) {
        int len = S.size();
        memset(pos, -1, sizeof(pos));
        pos[len - 1][S[len - 1] - 'a'] = len - 1;
        for (int i = len - 2; i >= 0; i--){ //预处理
            for (int j = 0; j < 26; j++)
                pos[i][j] = pos[i + 1][j];
            pos[i][S[i] - 'a'] = i;
        }
        int cnt = 0;
        for (auto& s : words){
            int x = 0, p = 0;
            while (p < s.size() && pos[x][s[p] - 'a'] != -1){
                x = pos[x][s[p] - 'a'];
                p++;
                if (s[p] == s[p - 1]) x++; //相同字母 需要加 1
            }
            if (p == s.size()){
                cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end

