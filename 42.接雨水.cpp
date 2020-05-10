/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 *
 * https://leetcode-cn.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (49.55%)
 * Likes:    1140
 * Dislikes: 0
 * Total Accepted:    85.7K
 * Total Submissions: 170.2K
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * 给定 n 个非负整数表示每个宽度为 1
 * 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
 *
 *
 *
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6
 * 个单位的雨水（蓝色部分表示雨水）。 感谢 Marcos 贡献此图。
 *
 * 示例:
 *
 * 输入: [0,1,0,2,1,0,1,3,2,1,2,1]
 * 输出: 6
 *
 */

// @lc code=start

class Solution {
   public:
    /***************************************************
     * 解题思路：
     * 方法1： 暴力解法，
     * 思路：针对每个位置，计算当前位置能存放的水的容量，即等于左右两侧比当前位置大的桩的高度差
     *  1、初始化 ans=0
     *  2、对每个位置，计算当前位置向左右遍历的最高桩， max_left=0, max_right=0
     *  max_left = max(max_left, height[j]);
     *  max_right = max(max_right, height[j]);
     *  3、当前位置所能存放的水的量为
     *  min(max_left,max_right)−height[i] . 将其加加到ans下即可
     *
     *  时间O(n2)
     ***************************************************/
    int trap1(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        if (size <= 1) return ans;
        for (auto i = 1; i < size; i++) {
            int max_left = 0, max_right = 0;
            for (auto j = i; j >= 0; j--) {
                max_left = max(max_left, height[j]);
            }
            for (auto j = i; j < size; j++) {
                max_right = max(max_right, height[j]);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
    /***************************************************
     * 方法1： 动态规划
     * 动态规划的思路是用空间换时间，将遍历中用到的临时数据暂存
     * 在方法1暴力法中，求每个位置的最左
     *最右最大值，都需要一遍扫描，这是暴力法耗时的关键
     *
     * 可以先统计每个位置最左、最右的最大值，放到临时数组中。
     * 1、初始化临时数组 left_max, right_max
     * left_max[i]存放 数组中下标i左侧的最大高度
     * right_max[i]存放 数组中下标i右侧的最大高度
     *
     * 空间O(N), 时间O(n)
     *
     ***************************************************/
    int trap2(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        if (size <= 1) return ans;
        vector<int> left_max(size), right_max(size);

        left_max[0] = height[0];
        right_max[size - 1] = height[size - 1];
        for (auto i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);  // 状态转移
        }
        for (auto i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);  // 状态转移
        }

        for (auto i = 1; i < size; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }

        return ans;
    }
    /***************************************************
     * 方法3： 使用栈 TODO:
     * 有点绕，栈需要单独专项练习
     *https://leetcode-cn.com/problems/trapping-rain-water/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-8/
     *
     ***************************************************/
    int trap3(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        if (size <= 1) return ans;
        stack<int> st;
        int cur_index = 0;
        while (cur_index < size) {
            while (!st.empty() && height[cur_index] > height[st.top()]) {
                // 当前元素比栈顶大，需要出栈并且计算当前可以存的水量
                int top = st.top();
                st.pop();
                if (st.empty()) break;
                int dis = cur_index - st.top() - 1;
                int bound =
                    min(height[cur_index], height[st.top()]) - height[top];
                ans += dis * bound;
            }
            st.push(cur_index++);
        }

        return ans;
    }
    /***************************************************
     * 方法4： 双指针
     * 直接看代码吧，
     ***************************************************/
    int trap(vector<int>& height) {
        int ans = 0;
        int size = height.size();
        if (size <= 1) return ans;
        int left = 0, right = size - 1;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                } else {
                    ans += left_max - height[left];
                }
                left++;
            } else {
                if (height[right] >= right_max) {
                    right_max = height[right];

                } else {
                    ans += right_max - height[right];
                }
                right--;
            }
        }

        return ans;
    }
};
// @lc code=end
