/*
 * @lc app=leetcode.cn id=565 lang=cpp
 *
 * [565] 数组嵌套
 */
#include <vector>
#include <algorithm>
using namespace std;
// 难点在于理解题目，递推的思想很简单，终止的条件是出现重复元素，因此使用vis数组记录是否被访问过
// 最简单的方法是迭代给定 nums 数组的所有索引。对于选择的每个索引 i，我们找到元素 nums[i] 并为当前索引 i 添加的新元素增加 count。
// 由于 nums[i] 必须作为新索引来查找属于与索引 i 对应的集合的下一个元素，因此新索引是 j = nums [i]

// @lc code=start
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int ret = 0;
        int cnt = 0;
        vector<bool> vis(nums.size(),0);
        for(int i = 0;i<nums.size()&&(nums.size()-cnt)>ret;++i){
            int len = 0;
            int c = i;
            while(vis[c]==false){
                len++;
                vis[c] = true;
                cnt++;
                c = nums[c];
            }
            ret = max(ret,len);
        }
        return ret;
    }
};
// @lc code=end