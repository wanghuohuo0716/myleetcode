/*
 * @lc app=leetcode.cn id=1003 lang=cpp
 *
 * [1003] 检查替换后的词是否有效
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
// 理解题意比较难
// 所有的有效字符串都是由abc生成的，只是生成的方法不同
// V=X+abc+Y，相当于是插入了abc字符串，那么把abc剔除后的单词，再剔除abc，直到没有abc，看看最后的单词是不是abc(其实最后一个单词abc也可以剔除，结果就是空的)
// 使用栈作为数据结构，遇到连续的abc就弹出，当栈为空栈时就是true

// 细节：当栈中元素不足两个时，需要先插入再比较，大于2个时，需要先比较再决定是插入还是消掉abc

// @lc code=start
class Solution {
public:
    bool isValid(string S) {
        int count[3] = {0};
        int len = S.length();
        if (len % 3) // 所有的单词都是abc生成的
            return false;
        stack<char> mstack;
        char pre, prepre;
        for (int i = 0; i < len; ++i) { // 遍历单词的所有字母
            if (mstack.size() >= 2) { // 初始化的时候需要先插入两个再比较(在过程种如果栈中数目小于2个也是需要先插入的)，后面栈中的个数大于3个，就需要先比较再决定是插入还是消掉abc
                pre = mstack.top(); // 没法直接索引栈顶下面那个元素，必须要先弹出栈顶元素才能索引下一个元素
                mstack.pop();
                prepre = mstack.top();
                if (prepre == 'a' && pre == 'b' && S[i] == 'c') {
                    mstack.pop();
                    continue;
                }
                mstack.push(pre);
                mstack.push(S[i]);
            }
            else
                mstack.push(S[i]);
        }
        return mstack.empty();
    }
};
// @lc code=end

