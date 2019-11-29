/*
 * @lc app=leetcode.cn id=670 lang=cpp
 *
 * [670] 最大交换
 */
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// 思路比较简单，找到数中最大的那个数，然后放到首位即可，同时注意特殊条件，如果首位已经是最大的，则继续向后排
// 代码的实现比较巧妙，通过把int转换为string从而能对数的每个部分进行单独的索引和比较大小，这个tips很棒！

// @lc code=start
class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        for (int i = 0; i < s.size(); ++i) {
            int index = i;
            for (int j = i + 1; j < s.size(); ++j) { // 找到i后面最大的数
                if (s[j] >= s[index])
                    index = j;
            }
            if (index != i && s[index] != s[i]) { // 交换最大的数
                swap(s[i], s[index]);
                break; // 跳出最外层的for
            }
        }
        return stoi(s);
    }
};
// @lc code=end

