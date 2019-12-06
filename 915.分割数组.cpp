/*
 * @lc app=leetcode.cn id=915 lang=cpp
 *
 * [915] 分割数组
 */
#include <vector>
using namespace std;
// 维护三个变量来找到分界线，lmax是左边数组最大值，rmax是右边数组最大值，divide作为边界线
// 当遍历时，lmax大于元素时更新lmax并且更新divide分界线；当rmax小于元素时，更新rmax

// @lc code=start
class Solution{
public:
    int partitionDisjoint(vector<int> &A){
        int lmax = A[0];
        int rmax = A[1];
        int divide = 0;
        int N = A.size();
        for (int i = 1; i < N; ++i) {
            rmax = max(rmax, A[i]);
            if (A[i] < lmax) {
                divide = i;
                lmax = max(lmax, rmax);
            }
        }
        return divide + 1;
    }
};
// @lc code=end
