/*
 * @lc app=leetcode.cn id=1222 lang=cpp
 *
 * [1222] 可以攻击国王的皇后
 */
#include <vector>
#include <algorithm>
using namespace std;
// 以国王为中心，逆时针遍历8个方向，寻找皇后。
// 表示运动的方法有很多种，可以是用两个数组，可以是用一个数组
// 有个需要注意的技巧：判断某个(r,c)位置是否有queen，无法直接根据题目给的变量queens来判断，给的是queen在地图的坐标，需要维护一个地图变量方便快速判断某个坐标是否有queen
// for (const auto& q : queens)
//     queen_map[q[0]][q[1]] = true;

// @lc code=start
class Solution {
public:
    vector<vector<int>> queensAttacktheKing(const vector<vector<int>>& queens, const vector<int>& king) {
        vector<vector<int>> ans;
        vector<vector<bool>> queen_map(n, vector<bool>(n, false));
        for (const auto& q : queens)
            queen_map[q[0]][q[1]] = true;
        const int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        const int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        for (int dir = 0; dir < 8; ++dir)
            for (int r=king[0], c=king[1]; suitable(r,c); r+=dr[dir], c+=dc[dir]) // 在每个dir方向上搜是否有queen，把一个方向搜完为止
                if (queen_map[r][c]) {
                    ans.push_back({r, c});
                    break;
                }
        return ans;
    }

private:
    static const int n = 8;
    static inline bool suitable(const int r, const int c) { // 不超出棋盘范围
        return 0 <= r && r < n && 0 <= c && c < n;
    }
};
// @lc code=end

