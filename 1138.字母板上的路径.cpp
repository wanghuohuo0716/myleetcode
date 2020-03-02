/*
 * @lc app=leetcode.cn id=1138 lang=cpp
 *
 * [1138] 字母板上的路径
 */
#include <string>
using namespace std;
// 巧妙的地方在于根据字符计算在表中的横纵坐标，可以根据字母ASCII码计算出坐标 {nr, nc} = {(ch - 'a')/5, (ch - 'a')%5}
// 把字母按1,2,3,4这样写出来就知道了规律

// 其实不是类似A*的最短路径，而是曼哈顿路径，下一个字符是确定的，所以目标点是确定的，行进的方式是确定的，走过的长度自然可以根据坐标计算

// @lc code=start
class Solution {
public:
    pair<int, int> position(const char ch) {
        const int index = tolower(ch) - 'a';
        return {index/5, index%5};
    }

    string alphabetBoardPath(const string& target) {
        int r = 0, c = 0;
        string os;
        for (const auto& ch : target) {
            auto [nr, nc] = position(ch);
            int dr = nr - r, dc = nc - c; // 目标行列与当前之差
            if (dr < 0) os += string(-dr, 'U'); // 连续填充dr个U，注意dr有正负之分
            if (dc < 0) os += string(-dc, 'L');
            if (0 < dr) os += string(dr, 'D');
            if (0 < dc) os += string(dc, 'R');
            os += "!";
            r = nr;
            c = nc;
        }
        return os;
    }


};
// @lc code=end

