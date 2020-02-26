/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */
#include <string>
using namespace std;
// 双指针，i指向原字符串，j指向输入字符串，当字符相同时，i和j同时自增，不同时，j自增，直到两个指针直到的字符相同
// 判断的条件1.字符串相同，i遍历到了最后， 2.字符串不同，j遍历到最后字符仍然不同

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i=0;
        int j=0;
        int n=name.length();
        int m=typed.length();
        if(n>m)
            return false;
        while(i<n&&j<m){
            if(name[i]==typed[j]){ // i个j指向的字符相同时，i和j同时自增，不同时，j自增，直到两个指针直到的字符相同
                i++;
                j++;
            }
            else{
                j++;
            }
             if(i==n)
                 return true;
        }
        return false;
    }
};
// @lc code=end

