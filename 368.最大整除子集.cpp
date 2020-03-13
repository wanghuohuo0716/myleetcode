/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */
#include <vector>
#include <algorithm>
using namespace std;
// 题意理解：子集中，所有元素相互能整除，找到这个最大的子集中的所有的元素
// 排序后，找到数组中能整除的最长串

// 状态：dp[i]为以nums[i]结尾的序列最长长度(该序列中所有元素能相互整除)

// dp[i]也是与之前所有的状态有关，因为nums[i]可能是在前面某个序列的后一个，所以要遍历之前所有的状态
// 状态转移方程：dp[i] = dp[j] + 1;

// 难点在于记录位置，如何记录不同序列的路径，即元素的顺序，实际上相当于搜索路径，而且也是有dp[i]<dp[j]，与A*极其类似
// 记录路径中每个元素的上一个元素，就可以回溯出路径
// 使用数组，记录以每个元素结尾的最长序列中的上一个元素在数组中的位置，对于以元素nums[i]结尾的最长整除序列，nums[i]的上一个元素的位置记录在last[i]中。

// @lc code=start
class Solution{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums){
        int sz = nums.size(), mx = 0, end = -1;
        vector<int> dp(sz, 1), last(sz, -1), res; // last[i]: 在最大序列中 nums[i]的上一个元素在nums出现的下标
        sort(nums.begin(), nums.end());
        for (int i = 0; i < sz; i++){
            for (int j = 0; j < i; j++){
                if (nums[i] % nums[j] == 0 && dp[i] <= dp[j]){ // 排序后，i比j大，而且要求nums[i]一定是接到最长的序列后，更新后的。内循环一次后，初始的dp[i]就会被更新，dp[i]开始不断变化，直到所有的子序列遍历完后，才会变成最大值
                    dp[i] = dp[j] + 1;
                    last[i] = j; // 内层for循环，找到的last[i]是最大的子集j，i不变，j在变。
                }
            }
            if (dp[i] > mx){ // 记录总的长度
                mx = dp[i];
                end = i;
            }
        }
        for (int i = end; i != -1; i = last[i]) //倒序输出
            res.push_back(nums[i]);
        return res;
    }
};
// @lc code=end
