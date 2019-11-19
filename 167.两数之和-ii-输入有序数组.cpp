/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */
#include <vector>
#include <iostream>
using namespace std;

//我们可以使用 两数之和 的解法在 O(n^2)时间O(1)空间暴力解决。
//然而，这种方法都没有用到输入数组已经排序的性质，我们可以做得更好。

//我们使用两个指针，初始分别位于第一个元素和最后一个元素位置，比较这两个元素之和与目标值的大小。
//如果和等于目标值，我们发现了这个唯一解。如果比目标值小，我们将较小元素指针增加一。
//如果比目标值大，我们将较大指针减小一。移动指针后重复上述比较知道找到答案。

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
                return {low + 1, high + 1};
            else if (sum < target)
                ++low;
            else
                --high;
        }
        return {-1, -1};
    }
};
// @lc code=end

