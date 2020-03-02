/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 */
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
// 要找到所有的组合，很自然想到回溯法
// 整体的结构其实还是斐波那契递归的思想，核心在于如何从数字串中构造出数
// 回溯进行时，需要用到维护的变量是斐波拉契的前两个数
// 回溯的时候，是每次只更新一个数。更新一个数，比较两个数！！

// 分割数字的方法：下一个数字是该数字串的所有可能结果，只考虑构成一个数，第一位开始，遍历所有位的数，形成的数字，比如1123就有，1,11,112，1123四种可能。
// start变量是来控制位数

// @lc code=start
class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> res;
        bool result = helper(S, 0, -1, -1, res);
        if (result)
            return res;
        else
            return {};
    }

    bool helper(string s, int start, int val1, int val2, vector<int> &res) {
        int size = res.size();
        if (start == s.length() && size >= 3)
            return true;
        long long targetVal = (long long)val1 + val2;

        if (targetVal > INT_MAX || start > s.length() * size / max(size +1 ,3) +1) // 这里可以进行strat的剪枝
                return false;
        for (int i = 1; i < s.length() - start + 1; i++) {
            string subStr = s.substr(start, i); // 构造下一个新数的方法，以start为起点，i为终点构造新数，判断这个数是否为斐波拉契数
            long long val = stoll(subStr);
            if (val > INT_MAX)
                return false;
            if (subStr.length() > 1 && val < 10) // '01'，数字以0开头不符合要求
                return false;
            if (val1 == -1 || val2 == -1 || val == targetVal) { // 初始化和满足斐波拉契规律的，插入结果中
                res.push_back((int)val);
                bool result = helper(s, start + i, val2, (int)val, res); // val2变成了val1，val变成了val2，往后延伸构造斐波拉契数列
                if (!result)
                    res.pop_back(); // 回溯了，不满足要求
                else
                    return true;
            }
            else if (val > val1 + val2) // 不满足斐波拉契规则
                return false;
        }
        return false;
    }
};
// @lc code=end

