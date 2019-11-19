/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution{
public:
    vector<vector<int>> subsets(vector<int> &nums){
        vector<vector<int>> res;
        vector<int> tmp;
        DFS(res, tmp, nums, 0);
        return res;
    }
    void DFS(vector<vector<int>> &res, vector<int> tmp, vector<int> &nums, int i){
        if (tmp.size() <= nums.size()){
            res.push_back(tmp);
        }
        for (int j = i; j < nums.size(); j++){
            tmp.push_back(nums[j]);
            DFS(res, tmp, nums, j + 1);
            tmp.pop_back();
        }
    }
};
// @lc code=end
