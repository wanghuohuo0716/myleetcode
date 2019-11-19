/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
// @lc code=start
class Solution{
private:
    set<vector<int>> res;
    vector<int> temp;

public:
    void dfs(int i, vector<int> &nums){
        if (temp.size() == nums.size()){
            res.insert(temp);
            return;
        }
        res.insert(temp);
        for (int j = i; j < nums.size(); j++){
            if (j != i && nums[i] == nums[j])
                continue;
            temp.push_back(nums[j]);
            dfs(j + 1, nums);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int> &nums){
        sort(nums.begin(), nums.end());
        dfs(0, nums);
        return vector<vector<int>>(res.begin(), res.end());
    }
};
// @lc code=end
