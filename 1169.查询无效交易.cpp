/*
 * @lc app=leetcode.cn id=1169 lang=cpp
 *
 * [1169] 查询无效交易
 */
#include <vector>
#include <string>
using namespace std;
// 暴力法
// 把每条记录拆分成同属性段，对相应的段进行比较，分为数据预处理部分和数据比较部分
// 不把大于1000的单独拿循环计算，而是放在和其它case在一个循环中，使用continue跳过剩下的代码即可

// 其实有时候暴力法是考验一个人的基本代码能力，如何把问题转换为代码，如何代码建模，可以仔细研究

// @lc code=start
class Solution{
public:
    vector<string> invalidTransactions(vector<string> &transactions){
        vector<string> ans;
        vector<vector<string>> trans(transactions.size());
        // 分割每条记录，把元素单独储存起来
        for (int i = 0; i < transactions.size(); i++){ // 遍历所有的记录
            int last = -1;
            for (int j = 0; j < transactions[i].size(); j++){ // 遍历某条记录内部信息
                if (transactions[i][j] == ','){ // 分隔
                    trans[i].push_back(transactions[i].substr(last + 1, j - last - 1)); // 提取从last + 1到j - last - 1的子串放到vector中
                    last = j;
                }
                else if (j == transactions[i].size() - 1) // 最后一个子串放入其中
                    trans[i].push_back(transactions[i].substr(last + 1, j - last));
            }
        }

        for (int i = 0; i < trans.size(); i++){
            if (atoi(trans[i][2].c_str()) > 1000){ // 大于1000为无效记录
                ans.push_back(transactions[i]);
                continue;
            }

            for (int j = 0; j < trans.size(); j++){
                if (i != j && trans[i][0] == trans[j][0] && trans[i][3] != trans[j][3]){ // 同一个人在不同地方消费
                    int a = atoi(trans[i][1].c_str());
                    int b = atoi(trans[j][1].c_str());
                    if (abs(a - b) <= 60){ // 间隔时间在60min以内
                        ans.push_back(transactions[i]); // i和j的交易时差小于60，把i插件去，而不是j，避免重复
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
