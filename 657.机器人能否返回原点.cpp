/*
 * @lc app=leetcode.cn id=657 lang=cpp
 *
 * [657] 机器人能否返回原点
 */
#include <string>
using namespace std;
// 设置两个变量统计上下和左右作为一组的次数，上下次数必须相同，左右次数必须相同
// tip：使用switch语句来代替hash表，直接进行索引

// @lc code=start
class Solution {
public:
    bool judgeCircle(string moves) {
        int UD = 0,LR = 0;
        for(char c : moves){
            switch(c){
                case 'U':   UD+=1;  break;
                case 'D':   UD-=1;  break;
                case 'L':   LR+=1;  break;
                case 'R':   LR-=1;  break;
            }
        }
        return !UD&&!LR ? true : false ;
    }
};
// @lc code=end

