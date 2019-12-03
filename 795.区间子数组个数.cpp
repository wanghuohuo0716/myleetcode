/*
 * @lc app=leetcode.cn id=795 lang=cpp
 *
 * [795] 区间子数组个数
 */
#include <vector>
#include <algorithm>
using namespace std;
// 使用双指针来记录子数组的长度
// 有一种动态规划的思想在里面，i-j代表是从j到i之间包含[i]的子数组的个数，累加把之前所有其它不含[i]的子数组；即j-i的子数组个数 = 不含[i]的子数组个数 + 包含[i]的子数组的个数
// 区间大于等于L小于R的子数组个数 = 区间小于等于R的子数组个数 - 区间小于L的子数组个数；
// @lc code=start
class Solution
{
public:
    int numSubarrayBoundedMax(vector<int> &A, int L, int R)
    {
        int t1 = 0, t2 = 0;
        int n = A.size();
        for (int i = 0, j = 0; i < n;)
        {
            if (A[i] <= R)
            {
                ++i;
                t1 += i - j; // 1 + 2 + 3 + 4 + ...计算子数组的数目
            }
            else
            {
                ++i;
                j = i;
            }
        }
        for (int i = 0, j = 0; i < n;)
        {
            if (A[i] < L)
            {
                ++i;
                t2 += i - j;
            }
            else
            {
                ++i;
                j = i;
            }
        }
        return t1 - t2;
    }
};
// @lc code=end
