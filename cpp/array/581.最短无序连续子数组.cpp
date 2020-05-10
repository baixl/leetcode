/*
 * [581] 最短无序连续子数组
 给定一个整数数组，你需要寻找一个连续的子数组，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
你找到的子数组应是最短的，请输出它的长度。
示例 1:

输入: [2, 6, 4, 8, 10, 9, 15]
输出: 5
解释: 你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。
说明 :

输入的数组长度范围在 [1, 10,000]。
输入的数组可能包含重复元素 ，所以升序的意思是<=。
 */
class Solution {
   public:
    // 思路： 先对整个数组排序，i 左到右  从j右到左遍历，直到找到值和原始数组不同的位置，  j-i+1 即为要求的值
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> new_nums(nums);
        sort(new_nums.begin(), new_nums.end());
        int i = 0, j = nums.size() - 1;

        while (i < nums.size() && nums[i] == new_nums[i]) {
            i++;
        }
        while (j > i && nums[j] == new_nums[j]) {
            j--;
        }
        return j - i + 1;
    }
};
