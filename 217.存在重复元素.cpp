/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <vector>
#include <unordered_map>
using namespace std;

// 有unordered_set可以直接去掉重复数据，C++ 利用set不允许两个元素有相同键值这一特性
// 此题方法有两种（哈希表，排序），如果用排序的话推荐大家自己手写一下快排等其他排序方法。
// 用哈希表的方式，此题一读就是一道典型的哈希映射的方式，即每个数字对应一个出现次数，
// 所有我们只需要创建一个哈希表然后每遍历一个数字就去里面找是否已经映射过了，如果映射过了（即已经添加进map中了）就返回true(因为当前数字还没有加进去，如果加进去就是至少两次了)。

//先用快速排序对数组进行排序，然后比较相邻元素是否有相同的

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // hash表
        // unordered_map<int,int> map;
        // for(int i =0; i<nums.size();i++)
        //     if(map.count(nums[i])!=NULL) return true;
        //     else map[nums[i]]+=1;
        // return false;

        // 快速排序
        if(nums.size()<=1) return false;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
};
// @lc code=end

