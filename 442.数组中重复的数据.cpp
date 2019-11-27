/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */
#include <vector>
#include <algorithm>
using namespace std;
// 经典的抽屉原理问题又称鸽笼问题,核心思想分清楚哪个是抽屉，哪个是东西，见https://zhidao.baidu.com/question/1573993951863695900.html
// 数组的索引作为抽屉，数组的值作为东西，当index!=nums[nidex-1],需要将nums[index-1]的值变成抽屉应该装的值即nums[index-1]=index，在此之前还需要保留原抽屉里的东西即prev=nums[index-1]
// 如何为东西找到对的抽屉呢？采用环形替换的方法,数组的数据放在正多边形上，以走跳棋的思路替换数据,隔k个点往前走，总能走回原点
// 为东西找抽屉和为抽屉找东西是两个思路，这里是为东西找抽屉

// 把元素快排，然后比较相邻元素是否相同

// 把元素的值作为索引，去遍历，每次遍历+n，最后检测哪个值大于2n就是遍历超过一次的

// 一定会换回来，因为它的值是pre不变的，那么那么它每次都是跟nums[prev-1]替换，遍历一遍，肯定能找到它的位置。每一个while循环都将一个数字放置到其该有的位置。
// 只要不同他就会跳着遍历，最后会遍历1-n，一定会有重复的
// @lc code=start
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1){ // 东西A不在对的抽屉B里
                int prev = nums[i]; //把东西A从错的抽屉B中拿出，prev代表东西A
                nums[i] = 0; //把东西A从错的抽屉B中拿出
                // 环形替换https://blog.csdn.net/weixin_41951281/article/details/101779479
                while(prev != 0 && prev != nums[prev-1]){ // prev代表抽屉A，两个prev代表的含义是不一样的，前一个是东西，后一个是抽屉，抽屉A是否存放了东西A
                    swap(nums[prev-1], prev); // 把抽屉A里的装的东西B拿出来，把东西A放入到抽屉A里
                }
                if(prev != 0){
                    result.push_back(prev);
                }
            }
        }
        return result;
    }
};
// @lc code=end

// 这个题属于技巧题 首先仔细看输入的给定的数组值 该值的区间为 1 ≤ a[i] ≤ n
// 这其实是这道题解题的关键点，好好利用这个信息。 某些元素出现了两次，
// 而一些其他的元素只出现了1次，我们可以利用这些元素在出现次数上面的不一样做文章。

// 仔细观察发现1 ≤ a[i] ≤ n 这个条件，正好和我们数组的下标差1，
// **我们可以按照数值来遍历数组**
// 那么在数组中具有相同值的元素，会被经过两次，那么我们只要想出一种方式
// 在这个遍历结束后可以区分，哪些元素被经过了多次即可，由于数组元素具有1 ≤ a[i] ≤ n
// 这样的范围，那其实我们当每次经过一个元素时，给他加上n，当遍历结束时，我们再次遍历数组
// 那些数值超过2n的元素索引+1，对应的就是我们的出现了两次的元素。
vector<int> res;
if(nums.empty()) return res;
int n=nums.size();
for(int i=0;i<n;i++){
    int index=(nums[i]-1)%n;//对遍历两次的数来说已经加了n，所以需要对n取余，防止数字越界
    nums[index]+=n;         //对应位置加n
}
for(int i=0;i<n;i++){
    //出现两次，则对应位置大于2n
    if(nums[i]>2*n)
        res.push_back(i+1);
}
return res;