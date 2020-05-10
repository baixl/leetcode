/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (43.51%)
 * Likes:    441
 * Dislikes: 0
 * Total Accepted:    130.2K
 * Total Submissions: 299.2K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start
class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = 0;
        vector<int> result;
        for (int i = 0; i < digits.size(); i++) {
            int temp = carry + digits[i];
            if (i == 0) {
                temp += 1;
            }
            result.push_back(temp % 10);
            carry = temp / 10;
        }
        if (carry != 0) {
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

