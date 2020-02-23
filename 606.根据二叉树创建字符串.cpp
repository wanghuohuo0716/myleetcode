/*
 * @lc app=leetcode.cn id=606 lang=cpp
 *
 * [606] 根据二叉树创建字符串
 */
#include <string>
#include <algorithm>
using namespace std;
// 使用递归，先遍历左节点，当左节点为空时，就会产生括号，判断右节点是否为空，如果为空则不进行括号处理

// @lc code=start

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
public:
    string tree2str(TreeNode* t) {
        string res = "";
        if(t==NULL)
            return res;
        if(t->left==NULL && t->right == NULL){
            res.append(to_string(t->val));
            return res;
        }
        res.append(to_string(t->val));
        res+=("("+tree2str(t->left)+")");
        if(t->right!=NULL) // 此if语句决定了，如果右边为空，就不会括号
            res+=("("+tree2str(t->right)+")");
        return res;
    }
};
// @lc code=end

