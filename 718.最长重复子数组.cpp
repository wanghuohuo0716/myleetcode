/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 */
#include <vector>
#include <algorithm>
using namespace std;
// 这个C++的algorithm库是有现成函数的
// @lc code=start
class Solution {
public:
    int findMax(vector<int> A, vector<int> B) {
        int repeat_max = 0;
        int an = A.size(), bn = B.size();
        for(int len=1; len <= an; len++) {
            repeat_max = max(repeat_max, findmaxLen(A, 0, B, bn-len, len));
        }
        for(int j=bn-an; j >= 0;j--) {
            repeat_max = max(repeat_max, findmaxLen(A, 0, B, j, an));
        }
        for(int i=1;i<an;i++) {
            repeat_max = max(repeat_max, findmaxLen(A, i, B, 0, an - i));
        }
        return repeat_max;
    }

    // 从a[i]和b[j]处往后进行比较，比较的长度是len
    int findmaxLen(vector<int> a, int i, vector<int> b, int j, int len) {
        int count = 0, repeat_max = 0;
        for(int k = 0; k < len; k++) {
            if(a[i+k] == b[j+k]) { //同时往后移
                count++; // 如果相同就计数
            // 不同有两种情况：1.第一位不同则舍弃此次，继续往后比 2.前面相同的部分结束，则比较相同的部分的个数与已有的哪个大，如何通过代码处理这两种情况？
            } else if(count > 0) {
                repeat_max = max(repeat_max, count);
                count = 0;
            }
        }
        return count > 0 ? max(repeat_max, count) : repeat_max;
    }

    int findLength(vector<int>& A, vector<int>& B) {
    return A.size() < B.size() ? findMax(A, B) : findMax(B, A);
    }
};
// @lc code=end

