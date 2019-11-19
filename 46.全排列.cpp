/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
#include <algorithm>
using namespace std;
// @lc code=start
class Solution{
private:
    vector<int> temp;
    vector<int> visited; // 定义的时候无法初始化，必须在构造函数内初始化

public:
    vector<vector<int>> permute(vector<int> &nums){
        vector<vector<int>> res;
        vector<int> d(nums.size(), 0); // 初始化
        visited = d;
        backtrack(nums, res, 0);
        return res;
    }

    void backtrack(vector<int> &nums, vector<vector<int>> &res, int i){
        if (i == nums.size()){
            res.push_back(temp);
            return;
        }

        for (int j = 0; j < nums.size(); j++){
            if(!visited[j]){
                temp.push_back(nums[j]);
                visited[j] = 1;
                backtrack(nums, res, i + 1);
                temp.pop_back();
                visited[j] = 0;
            }
        }
    }
};
// @lc code=end
