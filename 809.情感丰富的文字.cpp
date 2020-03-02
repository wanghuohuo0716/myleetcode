/*
 * @lc app=leetcode.cn id=809 lang=cpp
 *
 * [809] 情感丰富的文字
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// 不能使用hash表，因为无法比较字母出现的顺序是否相同，而且可能会出现重复的字母，aabbaa的字母顺序是aba，但是hash表无法表示，对于unordered_map或者unordered_set容器，其遍历顺序与创建该容器时输入元素的顺序是不一定一致的，遍历是按照哈希表从前往后依次遍历的
// 1.是单词出现的字母顺序要相同，2.相应字母的数量要满足一定关系，满足这两个条件才能进行拓展
// 建立string->vector<int>的映射，最后的代码中，mw是单词S的非重复字母，vector<int>的长度与string长度相同，代表对应字母的出现的数目

// 参考代码是对每个单词的每个字母进行比较，i和j分别代表是非重复字母的索引

// @lc code=start
class Solution {
public:
    bool valid(const string& s, const string& q) {
        int i = 0; // 重复字母终止位置-1,也代表非重复字母的索引
        int j = 0;
        int l1 = 0; // 重复字母起始位置
        int l2 = 0;
        int d1 = 0; //重复字母长度
        int d2 = 0;
        while (i < s.size() && j < q.size()) {
            if (s[i] != q[j]) return false; // i和j代表非重复字母的索引，这个判断是为了保证非重复字母的对应顺序是相同的
            while (i < s.size() && s[i] == s[l1]) ++i; // 怎么分析i是最后一个重复字母的索引还是重复字母结束后的下一个字母的索引，根据判断条件来看，跳出的时候，肯定S[i]!=S[l1]，索引i是下一个字母的索引
            while (j < q.size() && q[j] == q[l2]) ++j;
            d1 = i - l1; // i是下一个字母的索引，所以求长度的时候不需要加1
            d2 = j - l2;
            if (d1 < d2 || (d1 < 3 && d1 > d2)) return false; // 每个字母必须满足一定条件才行
            l1 = i;
            l2 = j;
        }
        d1 = s.size() - i; // 最后一个字母比较
        d2 = q.size() - j;
        if (d1 < d2 || (d1 < 3 && d1 > d2)) return false;
        return true;
    }
    int expressiveWords(string S, vector<string>& words) {
        int res = 0;
        for (auto& w : words) {
            res += valid(S, w);
        }
        return res;
    }
};
// @lc code=end

// 建立string->vector<int>的映射，下列代码中，mw是单词S的非重复字母，vector<int>的长度与string长度相同，代表对应字母的出现的数目
string S = "heeellooo";
vector<int> ms; // 非重复单词的字母对应的次数
string mw; // 非重复单词的顺序
int i, j, k;
while (i < S.size())
{
    while (j < S.size() && S[i] == S[j])
        j++;
    mw += S[i];
    ms[k++] = i - j;
    i = j;
}