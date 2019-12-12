/*
 * @lc app=leetcode.cn id=1053 lang=cpp
 *
 * [1053] 交换一次的先前排列
 */
#include <vector>
#include <algorithm>
using namespace std;
// 数字的字典序，1，2，3，4，5的排列，则12345在前，54321在后
// 此题核心是找出交换一次小于A的所有序列(可以把序列的每一位看做一个整数的每一位，把序列看成一个数)中选出最大的那个序列
// 当出现下降时，记录下降的left和right，在left后面的序列中找到小于left的最大数right与left交换。
// 为什么这种方法会是最小？
// 用曲线的方法分析最为准确，因为只能交换一次，所以目标是找到使left下降最少即可。如果可以交换多次，则后面的序列还得要进行排列，依次从大到小
// https://leetcode-cn.com/problems/previous-permutation-with-one-swap/solution/shu-ju-fen-xi-hou-que-ding-jie-ti-luo-ji-by-jacder/
// 一定会有A[i] > A[i+1]，否则就是递增序列，12345，没有比它更小的了

// @lc code=start
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
    int left = 0, right = 0;
    for (int i = 0; i < A.size() - 1; i++) {
        if (A[i] > A[i+1]){ //发现数据变小时记录下来left和right
            left = i;
            right = i + 1;
        }
        else if (left != right && A[i] < A[i + 1] && A[left] > A[i + 1]){ // 后续如果有数据变大并且不大于left，更新right
            right = i + 1;
        }
    }
    swap(A[left], A[right]);
    return A;
    }
};
// @lc code=end

