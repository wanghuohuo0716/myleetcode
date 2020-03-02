/*
 * @lc app=leetcode.cn id=553 lang=cpp
 *
 * [553] 最优除法
 */
#include <string>
#include <vector>
#include <sstream>
using namespace std;
// 脑筋急转弯：要使得结果最大，则被除数最大，除数最小。而对于一个长度固定的序列. [a,b,c,d,e] 它的式子为 a / b / c / d / e，所以被除数一定是第一个数a，除数是剩下所有的字符做除法结果，这个结果才是最小b / c / d / e
// 但其实也可以用动态规划的方法做，只是会非常复杂

// @lc code=start
class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string a = to_string(nums[0]);
        if(nums.size() == 1) return a;
        a = a + "/";
        string b = "";
        for(int i = 1 ; i < nums.size() ;++i){
            if(i != 1)
                b = b + "/";
            b = b + to_string(nums[i]);
        }
        if(nums.size() == 2)
            a = a + b; // 字符串相加，不是数字相加
        else
            a = a + "(" + b + ")";
        return a;
    }
};
// @lc code=end

