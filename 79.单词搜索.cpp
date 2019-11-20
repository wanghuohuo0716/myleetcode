/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// 回溯法
// 直接搜索整个二维网格比找到初始位置在搜索在代码上要简洁许多，虽然看起来花费时间要多，但其实花费的时间与搜索初始位置相比本质相同，都得遍历一遍二维网格
// 用什么变量来判断已经达到目标，即成功的标志是什么：搜索的字母在二维网格中是否存在，记录的是当前字母在word中的索引，当索引达到最后即满足要求
// 子结点是什么：是当前结点四周的结点
// 回溯过程是什么：当前结点如果不满足要求，搜索四周子结点，搜索完成后回溯，返回搜索结果true/false；如果满足要求，回溯的同时返回true；
// 在搜索子结点的过程中使用i和j代表子结点的索引
// 只有所有的搜索节点回溯时返回true才代表搜索到了，否则就没有

// 回溯有三种case，回溯的标志就是return 1.搜索过程不符要求(比如数组越界)，终止搜索，进行回溯 2.搜索成功，终止搜索，回溯 3.搜索完子结点，终止搜索，回溯

// @lc code=start
class Solution{
public:
    bool helper(vector<vector<char>> &board, string &word, int i, int j, int length){
        if (i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || length >= word.size() || word[length] != board[i][j]){
            return false; // 这是回溯
        }
        if (length == word.size() - 1 && word[length] == board[i][j]){
            return true; // 这也是回溯
        }
        char temp = board[i][j];
        board[i][j] = '-'; // 对结点的处理，标志为已拓展
        bool flag = helper(board, word, i, j + 1, length + 1) || helper(board, word, i, j - 1, length + 1) || helper(board, word, i + 1, j, length + 1) || helper(board, word, i - 1, j, length + 1);
        board[i][j] = temp; // return回溯之前清除掉已拓展的标志
        return flag; // 这还是回溯
    }

    bool exist(vector<vector<char>> &board, string word){
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if (helper(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end
