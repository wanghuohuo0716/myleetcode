/*
 * @lc app=leetcode.cn id=520 lang=cpp
 *
 * [520] 检测大写字母
 */
#include <string>
using namespace std;
// 大写字母使用正确：大写字母的个数与索引存在关系
// 做题可以从正面思考和反面思考，正面：三种都是的条件列举出来，符合就可以。反面：寻找不符合三类正确结果的错误答案所具有的特点
// 比如这里的条件就是：大写字母的负数小于正在遍历的下标，就是错误答案的特点

// 错误答案的条件不能完全覆盖，再用正确答案的条件筛选一遍即可

// 错误答案的条件筛选位置，然后再筛选数量

// @lc code=start
class Solution {
public:
    bool detectCapitalUse(string word) {
        int uc = 0;
        for (int i = 0; i < word.size(); i++) { // 筛选大写字母的位置是否正确
            if (isupper(word[i])) {
                if(uc<i){
                    return false;
                }
                uc++;
            }
        }
        return uc == word.size() || uc <= 1; // 满足三种正确答案的特点，大写字母的个数为0,1，word.size()
    }
};
// @lc code=end

