/*
 * @lc app=leetcode.cn id=385 lang=cpp
 *
 * [385] 迷你语法分析器
 */
#include <string>
#include <vector>
#include <stack>
using namespace std;
// 题目看起来其实花里胡哨的，但实际上是从字符串分析出来各个数字，以及数字之间的嵌套关系
// 这种自然而然会想到用栈来处理
// 返回的是个结构体，结构体内存在嵌套关系

// 先把数字放入结构体中，在进行结构体之间的嵌套

 // This is the interface that allows for creating nested lists.
 // You should not implement it, or speculate about its implementation
class NestedInteger {
    public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};
// @lc code=start
class Solution {
public:
    NestedInteger deserialize(string s) {
    stack<NestedInteger*> stk; // 这里用stack<NestedInteger>会非常耗时，建议对结构体使用指针栈
    string numStr; // 整数字符串，用来临时保存提取的数
    for (char &c : s) {
        if (c == '[') { // 嵌套关系
            NestedInteger *res = new NestedInteger(); // 当前结构体的指针res，来构造嵌套关系
            stk.push(res); // [是结构体的开端，]是结构体的末尾，当遇到末尾时，就会进行结构体之间的嵌套
        }
        else if (c == '-' || isdigit(c)) { // 数字
            if (stk.empty()) // 只有一个数字，没有嵌套关系
                return NestedInteger(stoi(s));
            else
                numStr.push_back(c);
        }
        else if (c == ',') { // 第一个嵌套构造，构造的是一个数
             if (!numStr.empty()){ // 存在空数字串
                stk.top()->add(NestedInteger(stoi(numStr))); // 把数字字符串转为数字后，利用构造函数构造新的结构体作为res的子结构，此时结构体只有一个值
                numStr = ""; // 清除原来的数
            }
        }
        else { // 遇到嵌套的闭合括号，"]"
            if (!numStr.empty()) { // ]前面有数字字符则构造嵌套结构，如果没有不构造，如果是]]则不会构造
                stk.top()->add(NestedInteger(stoi(numStr))); // 此时结构体只有一个值
                numStr = "";
            }
            NestedInteger *res = stk.top(); // 构造第二个嵌套结构，NestedInteger 对象包含一个有两个元素的嵌套列表，当遇到“]”字符时，把stack中存的完整的结构[]作为嵌套结构进行嵌套
            stk.pop();
            if (stk.empty()) {
                return *res;
            }
            else {
                stk.top()->add(*res); // 此时结构体嵌套的是多个结构体
            }
        }
    }
    return NestedInteger();
    }
};
// @lc code=end

