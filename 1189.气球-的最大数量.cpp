/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */
#include <string>
#include <algorithm>
using namespace std;
// 统计每个单词出现的次数，然后计算balloon需要的字母的次数，然后选择最小那个次数即可

// @lc code=start
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int count[26] = {0};
        for (char c : text)
            count[c-'a']++; // 索引顺序作为字母顺序，值为该字母在text中出现的次数

        int balloonCount[] = { // 统计每个balloon出现的次数
            count['b'-'a'],
            count['a'-'a'],
            count['l'-'a']/2,
            count['o'-'a']/2,
            count['n'-'a']
      };
        return *min_element(balloonCount, balloonCount+5); // 短板效应，只有满足最小的数才能凑齐ballopn
    }
};
// @lc code=end

