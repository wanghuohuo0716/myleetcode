/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] 复数乘法
 */
#include <string>
#include <vector>
#include <sstream>
using namespace std;
// 思路很清晰，分割出实部和虚部，然后计算新的虚数的实部和虚部，然后拼出虚数
// 难点是如何快速分割，同样是使用getline函数和sstream来处理

// 去掉末尾的字符i有两种方法，使用erase()或substr()函数

// @lc code=start
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        // 切割出实部和虚部
        vector<string> as;
        stringstream ss(a);
        string tmp;
        while (getline(ss, tmp, '+'))
            as.push_back(tmp);
        as[1].erase(as[1].end() - 1); // 去掉字符i，a[1]是虚部字符串，如"1i"，a[1].end()-1是字符i的迭代器
        // as[1] = as[1].substr(0, as[1].length() - 1); 另一种代码去掉末尾的字符i

        vector<string> bs;
        stringstream ss2(b);
        while (getline(ss2, tmp, '+'))
            bs.push_back(tmp);
        bs[1].erase(bs[1].end() - 1);

        // 转成int然后计算
        int a_real = stoi(as[0]);
        int a_img = stoi(as[1]);
        int b_real = stoi(bs[0]);
        int b_img = stoi(bs[1]);

        // 数学公式
        return to_string(a_real * b_real - a_img * b_img) + "+" + to_string(a_real * b_img + a_img * b_real) +"i";

    }
};
// @lc code=end

