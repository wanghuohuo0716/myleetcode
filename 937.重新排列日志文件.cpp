/*
 * @lc app=leetcode.cn id=937 lang=cpp
 *
 * [937] 重新排列日志文件
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 关键是自定义排序规则的使用，首先判断是字母串还是数字串，数字串的比较规则简单，字母串需要使用string自带的compare函数进行比较

// 使用自定义比较算法的核心：重新定义“小于”，比较函数的输入是两个变量a,b（有先后顺序之分），返回的是bool类型，如果返回true，则a<b，如果返回是false，则a>b
// 根据返回的true和false来判断a与b的大小关系

// @lc code=start
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), cmp_stable);
        return logs;
    }
    static bool cmp_stable(const string &a, const string &b){
        int pa = 0;
        int pb = 0;
        while(a[pa++] != ' '); // 先比较再自增，找到标识符后第一个字符的位置
        while(b[pb++] != ' ');
        bool aIsNumberLog = a[pa] >= '0' && a[pa] <= '9'; // 根据第一个字符判断是字母串还是数字串
        bool bIsNumberLog = b[pb] >= '0' && b[pb] <= '9';

        // 数字排序
        if(!aIsNumberLog && bIsNumberLog) return true;
        if(aIsNumberLog && !bIsNumberLog) return false;
        if(aIsNumberLog && bIsNumberLog) return false; // return false 的话，若a和b都是数字日志且相等，那么它们将会保持原来的顺序。

        // 字母排序
        int cmp = a.compare(pa, -1, b, pb, -1);
        if(cmp == 0)
            return a.compare(0, pa, b, 0, pb) <= 0;
        else if(cmp < 0)
            return true; // a is lower
        else
            return false;
    }
};
// @lc code=end

