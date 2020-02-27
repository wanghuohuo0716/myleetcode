/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
#include <string>
using namespace std;
// 类似爬楼梯的动态规划，f(n)=f(n-2)+f(n-1)，最后迈1步还是2步
// 不难发现，字符串s的解码方法与s加上一个字符后的解码方法存在联系
// dp[i]为，s[1]...s[i]解码方法的总数，s[i]的解码方法与s[i-1]和s[i-2]有关
// 若s[i]='0'(字符串i处的字符为0),则s[i-1]必须为1或者2(才能构成数字10或20，单独数字0无法解码)，因此dp[i]=dp[i-2],因为后面数是10或者20，只有一种解码方法，解码总数不变
//                               若s[i-1]不是1或者0，则返回0，因为0无法单独解码

// 若s[i-1]='1',如果把s[i-1]和s[i]看做1个整数进行解码，则解码方法为dp[i-2],(解码的最后一个字符是s[i-2])
//              如果把s[i-1]和s[i]看做2个整数分布解码，则解码方法为dp[i-1],(解码的最后一个字符是s[i-1])
//              最终结果dp[i]=dp[i-1]+dp[i-2]

// 若s[i-1]='2',与上面s[i-1]='1'类似，但是要求s[i]必须在0-6范围内才会有dp[i]=dp[i-1]+dp[i-2],否则dp[i]=dp[i-2]

// dp[i]仅与前两项有关，可以用单变量代替数组dp[]，使得空间复杂度从O(N)降到O(1)

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int pre = 1, curr = 1;//dp[i-1] = dp[i] = 1,解码方法总数
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr; // temp相当于dp[i-2]
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2')
                curr = pre;
            else
                return 0; // 0无法单独解码
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;
        pre = tmp;
    }
    return curr;
    }
};
// @lc code=end

