/*
 [9] 回文数
 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:
输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
 */
class Solution {
   public:
    bool isPalindrome(string s) {
        if (s.size() <= 1) {
            return true;
        }
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (!((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z'))) {
                i++;
            } else if (!((s[j] >= '0' && s[j] <= '9') || (s[j] >= 'a' && s[j] <= 'z'))) {
                j--;

            } else {
                if (s[i] != s[j]) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
    // 方法
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        string s = to_string(x);

        return isPalindrome(s);
    }
};
