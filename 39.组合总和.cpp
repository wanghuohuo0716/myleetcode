/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
#include <algorithm>
using namespace std;
// 类似两数之和，只不过和是一定的，但是数字不止两个
// 思路是回溯法，算是比较经典的题目和方法了，回溯法一般是找到回溯点满足条件，可以剪枝避免无效搜索
// 回溯算法实际上一个类似枚举的搜索尝试过程，主要是在搜索尝试过程中寻找问题的解，当发现已不满足求解条件时，就“回溯”返回，尝试别的路径。
// 回溯法一般用深度遍历，DFS。实现的过程有递归结构和非递归结构
// 回溯法有个明显的缺点是会出现重复，这里先排序来避免重复搜索；也可以搜索完后去重，但是会慢一些。
// 还比较有意思的一点是记录路径的代码实现：path.push_back()，这里插入的是值，表示路径，也可以插入索引表示路径。
// 最后把所有路径插入到结果中，res.push_back(path);

// 与78题类似，其实可以看做子集之和是否达到了target
// @lc code=start
class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res; // 储存所有可能的路径，每行都是一条path
    vector<int> path; // 储存当前的路径
public:
    void DFS(int i, int target) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        for (int j = i; j < candidates.size() && target - candidates[j] >= 0; j++) { // for循环，使得每个节点都会遍历[i, end]范围内的元素
            path.push_back(candidates[j]);
            DFS(j, target - candidates[j]); // 递归
            path.pop_back();
        }// 实际上for结束后还有个return，搜索完所有子结点后，回溯
        return;
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        DFS(0, target);

        return res;
    }

};
// @lc code=end

