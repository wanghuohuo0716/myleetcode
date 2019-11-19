/*
 * @lc app=leetcode.cn id=532 lang=cpp
 *
 * [532] 数组中的K-diff数对
 */
#include <vector>
using namespace std;
// 双指针法，得先排序，排序能避免很多数字重复导致的问题。复杂度是O（n^2）
// 或者排序后，进行二分查找

// @lc code=start
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int sum=0;
        sort(nums.begin(),nums.end()); //排序避免了重复数字带来的影响，检测到k-diff后就可以直接跳出循环了
        for(int i=0;i<nums.size();++i){
            if((i!=0&&nums[i]!=nums[i-1])||(i==0)){ // 重复的数字不查了
            for(int j=i+1;j<nums.size();++j){
                if((nums[j]-nums[i])>k)
                    break;
                else if((nums[j]-nums[i])==k){
                    ++sum;
                    break;
                }
              }
            }
        }
        return sum;
    }
    //排序后，进行二分查找
    // sort(nums.begin(),nums.end());
    // int n=nums.size();
    // int ans=0;
    // for(int i=0;i<n;++i)
    // {
    //     if(i!=0&&nums[i]==nums[i-1])
    //         continue;
    //     auto it=lower_bound(nums.begin()+i+1,nums.end(),k+nums[i]);//采用lower_bound()函数查找第一个大于等于k+nums[i]的数，如果没找到，说明右侧最大值小于k+nums[i]，此时可直接结束遍历，返回结果。如果找到，判断找到的结果是否是k+nums[i]，如果是，则计数加1
    //     if(it==nums.end())//查找失败,说明此刻数组中最大值比nums[i]+k小，因此无需再进行查找
    //         break;
    //     if(*it==k+nums[i])
    //         ++ans;
    // }
    // return ans;
};
// @lc code=end

