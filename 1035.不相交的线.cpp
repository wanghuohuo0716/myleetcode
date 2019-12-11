/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */
#include <vector>
using namespace std;
// 使用动态规划的方法，难点在于动态规划的公式不是那么明显能够推导出来的，状态的选择很关键，此题的状态是设函数f(x,y)标识A的前x个数字和B的前y个数字，能绘制出的最大连接数。
// 与最长公共子序列类似，https://leetcode-cn.com/problems/uncrossed-lines/comments/
// 设 A[0] ~ A[x] 与 B[0] ~ B[y] 的最大连线数为 f(x, y)，那么对于任意位置的 f(x, y) 而言：
// 如果 A[x] == B[y]，即 A[x] 和 B[y] 可连线，此时 f(x, y) = f(x - 1, y - 1) + 1
// 如果 A[x] != B[y]，即 A[x] 和 B[y] 不可连线，此时最大连线数取决于 f(x - 1, y) 和 f(x, y - 1) 的较大值

// 假设A[x]!=B[y]时，不可能A[x]与B[y]都参与连线，否则一定会相交，所以结果是max(dp[x][y-1], dp[x-1][y]);
// 假设A[x]==B[y]时，么一定A[x]和B[y]连是最优解,即dp[x][y]=dp[x-1][y-1]+1
// 在A[x]==B[y]时有2种情况，1.A[x]和B[y]都参与连接，则一定会相交 2.只有A[x]或B[y]参与连接，假设B[y]参与了连接，连了A[z]，那么A[z]一定小于A[x]，所以f(z,y)=f(x,y)，和A[x]连B[y]的情况值一样。
// 最后推导出来了递推公式

// 递推公式是f(x,y)=f(x-1,y-1)+1;如果x作为索引，会有负值，所以变成dp[i + 1][j + 1] = dp[i][j] + 1，为避免数组越界，数组长度还要+1
// @lc code=start
class Solution{
public:
    int maxUncrossedLines(vector<int> &A, vector<int> &B){
        int n1 = A.size();
        int n2 = B.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
        for (int i = 0; i < n1; i++){
            for (int j = 0; j < n2; j++){
                if (A[i] == B[j]){
                    dp[i + 1][j + 1] = dp[i][j] + 1; //dp[0][0]为0，数组的长度是size+1,因此可以认为
                }
                else{
                    dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }
        return dp[n1][n2];
    }
};
// @lc code=end
