/*
 * @lc app=leetcode.cn id=665 lang=cpp
 *
 * [665] 非递减数列
 */
#include <vector>
using namespace std;
// 4，2，3
// -1，4，2，3
// 2，3，3，2，4
// [i]>[i+1]时，要么改[i]，要么改[i+1]。[i]=[i-1]，要么换[i+1]=[i]，不能[i]换成[i+1],因为[i-1]与[i]的大小不知道，即后一个数只能被前一个数替换

// 我们通过分析上面三个例子可以发现，当我们发现后面的数字小于前面的数字产生冲突后，
// [1]有时候需要修改前面较大的数字(比如前两个例子需要修改4)，
// [2]有时候却要修改后面较小的那个数字(比如前第三个例子需要修改2)，
// 那么有什么内在规律吗？是有的，判断修改那个数字其实跟再前面一个数的大小有关系，
// 首先如果再前面的数不存在，比如第一个例子，4前面没有数字了，我们直接修改前面的数字为当前的数字2即可。
// 而当再前面的数字存在，并且小于当前数时，比如例子2，-1小于2，我们还是需要修改前面的数字4为当前数字2；
// 如果再前面的数大于当前数，比如例子3，3大于2，我们需要修改当前数2为前面的数3。

// @lc code=start
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i + 1]) {
                int tmp = nums[i];
                if(i == 0) {
                    nums[i] = nums[i + 1];
                } else {
                    nums[i] = nums[i - 1]; // 向小的看齐，i-1肯定小于等于i
                }

                if(nums[i] > nums[i + 1]) { //换了较小的i-1，仍不满足，即出现例3的情况，
                    nums[i] = tmp; // 还原原来的的i
                    nums[i + 1] = nums[i]; //把i+1变成前面的i,只有这两种情况
                }
                cnt++;
                if(cnt == 2) {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end

