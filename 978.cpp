#include <vector>
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int anchor = 0, right = 1, res = 0;
        for (; right < A.size();right++){
            if(A[right] > A[right - 1] && A[right] > A[right + 1] && right + 1 < A.size()){
                res = max(res, right - anchor + 1);
                right++; // 实际上right = right + 2
            }
            else if(right + 1 < A.size()){
                anchor = right;
            }
        }
        return res;
    }
};

