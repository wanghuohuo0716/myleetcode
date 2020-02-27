/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */
#include <string>
using namespace std;
// 因为数字太大后相乘，无法使用atoi()函数，atoll也不行，一定会溢出，而下面是每位数字相乘，最大不会超过81(9*9)，不会溢出
// 使用竖行乘法计算，https://leetcode-cn.com/problems/multiply-strings/solution/c-shu-shi-cheng-fa-dai-ma-jian-ji-you-ya-yi-dong-b/

// 核心：num1[i] * num2[j]的结果，个位储存在res[i+j+1],十位(进位)储存在res[i+j]
// 去除首位0使用子串函数，nice!

// @lc code=start
class Solution{
public:
    string multiply(string num1, string num2){
        int n1 = num1.size();
        int n2 = num2.size();
        string res(n1 + n2, '0'); // num1的每位数字与num2的每位数字相乘后的结果，结果的位数不会超过n1+n2
        for (int i = n2 - 1; i >= 0; i--){ // 从个位开始计算
            for (int j = n1 - 1; j >= 0; j--){
                int temp = (res[i + j + 1] - '0') + (num1[j] - '0') * (num2[i] - '0');
                res[i + j + 1] = temp % 10 + '0'; // 当前位
                res[i + j] += temp / 10; // 前一位加上进位，res[i+j]已经初始化为'0'，加上int类型自动转化为char，所以此处不加'0'，与上面加'0'的区别在于，这里是累加，上面是赋值
            }
        }

        //去除首位'0'
        for (int i = 0; i < n1 + n2; i++){
            if (res[i] != '0')
                return res.substr(i);
        }
        return "0";
    }
};
// @lc code=end
