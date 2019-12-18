#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums){
        int n = nums.size(), ans = INT_MAX;
        int left, sum;
        for (int right = 0; right < n; right++){
            sum += nums[right];
            while (sum >= s)
            {
                ans = min(ans, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return (ans != INT_MAX) ? ans : 0;
    }
}











