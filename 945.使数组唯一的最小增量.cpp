/*
 * @lc app=leetcode.cn id=945 lang=cpp
 *
 * [945] 使数组唯一的最小增量
 */
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
// 排序把重复元素放到一起，遍历，设置个变量维护前一个元素的值作为A[i]的比较对象，然后计算累加次数

// @lc code=start
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size()<2) return 0;
        sort(A.begin(), A.end());
        int last = A[0], ret = 0;
        for(int i = 1; i < A.size(); ++i){
            if(A[i] <= last){
                ret += last - A[i] +1;  // 将A[i]调整为last+1所需次数
                last ++;
            }
            else
                last = A[i];
        }
        return ret;
    }
};
// @lc code=end

