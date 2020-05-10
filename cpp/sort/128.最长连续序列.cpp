/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution {
   public:
    // 方法1 ：先排序，然后遍历，这个方法时间超过O(n)

    //方法2： 使用hash_set 的唯一性解决
    // 1、 先将所有元素塞入hash_set
    // 2、遍历元素， max_length =1 ,然后依次遍历比当前元素 -1， +1 的值是否在hash_set 中，
    // 3、遍历过程中，删除元素
    // 4、更新max_leneght
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        unordered_set<int> set;
        for (auto& num : nums) {
            set.insert(num);
        }

        int max = 0;
        for (int i = 0; i < nums.size(); i++) {
            // set中没找到，则说明前面可能已经删除了
            int num = nums[i];
            if (set.find(num) == set.end()) {
                continue;
            }
            int max_length = 1;
            set.erase(num);

            int next = num + 1;
            while (set.find(next) != set.end()) {  //向右找
                max_length++;
                set.erase(next);
                next++;
            }

            int pre = num - 1;
            while (set.find(pre) != set.end()) {  //向右找
                max_length++;

                set.erase(pre);
                pre--;
            }
            if (max_length > max) {
                max = max_length;
            }
        }
        return max;
    }
};
