/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 *
 * [1031] 两个非重叠子数组的最大和
 */
#include <vector>
using namespace std;
// 核心思想：滑动窗口+分界线，同时用四维数组记录分界线左右两侧连续子数组元素最大和
// 题意限定了L和M的大小，子数组的长度是固定的，所以可以考虑用滑动窗口法
// 如果是避免重叠的话，则必然是存在一个分界线，把A分成两半，存在两大类情况，子数组L在M的左边或者L在M的右边
// 分别在两边找到连续L和M个元素最大和，然后求和即可
// 问题的难点在于分界线，分界线以索引划分，要求每个索引作为分界线时，连续L个元素在index左(右)边数组中的最大值和连续M在index右(左)边数组中最大值
// 因此需要维护一个n*4维的矩阵
// dp[i][0]记录i左边连续 L 长度子数组最大的元素和
// dp[i][1]记录i右边连续 M 长度子数组最大的元素和
// dp[i][2]记录i左边连续 M 长度子数组最大的元素和
// dp[i][3]记录i右边连续 L 长度子数组最大的元素和

// @lc code=start
class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		// 4个滑动窗口, 4种情况
		vector<vector<int>> dp(A.size(), vector<int>(4, 0));
		int presum = 0;
		int maxsum;
		for (int i = 0; i < L; ++i)
		{
			presum += A[i]; // presum 记录连续L个元素的和
		}
		maxsum = presum;
		dp[L - 1][0] = maxsum;
		for (int i = L; i < A.size(); ++i)
		{
			presum -= A[i - L]; // 减去前面一个数
			presum += A[i]; // 加上后面一个数，求和元素的数量不变，滑动窗口
			maxsum = max(maxsum, presum);
			dp[i][0] = maxsum; // 记录到i处，前面数组中的连续L个元素的最大和，i是分界线
		}

		presum = 0;
		for (int i = 0; i < M; ++i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[M - 1][1] = maxsum;
		for (int i = M; i < A.size(); ++i)
		{
			presum -= A[i - M];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][1] = maxsum;
		}

		presum = 0;
		for (int i = A.size() - 1; i >= A.size() - L; --i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[A.size() - L][2] = maxsum;
		for (int i = A.size() - L - 1; i >= 0; --i)
		{
			presum -= A[i + L];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][2] = maxsum;
		}

		presum = 0;
		for (int i = A.size() - 1; i >= A.size() - M; --i)
		{
			presum += A[i];
		}
		maxsum = presum;
		dp[A.size() - M][3] = maxsum;
		for (int i = A.size() - M - 1; i >= 0; --i)
		{
			presum -= A[i + M];
			presum += A[i];
			maxsum = max(maxsum, presum);
			dp[i][3] = maxsum;
		}

		//计算答案
		int res = 0;
		//L在M左边
		for (int i = L; i <= A.size() - M; ++i)
			res = max(res, dp[i - 1][0] + dp[i][3]);
		//M在L左边
		for (int i = M; i <= A.size() - L; ++i)
			res = max(res, dp[i - 1][1] + dp[i][2]);

		return res;
    }
};
// @lc code=end

