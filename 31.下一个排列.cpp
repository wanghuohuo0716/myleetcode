/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include <vector>
#include <algorithm>
using namespace std;
// 首先这道题理解题意是一道坎。
// 下一个排列的题意理解：给定一个整数数组，[9,8,7,4,6,5,3,2,1]，有多种排列组合，如123456789是最小的数，987654321是最大的数。
// 而当前数组的排列组合是987465321，找一个比这个数大的所有数中最小的那个数即987512346

// 帮助理解解答思路，https://leetcode-cn.com/problems/next-permutation/solution/xia-yi-ge-pai-lie-by-leetcode/

// 根据结果可知，找到这个数的方法分为三步：
// 1.从右边找到两个连续的数字 a[i-1] 和 a[i]，它们满足 a[i-1]<a[i]
// 2.把i到最后的数按升序排列
// 3.把nums[i-1]和后面的升序序列中比它大的数中最小的那个数交换即可（并不是i与i-1交换就能得到最小的数）
// 举例：987465321->987412356->987512346

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // STL中有寻找下一个排列的函数，一行搞定
        // next_permutation(nums.begin(),nums.end());

        // 找到转折点，然后反转，找到最近一个值进行交换
        if (nums.size() > 1) {
            int i,anchor;
            for (i = nums.size() - 1; i > 0 && nums[i - 1] >= nums[i]; i--);
            anchor = i - 1; //如果i=0则出bug了
            if (anchor==-1){
                sort(nums.begin(), nums.end());
                return;
            }

            reverse(nums.begin() + i, nums.end());

            for (; i < nums.size(); i++){
                if (nums[i] > nums[anchor]){
                    swap(nums[i], nums[anchor]);
                    return;
                }
            }
        }
    }
};
// @lc code=end

