/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] 生命游戏
 */
#include <vector>
#include <algorithm>
using namespace std;
// 暴力法：直接创建另一个相同大小的矩阵，然后用3*3的滑动窗口处理原二维网格平面，把得到的值放到新的二维矩阵中
// 利用最低位保存当前的细胞状态（0或1），利用高位保存四周细胞状态的和。这样x&1就能得到当前状态，x>>1就能得到四周细胞状态的和
// @lc code=start
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty())
            return;
        int R = board.size();
        int C = board[0].size();
        int nearby[8][2] = {{-1, 0}, {-1, -1}, {0, -1}, {1, -1}, {1, 0}, {1, 1}, {0, 1}, {-1, 1}};
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                for (int k = 0; k < 8; ++k) {
                    int r = i + nearby[k][0];
                    int c = j + nearby[k][1];
                    if (r >= 0 && r < R && c >= 0 && c < C) {
                        board[i][j] += (board[r][c] & 1) << 1; // 高位保存四周细胞状态的和
                    }
                }
            }
        }
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                int t = board[i][j] >> 1;
                if (t < 2 || t > 3) {
                    board[i][j] = 0;
                } else if (t == 3) {
                    board[i][j] = 1;
                } else {
                    board[i][j] &= 1;
                }
            }
        }
        return;
    }
};
// @lc code=end

