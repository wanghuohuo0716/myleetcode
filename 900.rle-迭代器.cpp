/*
 * @lc app=leetcode.cn id=900 lang=cpp
 *
 * [900] RLE 迭代器
 */
#include <vector>
#include <unordered_set>
using namespace std;
// 不是一次删除，而是可以多次操作，需要维护上次删除的位置，在RLE迭代器中位置等于元素和其已经删除的次数
// 维护下一个元素的位置和删除次数而不是真的修改原数组，记录删除的次数，当删除的次数达到n时即完成操作，如果下一个元素超出数组边界，则返回-1
// 在删最后一个元素之前，肯定把之前的所有元素都删光了

// @lc code=start
class RLEIterator {
public:
    vector<int> A;
    int i, q;
    RLEIterator(vector<int>& A) {
        this->A = A;
        i = q = 0;
    }

    int next(int n) {
        while (i < A.size()) {
            if (q + n > A[i]) {
                n -= A[i] - q;
                q = 0;
                i += 2;
            } else {
                q += n;
                return A[i+1];
            }
        }

        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(A);
 * int param_1 = obj->next(n);
 */
// @lc code=end

