/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
#include <vector>
using namespace std;
// 找分段连续的0，当0的数目大于等于3的时候才能种，3个0则可以种，4个也是1,5个是2，(每一段中0的个数-1/2)取下限
// 但是上述这个太难写代码了，完全没有和程序结合起来，想问题的解决方案的时候就没有考虑到程序如何写的问题！！！

// 应该直接想象有一列数组的图像在脑海中，利用思考遍历过程中如何处理，没有遍历的思想！！

//检测是否有连续三个都为0的情况，如果有就把中间那个置位1，否则不处理。然后对开始和结尾进行特殊处理即可。
// @lc code=start
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size();i++){
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0))
            {
                flowerbed[i] = 1;
                count++;
            }
        }
        return count >= n;
    }
};
// @lc code=end

