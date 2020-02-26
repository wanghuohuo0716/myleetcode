/*
 * @lc app=leetcode.cn id=788 lang=cpp
 *
 * [788] 旋转数字
 */
#include <string>
using namespace std;
// 这个数字是旋转自身，而不是首尾旋转，读清题意
// 使用除法和取余操作，对整数的每一位数字进行检测，判断是否是好数，对0,1,8这三个数字不做操作

// @lc code=start
class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for(int i=1;i<=N;i++){
            int n = i,flag = 0;
            while(n){
                int x = n%10;
                if(x==3||x==4||x==7)
                    break;
                if(x==2||x==5||x==6||x==9) // 核心，避免了0,1,8这三个数重复形成的数，如888
                    flag = 1;
                n /=10;
            }
            if(n==0&&flag) // 所有位的数都是好数，整个数才是好数
                count++;
        }
        return count;
    }
};
// @lc code=end

