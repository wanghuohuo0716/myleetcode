/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
* [189] 旋转数组
 */
#include <vector>
using namespace std;
// 反转的思路很容易理解，因为数组的顺序是保持不变的！
// 原始数组                  : 1 2 3 4 5 6 7
// 反转所有数字后             : 7 6 5 4 3 2 1
// 反转前 k 个数字后          : 5 6 7 4 3 2 1
// 反转后 n-k 个数字后        : 5 6 7 1 2 3 4 --> 结果

// 时间复杂度：O(n)。 n个元素被反转了总共 3 次。
// 空间复杂度：O(1)。 没有使用额外的空间。
// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 暴力法会超出时间限制，复杂度为O(n*k)
        // int temp, previous;
        // for (int i = 0; i < k; i++) {
        //     previous = nums[nums.size() - 1];
        //     for (int j = 0; j < nums.size(); j++) {
        //         temp = nums[j];
        //         nums[j] = previous;
        //         previous = temp;
        //     }
        // }
        k %= nums.size(); //如果k超过了数组长度，必须得用取余计算
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }
    void reverse(vector<int>& nums2, int start, int end) {
        while (start < end)
        {
            int temp = nums2[start];
            nums2[start] = nums2[end];
            nums2[end] = temp;
            start++;
            end--;
        }
    }
};
// @lc code=end

