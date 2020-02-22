/*
 * @lc app=leetcode.cn id=443 lang=cpp
 *
 * [443] 压缩字符串
 */
#include <string>
#include <vector>
using namespace std;
// 思路比较简单，双指针找到原数组中重复字符的起止位置，计算数字，然后在原数组上进行修改

// 大循环：采用双指针迭代的方法，由一个指针带着另一个走（j = i），由i跳过重复的元素
// 小循环1：对i进行自增，找到j的下一个位置
// 结果变量所指位置被赋为上一个处理完的元素
// 小循环2：将重复次数（即i和j的间隔）转为字符串，注意要用sprintf（itoa不是标准库函数），对结果变量所指位置赋值
// 返回结果变量

// @lc code=start
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int cur = 0; // 在原数据上修改的指针索引
        for(int i = 0, j = 0; i < n; j = i) {
            while(i < n && chars[i] == chars[j]) { // 此时i指向的是下一个字符
                i++;
            }
            chars[cur++] = chars[j];
            if(i - j == 1) {
                continue;
            }
            string s = to_string(i - j); // 把一个个字符单独提出来
            for(int t = 0; t < s.size(); t++) {
                chars[cur++] = s[t];
            }
        }
        return cur;
    }
};
// @lc code=end

