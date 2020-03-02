/*
 * @lc app=leetcode.cn id=468 lang=cpp
 *
 * [468] 验证IP地址
 */
#include <string>
#include <vector>
#include <sstream>
using namespace std;
// 思路清晰且简单，把IP地址进行分段存在vector<string>中，每段进行检测是否符合要求，很多限制条件是根据测试用例来设置的
// 采用的函数结构使得思路贼清晰，重复使用split函数
// 自定义的split函数利用sstream和getline函数，对指定的分隔符进行分割，快速提取每段字符串
// 使用auto进行for循环，也避免了不知道单个段里面字符数目的多少的尴尬，解决了IPV6前置0的问题

// @lc code=start
class Solution {
public:
    string validIPAddress(string IP) {
        if (isValidIPv4(IP)) return "IPv4";
        if (isValidIPv6(IP)) return "IPv6";
        return "Neither";
    }

    // 优雅的split
    void split(const string s, vector<string>& vs, const char delim= ' '){ // 变量vs是记录ip的每一段字符串
        istringstream iss(s);
        string temp;
        while (getline(iss,temp,delim)){
            vs.push_back(temp);
        }
        if (!s.empty() && s.back() == delim)
            vs.push_back({});//加这句的原因是getline不会识别最后一个delim,避免误判"172.16.254.1.","2001:0db8:85a3:0:0:8A2E:0370:7334:"之类的情况
    }

    // 判定是否IPv4
    bool isValidIPv4(string IP){
        vector<string> vs; // 记录ip的每一段字符串
        split(IP,vs,'.'); // 会更新vs，vs从储存了变量IP中的每一段字符串
        if (vs.size()!=4)
            return false;

        for (auto &v:vs) {
            if (v.empty() || (v.size()>1 && v[0] == '0') || v.size()>3) // IPV4的每段进行筛选，根据测试用例来的限制条件
                return false;
            for (auto c:v) { // 对每一段进行内部验证是否是数字，也是根据测试用例来的
                if (!isdigit(c))
                    return false;
            }
            int n = stoi(v);
            if (n<0||n>255)
                return false;
        }
        return true;
    }

    // 判定是否IPv6，筛选的特别条件是根据测试用例来的
    bool isValidIPv6(string IP){
        vector<string> vs;
        split(IP,vs,':');
        if (vs.size()!=8) // 对ip进行筛选
            return false;
        for (auto &v:vs) {
            if (v.empty() || v.size()>4 ) // 对段进行筛选
                return false;
            for (auto c:v){ // 段内筛选
                if (!(isdigit(c) || (c>='a'&&c<='f') || (c>='A'&&c<='F')))
                    return false;
            }
        }
        return true;
    }
};
// @lc code=end

