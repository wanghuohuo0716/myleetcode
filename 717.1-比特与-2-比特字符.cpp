/*
 * @lc app=leetcode.cn id=717 lang=cpp
 *
 * [717] 1比特与2比特字符
 */
#include <vector>
using namespace std;
// 此最后一位是否为一比特字符，只和他左侧出现的连续的 1 的个数有关
//（即它与倒数第二个 0 出现的位置之间的 1 的个数,如果数组中只有 1 个 0，那么就是整个数组的长度减一）有关。
// 如果 1 的个数为偶数个，那么最后一位是一比特字符，如果 1 的个数为奇数个，那么最后一位不是一比特字符。

// @lc code=start
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size() - 2; //倒数第二个索引
        while (n >= 0 && bits[n] > 0) n--; //从后往前找连续1的索引
        return (bits.size() - n) % 2 == 0;
    }
};
// @lc code=end

