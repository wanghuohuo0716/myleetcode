/*
 * @lc app=leetcode.cn id=457 lang=cpp
 *
 * [457] 环形数组循环
 */
#include <vector>
#include <algorithm>
using namespace std;
// 就是在每个位置都单独进行判断，判断走了一圈后能不能达到自己，可以则true
// @lc code=start
class Solution
{
public:
    bool circularArrayLoop(vector<int> &nums){
        vector<int> store;
        for (int i = 0; i < nums.size(); i++){
            store.clear();
            int cur = i;
            bool pos = nums[i] > 0 ? true : false;
            store.push_back(i);
            while (1){
                nums[cur] %= int(nums.size());
                auto next = ((cur + nums[cur] < nums.size()) && (cur + nums[cur] >= 0)) ? cur + nums[cur] : cur + nums[cur] - nums.size() * (pos == true ? 1 : -1);
                if ((nums[next] > 0) != pos || store.size() > nums.size())
                    break;
                if (next == i){
                    if (store.size() == 1)
                        break;
                    else
                        return true;
                }
                store.push_back(next);
                cur = next;
            }
        }
        return false;
    }
};
// @lc code=end
