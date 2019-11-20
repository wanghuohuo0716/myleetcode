/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <vector>
#include <algorithm>
using namespace std;
// 这个问题为解决这类问题提供了一种方法，其实排序方法才是效果最好的，实际使用中肯定是用排序算法
// 其主要思想是给每个数字设定一种颜色，并按照指定的顺序进行调整，使用排序算法直接进行分类。
// 使用整数 0、 1 和 2 分别表示红色、白色和蓝色，然后排序。

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
    // 对于所有 idx < p0 : nums[idx < p0] = 0
    // curr 是当前考虑元素的下标
    int p0 = 0, curr = 0;
    // 对于所有 idx > p2 : nums[idx > p2] = 2
    int p2 = nums.size() - 1;

    while (curr <= p2) {
        if (nums[curr] == 0) {
            swap(nums[curr++], nums[p0++]);
        }
        else if (nums[curr] == 2) {
            swap(nums[curr], nums[p2--]);
        }
        else
            curr++;
    }
    }
};
// @lc code=end

