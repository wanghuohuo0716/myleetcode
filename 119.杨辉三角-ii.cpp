/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

//思路1：重建整个杨辉三角到第rowIndex行，然后输出结果，但是这个空间复杂度很高
//思路2：由于只需要第rowIndex行，每行的计算结果是根据上一行保存下来的，所以需要的空间复杂度只有上面那个一行大小，两个思路的速度是相同的
//在保存上一行的结果上，有两种处理方式：
//1.新建两个vector，一个是i-1行的，一个是i行的，i行数据根据i-1行进行计算，然后再将i行数据复制到i-1行中
//2.只用一个vector，两个处理方式的区别在计算result[j] =result[j] + result[j - 1]，前者计算的过程是根据vector从前往后计算，j从1一直到i-1，但是如果是从后往前计算，j从i-1到1,后者每次只需要增加1个空间大小，不需要额外多出的储存空间
//从前往后计算：更新result[2]后即result[2](第i行)=result[1](第i-1行) + result[2](第i-1行)，vector变量的二个元素result[2]的数值就被覆盖了，更新result[3]会用到新的result[2]，因此这种更新方式需要两个vector
//从后往前计算：result[3](第i行)=result[3](第i-1行) + result[2](第i-1行)，此时result[2]数值并未被覆盖
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result;
        for(int i = 0; i <= rowIndex; ++i){
            result.push_back(1); //更新下一行前，先把数组长度+1，在末尾加上1
            for(int j = i - 1; j > 0; --j){ //j从i-1到1倒着计算，节省储存空间
                result[j] += result[j - 1];
            }
        }
        return result;
    }
};
// @lc code=end

