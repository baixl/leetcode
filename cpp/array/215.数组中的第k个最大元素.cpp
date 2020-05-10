/*
 * @lc app=leetcode.cn id=215 lang=cpp
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 * Medium (58.60%)
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 示例 1:
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 *
 * 示例 2:
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 *
 * 说明:
 *
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 *
 */

// @lc code=start
class Solution {
   public:
    /*
    方法1： 快排分区法
    */
    int findKthLargest1(vector<int>& nums, int k) {
        if (nums.empty() || k <= 0) return 0;
        int left = 0, right = nums.size() - 1;
        int index = partition(nums, left, right);
        while (index != k - 1) {
            if (index > k - 1) {
                right = index - 1;
            } else {
                left = index + 1;
            }
            index = partition(nums, left, right);
        }
        return nums[index];
    }
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        while (left < right) {
            // 找到一个比pivot 大的元素
            while (left < right && nums[right] <= pivot) {
                right--;
            }
            nums[left] = nums[right];
            // 找到一个比
            while (left < right && nums[left] >= pivot) {
                left++;
            }
            nums[right] = nums[left];
        }
        nums[left] = pivot;
        return left;
    }

    /******************
    方法2： 堆排序
    */
    int findKthLargest2(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());  // 默认大顶堆
        int result = 0;
        for (auto i = 0; i < k; i++) {
            result = nums.front();
            pop_heap(nums.begin(), nums.end());  // 将堆顶元素移到末尾
            nums.pop_back();                     // 弹出末尾元素
        }
        return result;
    };
    // 使用优先级队列 priority_queue
    int findKthLargest(vector<int>& nums, int k) {
        // 创建小顶堆
        priority_queue<int, std::vector<int>, std::greater<int>> q;
        int i = 0;
        for (i = 0; i < k; i++) {
            q.push(nums[i]);
        }
        for (i = k; i < nums.size(); i++) {
            q.push(nums[i]);
            q.pop();
        }

        return q.top();
    };
};
// @lc code=end
