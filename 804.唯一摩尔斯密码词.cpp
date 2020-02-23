/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩尔斯密码词
 */
#include <string>
#include <vector>
#include <set>
using namespace std;
// 直接拼接，没有压缩，直接将word翻译出来，然后计算种类即可，使用hash表进行去重操作

// @lc code=start
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> ans;
        string mos[]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(int i=0; i<words.size(); i++){
            string str="";
            for(int j=0; j<words[i].length(); j++){
                str+=mos[words[i][j]-'a'];
            }
            if(!ans.count(str)) // str不在ans中就插入到ans中
                ans.insert(str);
        }
        return ans.size();
    }
};
// @lc code=end

