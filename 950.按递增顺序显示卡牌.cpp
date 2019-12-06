/*
 * @lc app=leetcode.cn id=950 lang=cpp
 *
 * [950] 按递增顺序显示卡牌
 */
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
// 属于逆约瑟夫环问题，N个数字围成一圈。从0开始出圈，往后每次跳一个出一个。已知原序列按顺序0到N-1，求出圈序列。核心：跳过数字找下一个数字。我们要做的是：从0到N-1，依次填坑
// 处理这种问题倒着思考，把手上符合要求的手牌动作回放到牌组中，牌组的顺序就是我们希望的顺序
// 约瑟夫环使用的数据结构是数组，而此题使用的数据结构是队列，因为两者动作回放不同，后者是把最后一个元素放到第一个，涉及到对整个数据结构的修改，用队列比较合适
// 这里答案用了数组作为数据结构来处理逆约瑟夫环问题，那就需要对跳过的坑位进行记录

// @lc code=start
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int N = deck.size();
        vector<int> res(N, 0);
        res[0] = deck[0];
        int i = 0; // 记录坑的位置
        int j = 1; // 要往坑里填的数
        while (j < N) {
            int empty = 0; // 用empty作为标志位，记录跳过的个数
            while (empty < 2) { // 不能i = i + 2;如果是偶数，那么会有一半数不会被更新 2.要忽略填过的数
                i = (i + 1) % N;
                if (res[i] == 0)
                    ++empty;
            }
            // 在剩余的空位中找到第二个空位放下一个较大的数即可
            res[i] = deck[j++];
        }
        return res;
    }
};
// @lc code=end

class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        if (deck == null || deck.length < 1) {
            return deck;
        }

        Arrays.sort(deck);// 得到升序排列的数组

        Queue<Integer> queue = new LinkedList<>();
        for (int i = deck.length - 1;i >= 0;i--) {// 倒着遍历，便是按降序访问
            queue.add(deck[i]);// 选最大值插入队列
            if (i == 0) {// 数组中所有元素均在队列中，退出过程
                break;
            }

            queue.add(queue.poll());// 将队头元素插入到队尾中
        }

        for (int i = deck.length - 1;i >= 0;i--) {
            deck[i] = queue.poll();// 倒回去，得到answer
        }

        return deck;
    }
}
