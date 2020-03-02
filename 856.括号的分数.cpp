/*
 * @lc app=leetcode.cn id=856 lang=cpp
 *
 * [856] 括号的分数
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
// 括号的匹配问题，很容易想到利用栈来解决
// 把左括号压入栈，右括号进行匹配，根据左括号在栈中的位置进行不同的操作
// 1.左括号在栈顶，即形成了()，得一分
// 2.左括号不在栈顶，即形成了(ABC)，得2*(A+B+C)分

// 等所有的元素处理完后，栈中有两种情况1.是栈底是左括号，则跟2一样处理，栈底是A，则A+B
// 栈中既有左括号又有数值，可以考虑用0代替左括号，则栈中元素数据类型相同

// 核心：栈中的元素是分值，同时也有左括号，分值也可以认为代表括号

// @lc code=start
class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        for(char c:S){
            if(c=='('){     //遇到左括号入栈，用0模拟
                s.push(0);
            }
            else{       //遇到右括号进行判断
                if(s.top()==0){ //栈顶为0即栈顶为左括号，此时为()的情况，得1分
                    s.pop();
                    s.push(1);
                }
                else{  //栈顶不为左括号即为(ABC)的情况，得分为(A+B+C)*2
                    int inScore=0;
                    while(s.top()!=0){ // 找到左括号的位置
                        inScore+=s.top();
                        s.pop();
                    }
                    s.pop();
                    s.push(inScore*2);
                }
            }
        }
        int score=0;
        while(!s.empty()){      //最后栈内都是分数，没有括号了，求和即可
            score+=s.top();
            s.pop();
        }
        return score;
    }
};
// @lc code=end

