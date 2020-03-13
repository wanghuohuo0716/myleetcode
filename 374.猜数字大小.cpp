/*
 * @lc app=leetcode.cn id=374 lang=cpp
 *
 * [374] 猜数字大小
 */

// 二分法查找数字，注意，二分查找的时候n不一定能找到

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(n==1)
            return 1;
        if(guess(n)==0)
            return n;
        int res,left=1,right=n,mid;
        while(left<=right){
            mid = left + (right - left) / 2;
            res = guess(mid);
            if (res == 0)
                return mid;
            if (res == -1)
                right=mid;
            if (res==1)
                left = mid;
        }
        return -1; // 函数有返回值，必须要有个return
    }
};
// @lc code=end

