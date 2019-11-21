/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */
#include <vector>
#include <algorithm>
using namespace std;
// 首先要知道一个结论，前序/后序+中序序列可以唯一确定一棵二叉树，所以自然而然可以用来建树。
// 构造树的过程用递归的方法是自然而然的，树的定义就是递归定义的
// 如何根据前序和中序遍历的结果构造树呢？
// 递归过程：1.找到前序的第一个值 2.把前序的第一个值作为根节点 3.根据前序的第一个值把中序分成两个左右两个序列，左边就是根节点的左节点组成部分，右边就是根节点右边组成部分 4.开始递归过程，左边就已知了前序和中序结果，，此时右边只知道中序结果，必须把左边遍历完后才知道右边的先序遍历结果
// 递归终止的条件：中序结果只有一个，唯一确定了左子结点，最后确定了右节点则整个树建立完毕
// PPT理解更充分：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/solution/cong-qian-xu-he-zhong-xu-bian-li-xu-lie-gou-zao-er/

// Definition for a binary tree node.
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
class Solution{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder){
        return pre_order(0, inorder.size() - 1, 0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode *pre_order(int leftpre, int rightpre, int leftin, int rightin, vector<int> &pre, vector<int> &in){
        if (leftpre > rightpre || leftin > rightin)
            return NULL;
        TreeNode *root = new TreeNode(pre[leftpre]);
        int rootin = leftin;
        while (rootin <= rightin && in[rootin] != pre[leftpre])
            rootin++;
        int left = rootin - leftin;
        root->left = pre_order(leftpre + 1, leftpre + left, leftin, rootin - 1, pre, in);
        root->right = pre_order(leftpre + left + 1, rightpre, rootin + 1, rightin, pre, in);
        return root;
    }
};
// @lc code=end
