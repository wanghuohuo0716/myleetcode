/*
 * @lc app=leetcode.cn id=816 lang=cpp
 *
 * [816] 模糊坐标
 */
#include <string>
#include <vector>
using namespace std;
// 难点是对一个字符串插入小数点，要保证小数点的合理性！要求测试用例进行分析怎么样插入小数点是合法的！
// 二维坐标有两个数字组成，要把字符串分成左右两半，分别对子字符串进行插入小数点操作，把所有可能的结果组合起来
// 每个左半串都有很多个右半串组合，所以会有嵌套for循环

// tip:1.提取子字符串用substr 2.输出结果的拼接，可以使用string重载的+直接进行拼接

// @lc code=start
class Solution {
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> resVec;
        int strSize = (int)S.size();
        //将S分成两半，注意输入的字符串被一対括号包围，所以分割的下标是[1, strSize - 3]
        for (int i = 1; i < strSize - 2; ++i){
            vector<string> leftVec, rightVec;//分别存储左、右边字符串添加小数点后的情况
            myFunc(leftVec, S.substr(1, i));//対左边i个字符进行添加小数点
            myFunc(rightVec, S.substr(i + 1, strSize - i - 2));//対右边strSize - i - 2个字符添加小数点
            //最后组合成大字符串
            for (const auto &leftStr : leftVec){
                for (const auto &rightStr : rightVec){
                    resVec.push_back('(' + leftStr + ", " + rightStr + ')');
                }
            }
        }
        return resVec;
    }
    //対str添加小数点
    void myFunc(vector<string> &resVec, const string str){
        int strSize = (int)str.size();
        if (str[0] == '0'){//str起始为'0'
            if (strSize > 1){//处理"0XXX"
                //如果最后一个字符为0，则这个字符串不可添加小数点，比如"01230"
                if (str.back() != '0'){
                    resVec.push_back("0." + str.substr(1));
                }
            }
            else{//str == "0"
                resVec.push_back(str);
            }
        }
        else if (strSize == 1 || str.back() == '0'){
            //如果str的长度为1，或者字符串以零结尾，则也不可添加小数点
            resVec.push_back(str);
        }
        else{
            //穷举放置小数点的下标
            for (int i = 1; i < strSize; ++i){
                resVec.push_back(str.substr(0, i) + '.' + str.substr(i));
            }
            resVec.push_back(str);
        }
    }
};
// @lc code=end

