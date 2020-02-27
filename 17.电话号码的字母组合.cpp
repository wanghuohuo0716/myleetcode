/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;
// 使用队列相当于是广度遍历，构建了一个树形结构去广度遍历，队列的元素是strin不是char
// 每次新插入的元素的长度都在慢慢变长，直到遍历完所有的数字


// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;//用于输出向量
        map<char, string> m = { {'2',"abc" },{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };//映射map哈希表
        int size = digits.size();//输入字符串长度
        queue<string> que;//新建队列

        //先将第一个元素对应的码表入队
        for (int j = 0; j < m[digits[0]].size(); j++){
            string str;
            str.push_back(m[digits[0]][j]);//char转string
            que.push(str);//string入队
        }
        string s;//用于存储队头元素
        for (int i = 1; i < size; i++){
            int length = que.size();//当前队列长度！！！！
            while (length--){ // 把当前队列中的每个元素都用一遍
                for (int j = 0; j < m[digits[i]].size(); j++){ // 队头与下一个数字对应的所有字母组合
                    s = que.front(); // 队头在for循环中不变，for循环完了在while循环中就会被弹出，原来队头下一个元素变为队头，
                    s = s + m[digits[i]][j];//队头元素加上新元素
                    que.push(s);//入队
                }
                que.pop();//队头出队，上一个队列的下一个元素变成队头
            }
        }
        while (!que.empty()){
            res.push_back(que.front());//队头元素存储至res
            que.pop();//队头出队
        }
        return res;//返回
    }
};
// @lc code=end

