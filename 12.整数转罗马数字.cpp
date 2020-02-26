/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 */
#include <string>
#include <vector>
using namespace std;
// 罗马字符999不是IM，而是CMXCIX,999是有900+90+9组成的
// 一共有13种组合方式，表示数字，所有的数字都用这13种组合表示
// 贪心算法，最大的数最多，最大的数不满足了，选择次大的数继续进行组合

// 可以对这13个数分别做除法，结果就是对应罗马数字组合的个数
// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        vector<int> values={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> strs={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        string res;
        for(int i = 0; i < values.size(); i++){
            while(num >= values[i]){
                res += strs[i];
                num -= values[i];
            }
        }
        return res;
    }
};
// @lc code=end

