/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] 常数时间插入、删除和获取随机元素
 */
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
// @lc code=start
class RandomizedSet {
public:
    unordered_set<int> s;
    string a;
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(s.find(val)==s.end())
        {
            s.insert(val);
            return true;
        }
        else
        {
            return false;
        }
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it=s.find(val);
        if(it==s.end())
        {
            return false;
        }
        else
        {
            s.erase(it);
            return true;
        }
    }

    /** Get a random element from the set. */
    int getRandom() {
        auto it=s.begin();
        advance(it,rand()%s.size());
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

