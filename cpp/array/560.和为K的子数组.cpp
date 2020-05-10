/*
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :

数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
class Solution {
   public:
    /*
    方法1：暴力解法, 能过，但效率较低
    */
    int subarraySum1(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int res = 0;
        int temp = 0;
        for (auto i = 0; i < nums.size(); i++) {
            temp = 0;
            for (auto j = i; j < nums.size(); j++) {
                temp += nums[j];
                if (temp == k) {
                    res += 1;
                }
            }
        }
        return res;
    }
    /*
    方法2： 使用数组存放，到当前值得总和, 时间O(n2) 空间O(n)
    */
    int subarraySum2(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int res = 0;
        vector<int> sum_vec(nums.size() + 1, 0);  // sum_vec[i] 表示到i-1位置的和
        sum_vec[0] = 0;
        for (auto i = 1; i <= nums.size(); i++) {
            sum_vec[i] = sum_vec[i - 1] + nums[i - 1];
        }
        for (auto i = 0; i < nums.size(); i++) {
            for (auto j = i + 1; j <= nums.size(); j++) {
                if (sum_vec[j] - sum_vec[i] == k) {
                    res++;
                }
            }
        }

        return res;
    }
    /*
    方法3： 使用hash, 使用map存放 到nums[i] 的和sum[i]出现的次数。
    遍历数组，如果sum-k 在数组中，则将其次数加到最终结果上。
    */
    int subarraySum(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int res = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        int sum = 0;
        for (auto i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (map.find(sum - k) != map.end()) {
                res += map[sum - k];
            }

            if (map.find(sum) != map.end()) {
                map[sum]++;
            } else {
                map[sum] = 1;
            }
        }

        return res;
    }
};