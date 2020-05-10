/*
 * @lc app=leetcode.cn id=268 lang=cpp
 * [268] 缺失数字
给定一个包含 0, 1, 2, ..., n 中 n 个数的序列，找出 0 .. n 中没有出现在序列中的那个数。
示例 1:
输入: [3,0,1]
输出: 2
示例 2:
输入: [9,6,4,2,3,5,7,0,1]
输出: 8
说明:
你的算法应具有线性时间复杂度。你能否仅使用额外常数空间来实现?
 */
class Solution {
public:
    //由于只缺少一个数字, 对0到n求和， 然后减去nums的和
    int missingNumber2(vector<int>& nums) {
        int sum = 0;
        for (auto i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int n = nums.size();
        return n * (n + 1) /2 - sum;

    }
     // 暴力解法
    int missingNumber2(vector<int>& nums) {
        int n = nums.size();
        for (auto i =0; i <=n; i++) {
            if (find(nums.begin(), nums.end(), i) == nums.end()) {
                return i;
            }
        }
        return -1;
    }
};

