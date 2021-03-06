/*
 * @lc app=leetcode.cn id=962 lang=cpp
 *
 * [962] 最大宽度坡
 */
#include <vector>
#include <stack>
using namespace std;
// 使用单调栈的思想，还是不是很理解，但是这个算法思想好像挺重要的
// 单调栈其实就是栈内元素以单调递增或单调递减进行存放,存放的是元素的序号index不是元素
// 单调栈可以解决的问题：
// 1.求解数组中元素右边第一个比它小的元素的下标，从前往后，构造单调递增栈；
// 2.求解数组中元素右边第一个比它大的元素的下标，从前往后，构造单调递减栈；
// 3.求解数组中元素左边第一个比它小的元素的下标，从后往前，构造单调递减栈；
// 4.求解数组中元素左边第一个比它小的元素的下标，从后往前，构造单调递增栈。
// 这里的“左边第一个元素”是指从当前元素出发，向左移动；不是指从数组的起始位置想当前元素移动

// 单调栈求解由两个部分组成，一个是初始化单调栈的过程，一个是利用单调栈计算的过程。
// 1.初始化单调栈
// 初始化过程即从序列中找到一个单调递减的子序列，比如在[6,0,8,2,1,5]中从初始位置开始的单调递减序列就是[6,0]（不连续是可以的），单调栈中把序号记录下来即[0,1]。

// 2.单调栈计算
// 计算过程很简单，从后往前遍历，当元素比栈顶序号的元素大（或等于）时，就计算栈顶的序号（并弹出）和位置i的差值，因为我们要找到最大的两者之差（即宽度）。


// @lc code=start
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> s;
        int res = 0;
        int n = A.size();

        s.push(0);
        for (int i = 1; i < n; i++) { // 构造单调递减栈
            if (A[s.top()] > A[i])
                s.push(i);
        }

        for (int i = n - 1; i >= res; i--) { // 从后往前遍历
            while (A[s.top()] <= A[i]){
                res = max(res, i - s.top());
                s.pop();
                if(s.empty())return res;
            }
        }

        return res;
    }
};
// @lc code=end

