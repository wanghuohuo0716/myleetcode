/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
// 使得两相邻字符不同，不是与原字符不同，因此需要统计各个字符的数目
// 把各个字符的数目统计出来，如果超过了字符串一半则无法完成重构
// 如果没超过，依次放入数量多的字符，就每次间隔一个位置放字符，到了末尾，再把剩下的字符放入间隔中即可

// 难点是如何把对哈希表中的数据进行排序

// @lc code=start
class Solution {
    struct elm{
        char alp; // 字母
        int cnt; // 字母的数量
        friend bool operator <(elm a,elm b){ // 定义了这个就定义了优先级队列中的排列方式!
            return a.cnt<b.cnt;
        }
    };
public:
    string reorganizeString(string S) {
        priority_queue<elm> q;
        unordered_map<char,int> mp;

        for(auto s:S)
            mp[s]++;
        for(auto p:mp){ // 把字母和字母对应的数量放入队列中
            elm t;
            t.alp=p.first;
            t.cnt=p.second;
            q.push(t); // 插入的时候实际上就已经按照优先级队列进行了排序，是按照p.second的降序进行排列
        }

        //若字母的数量大于字符串长度的一半，重构之前和之后都必定有会两个该字符相邻，无法重构
        int i=q.top().cnt;
        if(S.size()%2 && i>S.size()/2+1) //字符串长度为奇数
            return "";
        if(S.size()%2==0 && i>S.size()/2) //字符串长度为偶数
            return "";

        i=0;
        while(!q.empty()){ // 把队列中的字母依次放入S中
            char t=q.top().alp;
            int k=q.top().cnt;
            while(k--){
                if(i>=S.size())
                    i=1;
                S[i]=t;
                i+=2;
            }
            q.pop();
        }
        return S;
    }
};
// @lc code=end

