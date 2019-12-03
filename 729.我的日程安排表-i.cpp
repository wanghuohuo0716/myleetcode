/*
 * @lc app=leetcode.cn id=729 lang=cpp
 *
 * [729] 我的日程安排表 I
 */
#include <vector>
#include <algorithm>
using namespace std;
// 难点在于条件的判断，不仅仅是start<iv[1],还得有end>iv[0],因为可能是在该日期前面插入行程

// @lc code=start
class MyCalendar {
public:
    vector<vector<int>> calendar;
    MyCalendar() {

    }

    bool book(int start, int end) {
        for (vector<int> iv : calendar){ // 遍历calendar中的每个元素，自动递增索引
            if (start < iv[1] && end > iv[0]) // 难点在于条件的判断
                return false;
        }
        calendar.push_back(vector<int>{start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

