#include <vector>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int anchor=0, right=0, res=0;
        for (; right < nums.size(); right++){
            if (right > 0 && nums[right - 1] >= nums[right]){
                anchor = right;
            }
            res = max(res, right - anchor + 1);
        }
        return res;
    }
};


