/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
#include <vector>
using namespace std;
// @lc code=start

/*
解题思路：
一般来说，子序列的遍历有三种方式：
1.以某个元素为起始点，形成长度递增的子序列
2.以某个元素为终点，形成长度递增的子序列
3.某序列长度递增，形成子序列，如长度为1的子序列就是原始序列中的所有元素

其中第二种遍历的方式容易被构造成动态规划解法
贪心思想：当前元素为终点的子序列最大和 只能是 前一个元素为终点的最大和子序列加上当前元素形成的新序列 或者 当前元素。二选一
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        if(nums.size() == 0) return NULL;
        int res = nums[0];
        int f_n = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            f_n = max(nums[i], f_n + nums[i]); //f_n是以当前元素为末尾的最大子序列和
            res = max(f_n, res); //把当前元素和之前元素的最大子序列和作比较，找最大的
        }
        return res;
    }
};
//定义一个函数f(n)，以第n个数为结束点的子数列的最大和，存在一个递推关系f(n) = max(f(n-1) + A[n], A[n]);
//将这些最大和保存下来后，取最大的那个就是，最大子数组和。因为最大连续子数组 等价于 最大的以n个数为结束点的子数列和
// @lc code=end

