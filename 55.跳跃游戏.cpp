/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <vector>
#include <algorithm>
using namespace std;
// 如果某一个作为 起跳点 的格子可以跳跃的距离是 3，那么表示后面 3 个格子都可以作为 起跳点。
// 可以对每一个能作为 起跳点 的格子都尝试跳一次，把 能跳到最远的距离 不断更新。
// 如果可以一直跳到最后，就成功了。

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
	int k = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		if (i > k) return false;
		k = max(k, i + nums[i]);
        if(k>=nums.size()-1)
            return true;
    }
	return true;
    }
};
// @lc code=end

