/*
 * @lc app=leetcode.cn id=905 lang=cpp
 *
 * [905] 按奇偶排序数组
 */
#include <vector>
using namespace std;
// 提供额外的空间，能简化算法。多拿出一个数组，把不同的内容拼接起来。第一遍输出奇数，第二遍输出偶数

// @lc code=start
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> ans(A.size());
        int t = 0;

        for (int i = 0; i < A.size(); ++i)
            if (A[i] % 2 == 0)
                ans[t++] = A[i];

        for (int i = 0; i < A.size(); ++i)
            if (A[i] % 2 == 1)
                ans[t++] = A[i];

        return ans;
    }
};
// @lc code=end

