/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */
#include <vector>
#include <algorithm>
using namespace std;
// 二分查找运载力K，计算K是否能运完货物，能运完则查找更小的K，不能则增大，直到找到最小的K
// 承载力K从max(weights)开始（即所有包裹中质量最大包裹的重量，低于这个重量我们不可能完成任务），逐渐增大承载力K，直到K可以让我们在D天内送达包裹。此时K即为我们所要求的最低承载力。
// 逐渐增大承载力K的方法效率过低，让我们用二分查找的方法来优化它。


// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int left = 0, right = INT_MAX;
        while (left < right) {
        	int mid = left + (right - left) / 2;
        	if (canShip(weights, D, mid)) { // 当前K可以满足，则减小
        		right = mid;
        	} else { // 当前K不能满足，则增大
        		left = mid+1;
        	}
        }
        return left;
    }
    bool canShip(vector<int> weights, int D, int K) {
    	int cur = K; // cur 表示当前船的可用承载量
    	for (int weight: weights) {
    		if (weight > K)
                return false;
    		if (cur < weight) {  //装到最大载重了
    			cur = K; // 第二天又有K承载量可以运输
    			D--;
    		}
    		cur -= weight; // 尽可能装满船
    	}
    	return D > 0; // 能否在D天内运完
    }
};
// @lc code=end

