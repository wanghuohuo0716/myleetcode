/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */
#include <vector>
#include <algorithm>
using namespace std;
// 组合题目，可以使用回溯法解决，但是会超时
// 利用快速排序，计算较小的两个数，判断第三个数是否满足要求，类似3sum。固定第一条边，每选择一个第二条边，都可以计算出存在m个三角形，三层循环

// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        if(nums.size()<3)
            return 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int k = i + 2;
            for (int j = i + 1; j < nums.size() - 1 && nums[i] != 0; j++) {
                while (k < nums.size() && nums[i] + nums[j] > nums[k])
                    k++;
                count += k - j - 1;
            }
        }
        return count;
    }
};
// @lc code=end
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        vector<int> tri;
        int cnt = 0;
        dfs(nums,tri,cnt,0);
        return cnt;
    }
    void dfs(vector<int>& nums,vector<int>& tri,int&cnt,int start){
        if(tri.size()==3){
            if(judgeTriangle(tri))
                cnt++;
            return;
        }
        for(int i=start;i<nums.size();i++){
            tri.push_back(nums[i]);
            dfs(nums,tri,cnt,i+1);
            tri.pop_back();
        }
    }
    bool judgeTriangle(vector<int> & tri){
        int a = tri[0],b = tri[1],c = tri[2];
        if(a<=0||b<=0||c<=0)
            return false;
        if(a+b>c && a+c>b && b+c>a)
            return true;
        return false;
    }
};
