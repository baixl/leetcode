package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/26
 * <p>
 * description:
 * Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 * For the purpose of this problem, we define empty string as valid palindrome.
 */
public class _125_ValidPalindrome {
    /*
    判断字符串是否是回文：这道题目需要忽略：非阿拉伯（字母和数字）字符,并且忽略大小写
    使用两个指针，从前后向中间夹逼
     */
    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) return true;

        s = s.toLowerCase();
        int left = 0, riht = s.length() - 1;
        while (left <= riht) {
            if ((s.charAt(left) < 'a' || s.charAt(left) > 'z') &&
                    (s.charAt(left) < '0' || s.charAt(left) > '9')) {
                left++;
                continue;
            }
            if ((s.charAt(riht) < 'a' || s.charAt(riht) > 'z') &&
                    (s.charAt(riht) < '0' || s.charAt(riht) > '9')) {
                riht--;
                continue;
            }
            if (s.charAt(left) == s.charAt(riht)) {
                left++;
                riht--;
            } else {
                return false;
            }
        }
        return true;
    }
}
