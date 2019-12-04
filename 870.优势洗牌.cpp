/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */
#include <vector>
using namespace std;
// 类似于田忌赛马
// 思路:对每个B[i]从A中找比B[i]大的最小的元素A[k]. 如果找到, 就用A[k]替换A[i]. 如果没找到, 就用A中的最小的元素替换A[i].

// @lc code=start
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        int size = A.size();
        if(size == 0 || size != B.size()){
            return vector<int>();
        }
        vector<pair<int, int>> bIndex(size);
        vector<int> result(size);
        for(int i = 0; i < size; i++){
            bIndex[i] = {B[i], i};
        }
        sort(A.begin(), A.end());
        sort(bIndex.begin(), bIndex.end());
        auto it = bIndex.begin();
        auto rIt = bIndex.rbegin();
        for(int i = 0; i < size; i++){
            if(A[i] > it->first){
                result[it->second] = A[i];
                it++;
            } else{
                result[rIt->second] = A[i];
                rIt++;
            }
        }
        return result;
    }
};
// @lc code=end

