/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */
#include <string>
using namespace std;
// 核心思想是记录ransom中出现的各个字母的次数，关键在于使用什么样的数据结构来储存
// 使用数组记录26个字母出现的次数，索引使用字符-a作为数组的索引，在ransom中累加，在magazine中递减，如果出现负数则false，如果全部运行完，则true
// 先累加magazine中字母，在减去ransom字母次数，只要字母表中的次数小于0就会退出
// 如果先累加ransom字母，再减去magazine中字母，还需要一个循环来判断字母表中所有的元素都为0
// 一个的思想是“出现一个例外就退出”，另一个是“所有都是对的才是对的”

// 这个构造26个字母的数组的tip比较常见，利用了桶的思想

// @lc code=start
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int hash[26] = {0};
        for(int i = 0;i<magazine.size();++i){
            hash[magazine[i]-'a'] += 1;
        }
        for(int i = 0;i<ransomNote.size();++i){
            hash[ransomNote[i]-'a'] -= 1;
            if(hash[ransomNote[i] - 'a'] < 0)return false;
        }
        return true;
    }
};
// @lc code=end

