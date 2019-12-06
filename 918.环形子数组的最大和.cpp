/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] 环形子数组的最大和
 */
#include <vector>
#include <algorithm>
using namespace std;
// 此题与连续子序列之和类似，题解中kanade算法实际就是动态规划算法
// 以当前元素为结尾子串的最大和=max(以前一个元素为结尾子串的最大和+当前元素，当前元素)
// 此题的特殊点在于可以环形遍历，那么最大值有两种可能，一种是正常子串，一种是环形子串，正常子串正常求即可。
// 当答案处于环形子串中，由于整个数组之和固定，那么求最小子串和，然后减去此和就是环形数组的最大子串了

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int temp = A[0];
        int max_val = temp,sum= temp;
        for(int i=1;i<A.size();i++){
            sum += A[i];
            temp = max(A[i], temp + A[i]);
            max_val = max(max_val,temp);
        }
        int min_val = 0;
        temp = 0;
        for(int i=1;i<A.size()-1;i++){
            temp = min(A[i], temp + A[i]);
            min_val = min(min_val,temp);
        }
        return max(max_val,sum-min_val);
    }
};
// @lc code=end

