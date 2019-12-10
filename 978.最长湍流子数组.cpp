/*
 * @lc app=leetcode.cn id=978 lang=cpp
 *
 * [978] 最长湍流子数组
 */
#include <vector>
using namespace std;
// 这种记录连续子数组首地址anchor的方法称为滑动窗口法，不是双指针方法
// 一个数组这种连续的数组是会划分为不同的块，不存在交集，当当前块结束时，当前块的末尾可能是下一个块的开始
// ！！！注意，这种滑动窗口法使用的前提是每个连续的子数组之间不存在交集！！！
// 多个嵌套的的条件运算符 ? :从第一个往后，根据不同的case处理，是线性逻辑思维

// @lc code=start
class Solution {
public:
    int compare(int a, int b){ //自己写的条件运算符，根据不同的case处理，先处理等于；线性逻辑思维
        return a == b ? 0 : (a > b) ? 1 : -1;
    }

    int maxTurbulenceSize(vector<int>& A) {
        int N = A.size();
        int ans = 1; // 记录最大值
        int anchor = 0; // 记录序列的索引

        for (int i = 1; i < N; ++i) {
            int c = compare(A[i-1], A[i]);
            if (i == N-1 || c * compare(A[i], A[i+1]) != -1) {
                if (c != 0)
                    ans = max(ans, i - anchor + 1);
                anchor = i;
            }
        }

        return ans;
    }

};
// @lc code=end

