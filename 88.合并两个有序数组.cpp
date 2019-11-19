/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    // two get pointers for nums1 and nums2
    int p1 = m - 1;
    int p2 = n - 1;
    // set pointer for nums1
    int p = m + n - 1;

    // while there are still elements to compare
    while ((p1 >= 0) && (p2 >= 0))
    {
        // compare two elements from nums1 and nums2
        // and add the largest one in nums1
        nums1[p--] = (nums1[p1] < nums2[p2]) ? nums2[p2--] : nums1[p1--];
    }
    // 如果nums1的有序数字用完了，剩下的nums2还需要继续往里面塞
    while(p2 >=0)
    {
        nums1[p--] = nums2[p2--];
    }

    }
};
// @lc code=end

