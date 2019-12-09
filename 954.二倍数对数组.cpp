/*
 * @lc app=leetcode.cn id=954 lang=cpp
 *
 * [954] 二倍数对数组
 */
#include <vector>
#include <map>
using namespace std;
// 关键在于如何寻找某个数的二倍是否存在
// 借助map关联容器储存元素及元素出现的数目，然后比较元素的二倍是否存在并且元素数目是否满足要求，通过减去已经配对的元素数目，判断剩下元素的数目是否能继续完成配对
// map是有序关联容器，<key,value>，存储键值对，默认是根据key的大小进行排序 unorder_map是无序关联容器
// 记录数组中元素及相应的数目这个需求还是很常见的，一般都是用的hash表处理

// @lc code=start
class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        map<int, int> dict;
        for (auto n : A)
            ++dict[abs(n)];
        dict.erase(0);
        while (!dict.empty()) {
            int maximum = dict.rbegin()->first;
            int half = maximum / 2;
            if (maximum & 0x1)
                return false;
            else if (dict[half] < dict[maximum])
                return false;
            dict[half] -= dict[maximum];
            dict.erase(maximum);
            if (dict[half] == 0)
                dict.erase(half);
        }
        return true;
    }
};
// @lc code=end

