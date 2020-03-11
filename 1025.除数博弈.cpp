/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */
#include <vector>
using namespace std;

// 属于序列型，从题目给的两个示例推断出可以使用动态规划
// 记dp[N]为黑板上数字为N的情况下,Alice的输赢情况， 如果Alice取了数字x, 那么显然dp[N]与dp[N -x]输赢情况相反。
// x可以取的值很多，只要dp[N -x]中任意一个为False, 那么Alice取这个x，Bob就会输
// 实际上Alice只有一次操作的机会

// 从开始状态向后推导，建立动态规划表即可判断Alice是否能赢

// @lc code=start
class Solution {
public:
    bool divisorGame(int N) {
        vector<bool> dp(N+1,false);
        dp[2] = true;
        for (int i = 3; i < N + 1; i++) // 从开始状态向后推导，建立动态规划表
            for(int j = 1; j < i;j++){ // j相当于取出来的数x，只要有一个j可以使得dp[i-j]为false即可，Alice就会选这个j，则Bob就是i-j，必然输
                if(i % j == 0 && !dp[i - j]){
                    dp[i] = true;
                    break;
                }
            }
        return dp[N];
    }
};
// @lc code=end

