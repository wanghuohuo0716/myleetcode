/*
 * @lc app=leetcode.cn id=835 lang=cpp
 *
 * [835] 图像重叠
 */
#include <vector>
using namespace std;
// 用二元组 (x, y) 表示对 A 的偏移量 delta，其中 x 表示向左（负数）或向右（正数），y 表示向上（负数）或向下（正数）
// 枚举偏移量的时间复杂度为O(n^4),判断是否重叠的复杂度为O(n^2)
// @lc code=start
class Solution{
public:
    int f(int x, int y, vector<vector<int>> &A, vector<vector<int>> &B){
        int m = A.size();
        int n = A[0].size();
        // A.右下角位于pos(x,y)
        int ansA = 0;
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                ansA += A[m-x-1+i][n-y-1+j]*B[i][j];
            }
        }
        // B.右下角位于pos(x,y)
        int ansB = 0;
        for(int i=0; i<=x; i++){
            for(int j=0; j<=y; j++){
                ansB += A[i][j]*B[m-x-1+i][n-y-1+j];
            }
        }
        return max(ansA, ansB);
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int m = A.size(); if(m==0) return 0;
        int n = A[0].size(); if(n==0) return 0;
        int ans = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                ans = max(ans, f(i, j, A, B));
            }
        }
        return ans;
    }
};
// @lc code=end