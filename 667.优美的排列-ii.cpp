/*
 * @lc app=leetcode.cn id=667 lang=cpp
 *
 * [667] 优美的排列 II
 */
#include <vector>
#include <algorithm>
using namespace std;
// 暴力法，直接生成全排列结果，再验证是否符合要求，全排列结果是O(n!)复杂度，验证是O(n)复杂度
// 题目要求只要找到一个就行，复杂度可以是O(n)
// 初始化为1到n，此时差值为1种，然后从第二位到末位开始不停翻转即可，翻转一次增加一种差值,https://leetcode-cn.com/problems/beautiful-arrangement-ii/solution/java-bu-duan-fan-zhuan-zai-tong-guo-guan-cha-zhi-j/
// 通过翻转，每次增加一个间隔，当间隔增加到k时停止翻转，剩下的位置按顺序填充即可。

// @lc code=start
class Solution {
public:
    vector<int> constructArray(int n, int k) {
		vector<int> arr(n);
		int l = 1, r = n;

		// 前 k 个数需要间隔从两端取；
		int i = 0;
		while (true) {
			if(i < k) { arr[i] = l; i++; l++; } else break;
			if(i < k) { arr[i] = r; i++; r--; } else break;
		}

		// 剩下的数字则按照降序或者升序排列；
		if(k % 2 == 1) {
			for (int j = k; j < arr.size(); j++) {
				arr[j] = l;
				l++;
			}
		} else {
			for (int j = k; j < arr.size(); j++) {
				arr[j] = r;
				r--;
			}
		}
		return arr;
    }
};
// @lc code=end

