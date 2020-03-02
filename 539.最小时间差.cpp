/*
 * @lc app=leetcode.cn id=539 lang=cpp
 *
 * [539] 最小时间差
 */
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// 转化为分钟，然后进行排序，要注意首尾时间差
// 默认理解是一天内的24小时，经过的时间，
// 只需要比较首尾即可，比如["00:00","00:01"，"23:59"],只需要对首位进行+24小时即可，因为排在首位后面的时间差肯定比首位要大

// tip:提取子串使用substr函数提取
// 将首位+24小时后push_back在末尾，让首位移动到末尾，使用for就可以一次比较完，不用再单独处理

// @lc code=start
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for (int i = 0; i < timePoints.size();i++){
            string hour = timePoints[i].substr(0,2); // 快速提取子串
            string minute = timePoints[i].substr(3,2);
            int time = stoi(hour) * 60 + stoi(minute);
            times.push_back(time);
        }
        sort(times.begin(), times.end());

        times.push_back(times[0]+24*60); // 将首位的时间移到第二天后与末尾时间进行比较，因为只要最小的一个时间差，所以只要比较首位即可

        int minvalue = INT32_MAX;
        for (int i = 0; i < times.size()-1;i++){ // 连续值，最小的值一定是两个值之间差
            minvalue = min(times[i + 1] - times[i], minvalue);
        }
        return minvalue;
    }
};
// @lc code=end

