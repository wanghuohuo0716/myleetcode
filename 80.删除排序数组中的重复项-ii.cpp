/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// 指定了原地删除肯定是双指针法，而且双指针法一般都事先排序了，一个指向遍历的元素，一个指向可以写入的位置，后者的大小是小于等
// current为写入的位置，i为遍历的位置，当i处元素与current-1处的元素不同时，则可以写入，否则不能
// 为什么i处元素与current-1处的元素不同时，则可以写入？这要分析可以写入的条件了。
// i不能加入到current的情况是：i和current还有current-1处的值都相等 能加入的情况是:i和current的值相等并且i和current-1的值不相等、i和current还有current-1的值都不相等 还有一种情况是不可能出现的情况 ：i和current的值不相等并且i和current-1的值相等 这种情况是不可能出现的 所以可以用i和current-1的值是否相等来判定是否写入的操作

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
	if (nums.size() <= 1)
		return nums.size();
	int current = 1;           //新数组中有效位置的最后一位，新加入的数据应当写到current+1
	for (int i = 2; i < nums.size();i++){ //从第三位开始循环，前两位无论如何都是要加入新数组的
		if (nums[i] != nums[current - 1]){  //符合条件，加入新数组
			current += 1;
			nums[current] = nums[i];
		}
	}
	return current+1;
    }
};
// @lc code=end

