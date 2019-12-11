/*
 * @lc app=leetcode.cn id=1014 lang=cpp
 *
 * [1014] 最佳观光组合
 */
#include <vector>
using namespace std;
// 此题的本质是求A[i] + A[j] + i - j的最大值，这个值可以解耦计算，分别计算A[i] + i与A[j] - j的最大值，然后求和即可
// 即维护两个变量记录这两个最大值，一遍遍历完后就知道了结果

// @lc code=start
class Solution{
public:
    int maxScoreSightseeingPair(vector<int> &A){
        int res = 0;
        int pre_max = A[0] + 0; // 初始值
        for (int j = 1; j < A.size(); j++){
            res = max(res, pre_max + A[j] - j); // 判断能否刷新res
            pre_max = max(pre_max, A[j] + j); // 判断能否刷新pre_max， 得到更大的A[i] + i
        }
        return res;
    }
};
// @lc code=end
