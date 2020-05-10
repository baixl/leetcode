package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/26
 * <p>
 * description:
 * The count-and-say sequence is the sequence of integers with the first five terms as following:
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth term of the count-and-say sequence.
 * Note: Each term of the sequence of integers will be represented as a string.
 * Example 1:
 * <p>
 * Input: 1
 * Output: "1"
 * Example 2:
 * <p>
 * Input: 4
 * Output: "1211"
 */
public class _38_CountandSay {
    public String countAndSay(int n) {
        if (n <= 0) return "";
        String s = "1";
        for (int i = 1; i < n; i++) {
            int cnt = 1;
            StringBuilder tmp = new StringBuilder();
            for (int j = 1; j < s.length(); j++) {
                if (s.charAt(j) == s.charAt(j - 1)) {
                    cnt++;
                } else {
                    tmp.append(cnt).append(s.charAt(j - 1));
                    cnt = 1;
                }
            }
            tmp.append(cnt).append(s.charAt(s.length() - 1));
            s = tmp.toString();
        }
        return s;

    }

    public static void main(String[] args) {
        _38_CountandSay object = new _38_CountandSay();
        System.out.println(object.countAndSay(5));
    }

}
