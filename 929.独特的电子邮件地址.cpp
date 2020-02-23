/*
 * @lc app=leetcode.cn id=929 lang=cpp
 *
 * [929] 独特的电子邮件地址
 */
#include <vector>
#include <set>
#include <string>
using namespace std;
// 遍历的过程中遇到不同的字符，处理的操作是不同的，并且在@字符之前和之后的操作也是不同的，因此在操作的时候还需要判断此时的字符是在@之前还是之后
// 使用flag记录字符所处的状态

// tip：使用hash表来避免重复计数

// @lc code=start
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> ans;
        for(int i=0;i<emails.size();i++){
            string temp="";
            int flag=1; //把每个字符串分成3种状态，初始为1，即遇到+号之前的状态
            for(int j=0;j<emails[i].size();j++){
                if(emails[i][j]=='+') //遇到+号之后，temp不加任何元素
                    flag=0;
                if(emails[i][j]=='@') //遇到@之后，temp加任何元素
                    flag=2;
                switch(flag){
                    case 1:if(emails[i][j]!='.') temp+=emails[i][j]; break;
                    case 2:temp+=emails[i][j]; break;
                    case 0:break;
                }
            }
            ans.insert(temp);
}
        return ans.size();
    }
};
// @lc code=end

