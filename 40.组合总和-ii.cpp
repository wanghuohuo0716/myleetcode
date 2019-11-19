/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// “解集不能包含重复的组合”，就暗示我们得对数组先排个序（“升序”或者“降序”均可，下面示例中均使用“升序”）。
// 相比于39题，区别在于数组元素只能使用一次，代码的区别在于下一层递归的起始索引不一样，变成了i+1。
// 如何去掉一个数组中重复的元素，可以先对数组升序排序,候选数组有序，对于在递归树中发现重复分支，进而“剪枝”是十分有效的。
//


// @lc code=start
class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> path;
public:
    void DFS(int i, int target) {//i的值为j+1
        if (target == 0) {
            res.push_back(path);
            return;
        }

        for (int j = i; j < candidates.size() && target - candidates[j] >= 0; j++) {
            if (j > i && candidates[j] == candidates[j - 1]) // 去重剪枝
                continue;
            path.push_back(candidates[j]);
            // 元素不可重复利用，使用下一个即i+1，把j+1赋值给i
            DFS(j + 1, target - candidates[j]); //
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);
        return res;
    }
};
// @lc code=end

