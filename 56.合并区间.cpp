/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <vector>
#include <algorithm>
using namespace std;
// 倾向于用空间换时间，思路容易理解，符合数学思维。
// 首先排序，保证了左边界顺序从小到大，排序是基础
// 设定一个res保存结果，res最后一个区间右边界大于原数组的左边界则需要选择更大的右边界

// 程序是数据结构+算法，这里思考程序的时候，如何选择res的数据结构是个值得思考的问题，选择数据结构的时候，算法有时候也相应的确定了

// @lc code=start
class Solution{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals){
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]); // 插入第一个区间，不是数是区间！
        for (int i = 1; i < intervals.size(); ++i){
            if (res.back()[1] >= intervals[i][0]){ //如果存在重叠区域
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end
