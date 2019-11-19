/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */
#include <vector>
#include <algorithm>
using namespace std;
// 和三数之和解法完全相同，最后都是递归简化到两数之和解法，复杂度为O(n^3)

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > res;
        if(nums.size()<4)
            return res;
        int a, b, c, d, n = nums.size();
        for (a = 0; a <= n - 4; a++){
            if (a > 0 && nums[a] == nums[a - 1])
                continue; //确保nums[a] 改变了
            for (b = a + 1; b <= n - 3; b++){
                if (b > a + 1 && nums[b] == nums[b - 1])
                    continue; //确保nums[b] 改变了
                c = b + 1, d = n - 1;
                while (c < d){
                    if (nums[a] + nums[b] + nums[c] + nums[d] < target)
                        c++;
                    else if (nums[a] + nums[b] + nums[c] + nums[d] > target)
                        d--;
        			else{
                        res.push_back({nums[a], nums[b], nums[c], nums[d]});
                        while (c < d && nums[c + 1] == nums[c]) c++; //确保nums[c] 改变了
                        while (c < d && nums[d - 1] == nums[d]) d--; //确保nums[d] 改变了
        				c++; //当nums[c+1]!=当nums[c]时，此时的c才是我们需要的
        				d--;
					}
				} //c和d，双指针
			} //b
		} //a
		return res;
    }
};
// @lc code=end

