/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */
// 要求时间复杂度必须是O(n)，因此排序是不可能的
// 思路是维护三个最大的数，第一大a，第二大b，第三大c
#include <vector>
#include <unordered_set>
using namespace std;
// @lc code=start
class Solution {
public:
    int thirdMax(vector<int>& nums) {
    // 下面代码比上面的要冗余的多，没有State of art的感觉
    int first = INT_MIN, second = INT_MIN, third = INT_MIN, f = INT_MAX;
    for (int i = 0; i < nums.size(); ++i){
        f = min(f, nums[i]);//The smallest number that appears
        if (nums[i] > first){//-2147483648
            third = second, second = first, first = nums[i];
        }else if (nums[i] > second && nums[i] < first){
            third = second, second = nums[i];
        }else if (nums[i] > third && nums[i] < second) {
            third = nums[i];
        }
    }
    return (second > third) && (third >= f) ? third : first; //third >= f是针对数组长度不超过3的处理办法，如果数组中没有INT_MIN则third不能是INT_MIN，利用初值来处理特殊情况

        // int a = INT_MIN, b = INT_MIN, c = INT_MIN;
        // bool flag = false;
        // int n = nums.size();

        // for (int i = 0; i < n; ++i)
        // {
        //     if(nums[i]==INT_MIN)
        //     {
        //         flag = true;
        //         continue;
        //     }

        //     if(nums[i]>a)
        //     {
        //         c=b;
        //         b=a;
        //         a=nums[i];
        //     }
        //     else if(nums[i]<a)
        //     {
        //         if(nums[i]>b)
        //         {
        //             c=b;
        //             b=nums[i];
        //         }
        //         else if(nums[i]<b)
        //         {
        //             if(nums[i]>c)
        //             {
        //                 c=nums[i];
        //             }
        //         }
        //     }
        // }

        // return c==INT_MIN? ((b>INT_MIN && flag)?c:a):c;
    }
};
// @lc code=end

