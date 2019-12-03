/*
 * @lc app=leetcode.cn id=775 lang=cpp
 *
 * [775] 全局倒置与局部倒置
 */
#include <vector>
#include <algorithm>
using namespace std;
// 因局部倒置一定是全局倒置，所以全局倒置数>=局部倒置数，只有一种情况等号才会成立，就是将0-N按顺序排列后只将其中相邻的两个数字交换次序，即不存在额外的全局倒置
// 连续做的两道题都是排列的题，感觉这种题就特么是找规律，没有太大的意义

// @lc code=start
class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i)
            if (abs(A[i] - i) > 1)
                return false;
        return true;
    }
};
// @lc code=end

