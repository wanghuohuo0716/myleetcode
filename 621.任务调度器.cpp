/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */
#include <vector>
#include <algorithm>
using namespace std;
// 完成所有任务的最短时间取决于出现次数最多的任务数量。
// 1、将任务按类型分组，正好A-Z用一个int[26]保存任务类型个数
// 2、对数组进行排序，优先排列个数（count）最大的任务，
//     如题得到的时间至少为 retCount =（count-1）* (n+1) + 1 ==> A->X->X->A->X->X->A(X为其他任务或者待命)
// 3、再排序下一个任务，如果下一个任务B个数和最大任务数一致，
//     则retCount++ ==> A->B->X->A->B->X->A->B
// 如果不一致，则按顺序填里面的空位，并且填不完，只要花费任务所需要的时间而已
// 4、如果空位都插满之后还有任务，那就随便在这些间隔里面插入就可以，因为间隔长度肯定会大于n，在这种情况下就是任务的总数是最小所需时间

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (tasks.size() <= 1 || n < 1) return tasks.size();
        //步骤1
        vector<int> counts(26);
        for (int i = 0; i < tasks.size(); i++) {
            counts[tasks[i] - 'A']++;
        }
        //步骤2
        sort(counts.begin(), counts.end());
        int maxCount = counts[25];
        int retCount = (maxCount - 1) * (n + 1) + 1;
        int i = 24;
        //步骤3
        while (i >= 0 && counts[i] == maxCount) {
            retCount++;
            i--;
        }
        //步骤4
        return max(retCount, int(tasks.size()));
    }
};
// @lc code=end

