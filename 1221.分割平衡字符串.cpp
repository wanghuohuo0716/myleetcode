/*
 * @lc app=leetcode.cn id=1221 lang=cpp
 *
 * [1221] 分割平衡字符串
 */
#include <string>
using namespace std;
// 计算某个字符的连续数量，然后当寻找到另一个字符的数量对应相同时，就确定了一个分割点。这样找到的每个平衡串都是最小平衡串
// tip:要L和R的次数相同，就对一个变量使用加减操作，当变量为0时，就次数相同了！！

// @lc code=start
class Solution {
public:
    int balancedStringSplit(string s) {
    int n= s.size() ;

    int counter = 0;
    int res = 0;

    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'R'){
            counter++;
        }
        else{
            counter--;
        }

        if(counter == 0){
            res++;
        }
    }

    return res;
    }
};
// @lc code=end

