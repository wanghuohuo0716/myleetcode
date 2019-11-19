/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>
#include <algorithm>
using namespace std;
// 题意是查找一个元素在数组中的上下边界。
// 要求时间复杂度是O(logn)，则一定是二分查找，线性查找的苏咋读是O(n)
// C++其实内置了左边界和右边界的查找函数，lower_bound()和upper_bound()函数
// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/solution/er-fen-cha-zhao-suan-fa-xi-jie-xiang-jie-by-labula/
// 二分查找思想很简单，但是实现很tricky。code解决的思想是while引出的搜索区间概念。
// 如果是while (left < right)，则左闭右开，当left=right时，跳出循环，此时需要检测nums[left]是否为target，while中没有检测
// while (left <= right)则两边都是闭区间搜索，当left>right时，跳出循环，此时不需要检测nums[left]是否为target，while中有检测
// 建议采用right=nums.size();while(left<right)这种模板，比right=nums.size()-1;while(left<=right)这种模板更泛化。
// 这种模板要注意1.要单独检查nums[left]的值是否是target 2.检查跳出循环时，索引left(right)是否会越界!

// @lc code=start
class Solution{
    public:
    vector<int> searchRange(vector<int> &nums, int target){
        vector<int> res(2, -1);  // [-1, -1]不是[2, -1]! 第一个参数是数组元素的数目，第二个参数是初始化的值
        if (nums.empty())
            return res;
        int n = nums.size(), left = 0, right = n - 1;
        // 缩小右边界，找左边界
        while (left < right){
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                right = mid; // 右边界左移
            else if (nums[mid] > target)
                right = mid;
            else if (nums[mid] < target)
                left = mid + 1;
        }
        if (nums[left] != target)
            return res;
        res[0] = left;

        right = n; // 接着上次搜到的左边界left开始往右边界搜索，如果 right = n-1，还需要单独判断nums[right]是否为target
        // 缩小左边界，找右边界
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                left = mid + 1; // 左边界右移
            else if (nums[mid] > target)
                right = mid;
            else if (nums[mid] < target)
                left = mid + 1;
        }
        // if (nums[right]!=target)
            res[1] = left - 1; //因为left-1的存在，所以最后不用判断left是否会越界。
        // else
        //     res[1] = right;
        return res; // 因为前面已经找到了一个left，所以也不用判断是否存在target
    }
};
// @lc code=end
