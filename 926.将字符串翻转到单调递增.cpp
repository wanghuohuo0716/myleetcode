/*
 * @lc app=leetcode.cn id=926 lang=cpp
 *
 * [926] 将字符串翻转到单调递增
 */
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// 每个位置都有两个状态，0和1，操作有两种，0翻转到1和1翻转到0
// 某一位为1时，前面一位是0或者1都可以
// 某一位为0时，前面一位只能为0

// 动态规划求解

// @lc code=start
class Solution{
public:
    int minFlipsMonoIncr(string S){
        int n = S.length();
        if(n < 2)
            return 0;
        int zero = 0; // 记录上一次1翻转0的次数
        int one = 0; // 记录上一次1翻转0的次数
        for(char c : S){
            if(c == '1'){
                zero = zero + 1;
                one = min(zero-1, one);
            }
            else{
                one = min(zero, one) + 1;
            }
        }
        return min(zero,one);
    }
};
// @lc code=end
