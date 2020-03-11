/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */
#include <vector>
using namespace std;
// 理解题意：要求繁对同一个数组进行求区域和操作，数组不变，所以可以使用前缀和
// 如果数组是变化的就没有意义了，必须要用暴力法
// 前缀和的计算其实也是动态规划的思想

// tip：前缀和的计算中，在数组首位插入0，避免了数组出现-1的索引

// @lc code=start
class NumArray {
public:
    NumArray(vector<int> &nums) {
        accu.push_back(0);
        for (int num : nums)
            accu.push_back(accu.back() + num);
    }

    int sumRange(int i, int j) {
        return accu[j + 1] - accu[i];
    }
private:
    vector<int> accu;
};


/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
// @lc code=end

