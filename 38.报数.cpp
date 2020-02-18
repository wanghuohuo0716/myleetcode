/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */
#include <string>
using namespace std;
// 难点在如何把读的逻辑转换为代码
// 读的结果分为两步，形成了2个数字
// 1.是对相同元素的计数是第一个数字
// 2.相同的元素作为后一个数字
// 3. if(a1[j]==a1[j+1])为了保证数组不越界，需要单独处理最后一个数字

// @lc code=start
class Solution {
public:
    string countAndSay(int n) {
        //后一项为对前一项的描述:n=2,更新了1次；n=3,更新了2次；n=4，更新了3次。
        if(n==1) return "1";//错误点1：返回一个字符串而不是'1'。
        string a1;
        string a2; // 要根据规则，使用a1更新a2
        string tmp;
        int i=0,j=0;
        a1.push_back('1');//错误点2：对于a1.push_back('A');
        //一、总循环次数
        for(i=1;i<n;++i){
            int num=1;
            j=0;//错误点3：忘记置0。
            //二、单次循环
            while(j<a1.size()-1){
                 if(a1[j]==a1[j+1]){ // 为了避免数组越界，j取值范围不能等于a1.size()-1
                     num++;
                     j++;
                 }
                 else{
                     //压入新的vector
                     a2.push_back(num+'0');//错误点4：忘记+'0'。
                     a2.push_back(a1[j]);

                     num=1; // num要置1
                     j++;
                 }
            }
            //把结尾的元素压入新的vector。
            a2.push_back(num+'0');
            a2.push_back(a1[j]);

            a1 = a2;
            a2.clear();
        }
        return a1;
    }
};
// @lc code=end

