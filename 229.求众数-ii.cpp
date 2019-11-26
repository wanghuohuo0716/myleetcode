/*
 * @lc app=leetcode.cn id=229 lang=cpp
 *
 * [229] 求众数 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// 类似摩尔投票
// 超过n/3的数最多只能有两个。先选出两个候选人A,B。 遍历数组，分三种情况：
// 1.如果投A（当前元素等于A），则A的票数++;
// 2.如果投B（当前元素等于B），B的票数++；
// 3.如果A,B都不投（即当前与A，B都不相等）,那么检查此时A或B的票数是否减为0：
// 3.1 如果为0,则当前元素成为新的候选人；
// 3.2 如果A,B两个人的票数都不为0，那么A,B两个候选人的票数均减一；

// 暴力法就是对每个元素都遍历一遍数组，记录出现的次数

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0)
            return res;
        //初始化：定义两个候选人及其对应的票数
        int candidateA = nums[0];
        int candidateB = nums[0];
        int countA = 0;
        int countB = 0;
        //遍历数组
        for (int num : nums) {
            if (num == candidateA) {
                countA++;//投A
                continue;
            }
            if (num == candidateB) {
                countB++;//投B
                continue;
            }

            //此时当前值和AB都不等，检查是否有票数减为0的情况，如果为0，则更新候选人
            if (countA == 0) {
                candidateA = num;
                countA++;
                continue;
            }
            if (countB == 0) {
                candidateB = num;
                countB++;
                continue;
            }
            //若此时两个候选人的票数都不为0，且当前元素不投AB，那么A,B对应的票数都要--;
            countA--;
            countB--;
        }

        //上一轮遍历找出了两个候选人，但是这两个候选人是否均满足票数大于N/3仍然没法确定，需要重新遍历，确定票数
        countA = 0;
        countB = 0;
        for (int num : nums) {
            if (num == candidateA)
                countA++;
            else if (num == candidateB)
                countB++;
        }
        if (countA > nums.size() / 3)
            res.push_back(candidateA);
        if (countB > nums.size() / 3)
            res.push_back(candidateB);
        return res;
    }
};
// @lc code=end

