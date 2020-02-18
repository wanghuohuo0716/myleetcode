/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <string>
#include <stack>
using namespace std;
// 简单的计数器来统计各个种类括号数量是否为偶数是不行的，还要考虑括号的相对位置，比如({)}这种类型就不行
// 难点在于如何处理这种相对位置
// 在每一个括号逐一形成有效括号时，存在递归的结构，可以考虑使用栈来来处理，把开括号压入栈中，有闭括号就弹出相应的开括号，最后栈为空则有效

// 在入栈之前，先对边界条件进行限制，把空串和奇数个串都排除掉，不进循环
// 当括号被压进去前，与栈顶端字符进行比较，如果匹配，就把栈顶端字符弹出栈，不匹配，就把字符压入栈

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
       stack<char> sta;
       int len = s.size();
       if(!len) return true;
       if(len%2==1) return false;//先把边界条件写好
       for(int i=0;i<len;++i){
           if (sta.empty()){ // 当栈为空的时候sta.top()索引时会造成数组越界，所以需要加一个stack是否为空的判断
               sta.push(s[i]);
               continue;
            }
            if(sta.top()=='('&&s[i]==')'){
                sta.pop();
                continue;
            }
            if(sta.top()=='['&&s[i]==']'){
                sta.pop();
                continue;
            }
            if(sta.top()=='{'&&s[i]=='}'){
                sta.pop();
                continue;
            }
            sta.push(s[i]);
       }
       return sta.empty();
    }
};
// @lc code=end

