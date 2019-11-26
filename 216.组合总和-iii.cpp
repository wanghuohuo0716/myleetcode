/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// 组合的题目，是有限种可能的情况，用回溯法解决
// 搜索范围的控制是采用了删除元素，在剩下元素中搜索，回溯时再把元素添加进来
// 剪枝的条件是控制选出来的元素按照从小到大排序，来避免重复
// 回溯的条件是长度和累加和相符时则添加到结果中然后回溯，注意两个条件的先后顺序，若分别满足两个条件的集合范围不同，一个是另一个的子集，则有顺序要求
// 累加和sum大于n也回溯，从两个条件入手分析回溯条件！

// @lc code=start
class Solution {
public:
    void backtrace(unordered_set<int>& candidate, vector<int>& temp, vector<vector<int> >& res, int i, int k, int sum, int n) {
        if (sum > n) return;
        if (i == k) {
            if (sum == n) {
                res.push_back(temp); // 插入后到return再回溯
            }
            return;
        }
        vector<int> v(candidate.begin(), candidate.end());
        for (auto x : v) {
            if (!temp.empty() && x < temp.back()) continue; // 出现重复的情况，正常case是从小到大排列，如果不是这个顺序，就会和前面的case重复
            candidate.erase(x);
            temp.push_back(x);
            backtrace(candidate, temp, res, i + 1, k, sum + x, n);
            candidate.insert(x);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        vector<vector<int> > res;
        unordered_set<int> candidate{1, 2, 3, 4, 5, 6, 7, 8, 9};
        backtrace(candidate, temp, res, 0, k, 0, n);
        return res;
    }
};
// @lc code=end

