/*
 * @lc app=leetcode.cn id=1156 lang=cpp
 *
 * [1156] 单字符重复子串的最大长度
 */
#include <string>
#include <vector>
#include <array>

using namespace std;
// 先把串处理成 字母+连续出现次数 例如 ： "ababa" ->a 1 b 1 a 1 b 1 a 1 然后，比较连续3个分组之间的关系，得到答案。
// 核心是判断 连续3个中间的那个分组个数是不是1，1、3分组字母是否相同。需要注意细节的是 返回的结果不可能超过这个字母出现的总次数

// tip：使用min和max来解决aaabaaa和aaabaaaca,是从连续的字符中拿一个来替换，还是从零散的字符拿出来替换，前者两个分段长度相加，后者两个分段长度相加后还要加1

// @lc code=start
class Solution {
public:
    int maxRepOpt1(string text) {
        vector<array<int, 2>> v;
        int cnt[26] = {}, ans = 0;

        for (int i = 0, lt = text.size(); i < lt; ) { // i,start双指针寻找最长的重复字符串
            int start=i;
            i++;
            while (i < lt && text[i]==text[start]) // start是起点，i是终点后一个
                i++;
            v.push_back({text[start]-'a', i-start}); // 记录相邻的重复字母及其出现的次数
            cnt[text[start]-'a'] += i-start; // 相同字符的总长度
        }
        for (auto& r : v) // r是array，r[0]代表第一个数字，r[1]代表第二个数字
            ans = max(ans, min(cnt[r[0]], r[1]+1)); // 直接把那个字符替换掉，新加了一个字符，然后判断字符是否比总的字符少，如果是就是对的，如果不是，那就没法新加一个字符,比如aaabaaa，把b和a交换，最大是6而不是7
        for (int i = 1, lv = v.size()-1; i < lv; i++) {
            if (v[i][1] == 1 && v[i+1][0] == v[i-1][0])
                ans = max(ans, min(cnt[v[i+1][0]], v[i+1][1]+v[i-1][1]+1)); // max(min)，保证了返回的结果不可能超过这个字母出现的总次数，通过这个避免查找是否还有多余的a可以进行交换，比如aaabaaacc,aaabaaaca，后者是最后一个a和b交换，还要找是哪个交换的，很麻烦
        }
        return ans;
    }
};
// @lc code=end

