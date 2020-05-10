/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 *
 * https://leetcode-cn.com/problems/sliding-window-maximum/description/
 * Hard (44.99%)
 * 给定一个数组
 * nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的
 * k 个数字。滑动窗口每次只向右移动一位。
 *
 * 返回滑动窗口中的最大值。
 *
 * 进阶：
 * 你能在线性时间复杂度内解决此题吗？
 *
 * 示例:
 *
 * 输入: nums = [1,3,-1,-3,5,3,6,7], 和 k = 3
 * 输出: [3,3,5,5,6,7]
 * 解释:
 *
 * ⁠ 滑动窗口的位置                最大值
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 *
 *
 * 提示：
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start
/*
方法1： 首先想到的是创建一个大小为k的堆（大顶堆）， 然后依次入堆，
选堆的顶元素就是滑动窗口的最大值 这种方法， 每次都有堆的移动，
可以实现，但性能不是最好 方法2：
剑指offer上题解，这里关键是想能否用O(1)获取滑动窗口的最大值。
    解法是使用双端队列Deque
    1、并不是将滑动窗口中每个元素都存入队列中，而是只把有可能存为滑动黄口最大值的数值存入到一个双端队列中。
        实际上，deque存放的是可能是最大值的数字的下标
    2、先看数组的前k和元素：
        若双端队列非空， 则需要判断当前值是否和双端队列左侧所指元素的大小。
        若当前值比左侧的所指元素大，则双端队列左侧所指元素肯定不是最大值，直接删除
    3、然后从k到nums.size()遍历
        3.1、先做2的判断
        3.3、判断双端队列头部所指元素是否超过了滑动窗口的大小
*/
class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if (nums.size() < k || k <= 0) return result;
        deque<int> q;                   // 存放可能是最大值的下标
        for (auto i = 0; i < k; i++) {  //
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        for (auto i = k; i < nums.size(); i++) {
            result.push_back(nums[q.front()]);  // 上一个窗口的最大值
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            while (!q.empty() && i - q.front() >= k) {  // 当前最大值已失效
                q.pop_front();
            }
            q.push_back(i);
        }
        result.push_back(nums[q.front()]);  // 最后一个窗口的最大值
        return result;
    }
};
// @lc code=end
