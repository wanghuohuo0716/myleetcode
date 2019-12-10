/*
 * @lc app=leetcode.cn id=1007 lang=cpp
 *
 * [1007] 行相等的最少多米诺旋转
 */
#include <vector>
#include <algorithm>
using namespace std;
// 代码解决的问题核心是如何找出翻转某个数组的数来记录某个数能达到的最大次数
// 1.记录该数在A数组中出现的次数 2.记录把B中的数翻到A上后，A中该数的数目
// min(len-count_a[i], len-count_b[i])是看翻转到A一致的次数小A，还是翻转到B一致的次数小

// @lc code=start
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int len=A.size();
        vector<int> count_a(6, 0);
        vector<int> count_b(6, 0);
        vector<int> count_ab(6, 0);
        for(int i=0;i<len;i++) {
            count_a[A[i]-1]++; // 记录A[i]这个数在A数组出现的次数
            count_ab[A[i]-1]++;// 记录A[i]这个数在A数组出现的次数
            count_b[B[i]-1]++; // 记录B[i]这个数在B数组出现的次数
            if(B[i]!=A[i]) {
                count_ab[B[i]-1]++; // 记录通过翻转B数组能达到该数的最大数目(其实也是翻转了A数组)
            }
        }
        int res=INT_MAX;
        for(int i=0;i<6;i++) {
            if(count_ab[i]==len) { // A B数组完全相同
                res=min(res,min(len-count_a[i], len-count_b[i])); // 翻转A或B次数少的来达到一样的长度，然后选择总的翻转次数最小的
            }
        }
        return res==INT_MAX?-1:res;
    }
};
// @lc code=end

