/*
 * @lc app=leetcode.cn id=833 lang=cpp
 *
 * [833] 字符串中的查找与替换
 */
#include <string>
#include <vector>
#include <map>
using namespace std;
// 使用map记录要替换的信息，把检测的索引作为键，把source和target作为对应的值也放进去，这样就能很方便的根据替换的索引找到source和target

// tip：不要在原始字符串S上进行删改，否则会影响后续的判断，要新建一个字符串
// 使用pair，使得map数据的一个键可以有两个值
// 选择从S逐个遍历的想法也比较好，能方便处理非替换的字符
// 如果是从indexes中遍历，租后生成结果时，S中剩余的字符不好拼接。所以选择从S中遍历，找到indexes就替换，没有找到就处理剩余字符

// @lc code=start
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        // generate dict
        map<int, pair<string,string>> dict;
        for (int i(0); i < indexes.size(); ++i) {
            dict[indexes[i]] = make_pair(sources[i], targets[i]);
        }
        // loop S
        string rst;
        int pos = 0;
        while (pos < S.size()) {
            if (dict.count(pos) and dict[pos].first == string(S.begin() + pos, S.begin() + pos + dict[pos].first.size())) {
                // dict[pos] exists and the corresponding source string, replace the substring.
                rst += dict[pos].second;
                pos += dict[pos].first.size();
            }
            else {
                // no replacement
                rst += S[pos];
                pos += 1;
            }
        }
        return rst;
    }
};
// @lc code=end

