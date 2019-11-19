/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
// @lc code=start
class Solution {
private:
    vector<int> temp;
    vector<vector<int>> res;
    int n;

public:
    void backtrace(map<int, int>& map, int i) {
        if (i == n) { // i代表已经完成填数的个数，排列的坑位 __ __ __
            res.push_back(temp);
            return;
        }
        for (auto& j : map) {
            if (j.second == 0) continue;
            temp.push_back(j.first); // 把值放进去
            --j.second; // 对应的次数减一
            backtrace(map, i + 1);
            temp.pop_back(); // 弹出值
            ++j.second; // 对应次数加一
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> map;
        n = nums.size();
        for (auto x : nums) ++map[x]; //第一个记录值，第二个记录这个值出现的次数
        backtrace(map, 0);
        return res;
    }
};
// @lc code=end
// 如果不设置这两个变量为全局变量，就得在函数中不断地传参下去，浪费空间
vector<int> nums; //待搜索数据，全局变量
vector<int> path; // 储存当前的路径
vector<vector<int>> res; //输出结果，全局变量
void main(void){
    int target = 0;
    backtrace(0, target); // 0代表根节点的索引，数组的第一个元素。把数组看成了树
}

void backtrace(int i, int target){
/*1*/if(target==0){ // 判断是否满足要求,即是否走到了叶子结点
/*2*/    res.push_back(path); // 走到了叶子结点处，对满足要求的结果进行处理
     return; //叶子结点处理完毕，返回到上一层根节点
        }
/*3*/for (int j = i; j < nums.size();j++){ // 对结点i(递归用两层循环嵌套表示，根节点索引用i表示，子结点索引用j表示)的所有子结点j进行搜索
/*4*/    path.push_back(nums[j]);// 第一次搜索到结点j时，对结点j进行处理
/*5*/    backtrace(j, target-nums[j]); // 以结点j为根结点，搜索结点j的所有子结点(因为是树状结构，这里j+1结点其实是j的子结点)，搜索完成后回溯到该结点；回溯后，下一次循环再搜索j+1的所有子结点，然后j+2，j+3...nums.size()-1，知道把i的所有子结点搜索完毕
/*6*/    path.pop_back();// 回溯到结点j时，处理结点j(已经搜索完以j的某个子结点的所有子结点，如搜索完j+1结点的所有子结点)
    }
}
// 1：控制条件
// 2: 结果处理
// 3：遍历i的所有子结点j
// 4: 对结点j的预处理
// 5：与结点j相关的控制条件变化处理
// 6: 回溯到结点j的处理
// 对回溯法，要处理的就是这6处代码


