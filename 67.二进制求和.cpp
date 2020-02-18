/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */
#include <string>
using namespace std;
// 核心算法有两个：1.二进制字符串转换为十进制数，十进制数相加后得到整数，2.整数转换为二进制字符串
// 可以看下最下面的两个转换函数，C++没有内置的这种函数
// C++有to_string内置函数，把整数转换为字符串，例如，32转换为“32”

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int al = a.size();
        int bl = b.size();
        while(al < bl) //让两个字符串等长，若不等长，在短的字符串前补零，否则之后的操作会超出索引
        {
            a = '0' + a;
            ++ al;
        }
        while(al > bl)
        {
            b = '0' + b;
            ++ bl;
        }
        for(int j = a.size() - 1; j > 0; -- j) //从后到前遍历所有的位数，同位相加
        {
            a[j] = a[j] - '0' + b[j];
            if(a[j] >=  '2') //若大于等于字符‘2’，需要进一
            {
                a[j] = (a[j] - '0') % 2 + '0';
                a[j-1] = a[j-1] + 1;
            }
        }
        a[0] = a[0] - '0' + b[0]; //将ab的第0位相加
        if(a[0] >= '2') //若大于等于2，需要进一
        {
            a[0] = (a[0] - '0') % 2 + '0';
            a = '1' + a;
        }
        return a;
    }
};
// @lc code=end

// 输入整数int，输出二进制字符串string
string IntToBin(int val)
{
    string str;
    for (int i = 16; i >= 0; i--) //int是16位，这里不同的位数还需要修改数字16
    {
        if (val & (1 << i))//&按位计算
            str += "1"; // 如果是push_back函数，不能是双引号，必须是单引号
        else
            str += "0";
    }
    return str;
}

// 输入字符串string，输出整数int
int BinToInt(string str)
{
    int n = 0;
    for (int i = 0; i < str.size(); i++)
    {
        n = n * 2 + (str[i] - '0');
    }
    return (int)n;
}
