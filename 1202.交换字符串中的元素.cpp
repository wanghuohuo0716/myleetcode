/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
// 字符串的数组题和数字的数组题在思路上差别还是挺大的
// 题意：任意多次交换 在 pairs 中任意一对索引处的字符，两个任意其实就是说pairs中某些的index会构成一个集合，集合中的元素可以通过两个任意完成任意排列
// 每个元素被替换成所在集合中的最小字典序元素，就可以使得s是按字典序最小的字符串
// 所以问题的核心在于如何根据pairs构造元素的集合(这些集合是不想交的，否则就会形成一个集合)
// 并查集是一种非常简单的树形数据结构，来帮助元素构造集合
// 并查集的操作有两个：1.Union 2.Find 前者是构造并查集，后者是查找元素所在集合中的根节点
// 理解并查集：https://blog.csdn.net/liujian20150808/article/details/50848646
// 构造并查集：https://www.cnblogs.com/hapjin/p/5478352.html


// @lc code=start
int v[100001];
int find (int i) { // 查找根节点
    while (i != v[i]) {
        v[i] = v[v[i]];
        i = v[i];
    }
    return i;
};
class Solution {
public:
    string smallestStringWithSwaps(string s, const vector<vector<int>>& pairs) {
        const int n = s.size();
        // 初始化并查集，决定了find函数是怎么找到自己的根节点，当节点的前导节点为自己时该节点为根节点
        for (int i = 0; i < n; i++)
            v[i] = i;
        // Union操作，子集合并
        for (const auto& p : pairs) {
            v[find(p[0])] = find(p[1]); // 把p[1]和p[0]归为1类
        }
        // 使用并查集分类字符
        unordered_map<int, vector<char>>classification; // 第一个参数代表类别，第二个参数为该类的元素
        for (int i = n - 1; 0 <= i; -- i) {
            const int t = find(i);
            v[i] = t; // 路径压缩
            if (!classification.count(t)) // 新建一个t类别，t是集合的代表元素(每个t都自成一类)，t的个数是类的个数
                classification[t] = vector<char>();
            classification[t].push_back(s[i]); // 把同一类的元素放到集合中
        }

        // 对同类字符排序，字典倒序
        for (auto& cla : classification) {
            vector<char>& vec = cla.second;
            sort(vec.rbegin(), vec.rend()); // r:reverse 倒序
        }

        // 写会原字符串
        for (int i = 0; i < n; i++) {
            const int t = v[i]; // 由于进行了路径压缩，v[i]就是i的根节点类别t
            s[i] = classification[t].back();
            classification[t].pop_back();
        }
        return s;
    }
};
// @lc code=end

