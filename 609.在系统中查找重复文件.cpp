/*
 * @lc app=leetcode.cn id=609 lang=cpp
 *
 * [609] 在系统中查找重复文件
 */
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
// 思路比较清晰：相同内容的文件路径放到一起，按照不同的内容进行索引
// tip: 1.很自然会想到使用hash表
//      2.在分割字符的时候使用find函数和substr来提取子字符串，相比于sstream与getline组合更灵活和熟悉

// @lc code=start
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> file_dict;
        vector<vector<string>> ans;
        if(paths.size() == 0)
            return ans;
        int n = paths.size();
        for(int i = 0; i < n; ++ i){
            size_t idx = paths[i].find(' '); // find函数返回在字符串中第一次出现该字符的索引
            if(idx != string::npos){ // 若存在空格
                string dir = paths[i].substr(0, idx) + '/'; // 构造dir
                while(idx != string::npos){ // 把单条字符串内的所有路径找完
                    size_t cur = idx + 1;
                    idx = paths[i].find('(', cur); // find函数从索引cur开始查找在字符串中第一次出现“(”的索引
                    string file = dir + paths[i].substr(cur, idx - cur); // 形成文件路径(比dir多了文件名)
                    cur = idx + 1;
                    idx = paths[i].find(')', cur); // 找到闭括号，准备提取内容
                    string content = paths[i].substr(cur, idx - cur); // 提取文件内容
                    file_dict[content].push_back(file); // 把相同文件内容的文件路径插入hash表中
                    idx = paths[i].find(' ', cur);
                }
            }
        }
        for(auto it = file_dict.begin(); it != file_dict.end(); ++ it){
            if(it->second.size() > 1){ // 存在相同内容的文件路径提出出来
                ans.push_back(it->second);
            }
        }
        return ans;
    }
};
// @lc code=end

