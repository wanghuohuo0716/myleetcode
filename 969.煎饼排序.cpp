/*
 * @lc app=leetcode.cn id=969 lang=cpp
 *
 * [969] 煎饼排序
 */
#include <vector>
#include <algorithm>
using namespace std;
// 感觉数组的算法就是排序和查找，如何针对特殊的情况降低时间和空间复杂度

// stl库函数max_element()计算区间的最大元素
// 每次都把当前区间最大的数移动到当前区间的最后面
// 假设当前区间为[0, i]，该区间内最大的数的下标为j
// 那么我们可以通过两次翻转达到目的：
// 1，j + 1，将该数移动到区间头部
// 2，i + 1，将该数移动到区间尾部
// @lc code=start
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int N = A.size();
        vector<int> res;
        for (int i = N - 1; i > 0; --i) {
            int j = max_element(A.begin(), A.begin() + i + 1) - A.begin(); // 计算最大元素的index
            if (j > 0) { // 若最大元素不再首位则需要翻转2次
                reverse(A.begin(), A.begin() + j + 1);
                res.push_back(j + 1); // 第一次翻转，把元素放到首位
            }
            reverse(A.begin(), A.begin() + i + 1); // 把首位元素放到最后
            res.push_back(i + 1);
        }
        return res;
    }
};
// @lc code=end

