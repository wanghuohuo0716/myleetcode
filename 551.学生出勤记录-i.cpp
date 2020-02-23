/*
 * @lc app=leetcode.cn id=551 lang=cpp
 *
 * [551] 学生出勤记录 I
 */
#include <string>
using namespace std;
// 单独统计A的次数，检测是否有三个连续的L的flag存在
// 连续三个检测时，为避免数组越界，通过扩大原数组的元素数目来避免数组越界

// @lc code=start
class Solution {
public:
    bool checkRecord(string s) {
        s.insert(s.begin(),'P'); // 通过扩大原数组的元素数目来避免数组越界
        s.push_back('P');
        int n = s.size();
        int A_num = 0;
        int P_tag = 0;
        for(int i = 1; i < n - 1; ++i)
        {
            if(s[i] == 'A')
                A_num++;
            if(s[i] == 'L' && s[i - 1] == 'L' && s[i + 1] == 'L')
                P_tag = 1;
        }
        return (A_num <= 1 && P_tag == 0) ? true : false;
    }
};
// @lc code=end

