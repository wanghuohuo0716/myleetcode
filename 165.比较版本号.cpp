/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */
#include <string>
#include <vector>
#include <sstream>
using namespace std;


// @lc code=start
class Solution {
public:
    int compareVersion(string version1, string version2) {
        char dot;
        int v1,v2;
        istringstream its1(version1);
        istringstream its2(version2);
        // its1="1.01",每次输出的数据是"1" "." "1",多个数字认为是一个字符串
        // true +false =true，true+true=true
        while(bool(its1>>v1) + bool(its2>>v2)){ // 当两个都比较完，若its1为空，执行>>操作会返回NULL，bool会使得其变成false
            if(v1>v2) return 1;
            if(v1<v2) return -1;
            v1=0; // 去掉了就报错？？？
            v2=0;
            its1>>dot; // 输出没用的dot,是字符类型
            its2>>dot;
        }

        return 0;
    }
};
// @lc code=end

        int p1 = 0, p2 = 0;
        int num1 = 0, num2 = 0;
        while(p1 < version1.size() || p2 < version2.size()){
            while(p1<version1.size()&&version1[p1]!='.'){//解析两个小数点之间的数字
                num1 = num1*10+version1[p1]-'0';
                p1++;
            }
            while(p2<version2.size()&&version2[p2]!='.'){
                num2 = num2*10 + version2[p2] - '0';
                p2++;
            }
            if(num1>num2)
                return 1;
            if(num1<num2)
                return -1;
            num1 = 0;//注意这里要置0
            num2 = 0;
            p1++;
            p2++;
        }
        return 0;