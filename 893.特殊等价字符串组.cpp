/*
 * @lc app=leetcode.cn id=893 lang=cpp
 *
 * [893] 特殊等价字符串组
 */
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
// 题目要求i ％ 2 == j ％ 2，交换 S[j] 和 S [i]。实际就是字符串的奇数子字符串和偶数子字符串各自相同
// 把奇数和偶数字符串单独提出来，然后分别排序后组合起来，然后比较不同字符串奇偶子串组合后的字符串是否相同，如果相同则原来就是一组的字符串
// tip：1.利用了set的自动去重机制，在使用insert函数时，如果是相同的就不会插入，最后计算set的size就知道了有多少组子串

// ！！！核心！！！
// tip：2.使用排序算法来判断 乱序的子串元素及元素的个数是否相同

// @lc code=start
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        set<string> ans;
        for(int i=0;i<A.size();i++){
            string odd="";
            string even="";
            for(int j=0;j<A[i].size();j++)
            {
                if(j%2)
                    odd.push_back(A[i][j]);
                else
                    even.push_back(A[i][j]);
            }
            sort(odd.begin(),odd.end());
            sort(even.begin(),even.end());
            ans.insert(odd+even);
        }
        return ans.size();
    }
};
// @lc code=end

