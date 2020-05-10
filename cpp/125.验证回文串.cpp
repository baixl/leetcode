/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
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
            if (!((s[i] >= '0' && s[i] <= '9') ||
                  (s[i] >= 'a' && s[i] <= 'z'))) {
                i++;
            } else if (!((s[j] >= '0' && s[j] <= '9') ||
                         (s[j] >= 'a' && s[j] <= 'z'))) {
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
};
