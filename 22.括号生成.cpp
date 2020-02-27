/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <string>
#include <vector>
#include <map>
using namespace std;
// 其实有点像全排列问题，所以需要回溯法进行寻找所有符合规则的答案
// 构造法生成括号，使用回溯法来构造

// 需要分析生成的规则，来确定深度遍历的规则！！！！！
// 1.回溯法维护的变量是哪些，2.满足要求的条件是什么！！！！！

// 左右括号数量相同，且都为n；有效的括号要求左括号在左边
// 保证左括号在左边，不会出现)(情况，要求左括号数量要不小于右括号！！！
// 左右括号数量相同，并且都为N，则构造出了一个合法的括号字符串
// 因此维护的变量就是括号的数量，左右括号的大小关系，括号字符串

// @lc code=start
class Solution{
public:
    vector<string> ans;
    int N;
    void dfs(int l, int r, string has){ // l:当前字符串变量has中左括号数量，r:当前字符串变量has中右括号数量
        if (r > l)
            return;
        if (l > N)
            return;
        if (l == r && r == N){ // 左右括号数量相同，并且都为N，则构造出了一个合法的括号字符串
            ans.push_back(has);
            return;
        }
        dfs(l + 1, r, has + "("); // 增加一个左括号
        dfs(l, r + 1, has + ")"); // 增加一个右括号
    }
    vector<string> generateParenthesis(int n){
        N = n;
        if (!N)
            return {};
        dfs(0, 0, "");
        return ans;
    }
};
// @lc code=end
