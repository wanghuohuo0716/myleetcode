/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
// 在栈中插入的是操作数，根据操作符处理下一个操作数，把处理的结果压入栈中，最后对栈的所有结果继续累加就是最终结果！！！
// 采用栈的数据结构更方便操作

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n=s.size(), num=0, res =0;
        char op='+';
        for(int i=0;i<n;++i){
            if(s[i]>='0')
                num=num*10+(s[i]-'0');
            if((s[i]<'0'&& s[i]!=' ')|| i==n-1){ // 筛选操作符
                if(op=='+') st.push(num);
                if(op=='-') st.push(-num);
                if(op=='*'||op=='/'){
                    int temp = (op=='*') ? st.top()*num : st.top()/num;
                    st.pop();
                    st.push(temp);
                }
                op=s[i];
                num=0;
            }
        }
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        return res;
    }
};
// @lc code=end

