/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 */
#include <string>
#include <algorithm>
using namespace std;
// 其实这个“除尽”要求是很严格的，S中只包含T子串，str1和str2同时除尽X，str1=N*X，str2=M*X，则str1+str2=(N+M)*X,str1+str2=str2+str1
// 不会出现str2中的X从str[1]开始算，因为会多出来一个str[0],无法形成X，不符合除尽的要求
// gcd算法是求a，b两个数的最大公约数算法，辗转相除法

// @lc code=start
class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if((str1 + str2) != (str2 + str1)) return "";
        int res = gcd(str1.size(), str2.size());
        return str1.substr(0, res);
    }

    int gcd(int a, int b) // 辗转相除法求最大公约数
    {
        while(a != 0 && b != 0)
        {
            a = a % b;
            if(a == 0)
                break;
            swap(a,b);
        }
        return b;
    }
};

// @lc code=end

