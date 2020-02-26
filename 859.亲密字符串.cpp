/*
 * @lc app=leetcode.cn id=859 lang=cpp
 *B
 * [859] 亲密字符串
 */
#include <string>
#include <vector>
#include <set>
using namespace std;
// 字符串一个个进行比较，如果是亲密的字符串，则不同的字符个数是0个或者2个，2个是交换后可以相同，0个是两个字符串相同，但是同时要求有重复字符
// 难点1是要考虑如果相同的字符串如果是亲密字符，必须要有重复字符
// 难点2是想到使用set这种hash表进行快速去重

// @lc code=start
class Solution {
public:
    bool buddyStrings(string A, string B) {
        if (A.size() != B.size()) return false;
        vector<int> index_of_mismatch;
        for (int i = 0; i < A.size(); i++)
            if (A[i] != B[i]) {
                index_of_mismatch.push_back(i);
                if (2 < index_of_mismatch.size()) return false;
            }
        if (index_of_mismatch.size() == 0) {
            return set<char>(A.begin(), A.end()).size() < A.size(); // 创建一个新变量(没有变量名称)，set<char>(A.begin(), A.end()).size()使用字符串A中所有字符构造一个set，代码会自动去重，新的变量长度如果小于A的长度，意味着里面有重复的元素
        }
        else if (index_of_mismatch.size() == 2) {
            return A[index_of_mismatch[0]] == B[index_of_mismatch[1]] &&
                   A[index_of_mismatch[1]] == B[index_of_mismatch[0]];
        }
        return false;
    }
};
// @lc code=end
