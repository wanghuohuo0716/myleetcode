/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#include <vector>
#include <unordered_set>
using namespace std;
// 思路是先把乱序的数排列好，在数组元素比较特殊的情况下（1≤a[i]≤n) n为数组长度，数组元素为整数，同一个元素最多重复2次），排序的时间复杂度是O（n)
// 排序好后，在比较索引与元素关系，不符合的就知道了缺少的数字

// 核心是特殊元素的排序!!!
// 理论是抽屉理论或者鸽巢理论，一个萝卜一个坑
// @lc code=start
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int index = 0;
        while(index < nums.size())
        {
            // 从坑位（索引）的角度考虑，当前数nums[index]不属于当前坑位index+1，并且目标坑位nums[index]-1还没被占据，即目标坑位的元素也是不符合规律的
            if(nums[index] != (index+1) && nums[nums[index]-1] != nums[index])
            {
                // 这个位置不属于当前index指向的元素，把index指向的元素调到它应该属于的位置
                int swapIndex = nums[index] - 1;
                int temp = nums[index];
                nums[index] = nums[swapIndex];
                nums[swapIndex] = temp;
            }else
            {
                index++; //遍历所有的元素
            }
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
// @lc code=end

