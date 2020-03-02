/*
 * @lc app=leetcode.cn id=1081 lang=cpp
 *
 * [1081] 不同字符的最小子序列
 */
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
// 这个子序列是要求保留字母在原字符串中相对字母的顺序，并不要求是连续的子序列
// 插入栈的元素要先比较与栈顶元素的大小，如果在栈顶元素后面，则直接插入，如果在栈顶元素前面，先遍历后面的字符是否有栈顶元素，如果有，则弹出栈顶元素(然后继续比较)，如果没有，则入栈

// @lc code=start
class Solution {
public:
    string smallestSubsequence(string text) {
	stack<char> st;
	vector<int> last(256, 0), seen(256, 0); // last记录同种字符在字符串中的最大索引，seen记录同种字符是否被使用过
	for(int i = 0; i < text.size(); i++) // 构造字母桶，记录同种字符在字符串中的最大索引。字母作为键，字母在字符串中的索引作为值
		last[text[i]] = i;
	for(int i = 0; i < text.size(); i++){
		if(seen[text[i]]) // 字母已经用过了则跳过
			continue;

		while(st.size() and st.top() > text[i] and last[st.top()] > i){ // last[st.top()] > i，就是查询st.top()这个字符在后面是否还出现过
            seen[st.top()] = 0; // 弹出后要清零，消除使用记录
            st.pop();
        }
        st.push(text[i]);
        seen[text[i]] = 1; // 记录字符已经用过了，去重
    }
	string res = "";
	while(st.size()){
        res += st.top();
        st.pop();
    }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

        // 若果不考虑相对字母在原字符串中的顺序，可以用set迅速解决
        vector<char> al(26);
        set<char> se;
        string res;
        for(auto t:text)
            se.insert(t);
        for (int i = 0; i < 26;i++)
            al[i] = 'a' + i;
        for (int i = 0; i < 26;i++)
            if(se.find(al[i])!=se.end())
                res += to_string(al[i]);
        return res;