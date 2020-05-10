package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/26
 * <p>
 * description:
 * Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11"
 * b = "1"
 * Return "100"
 */
public class _67_AddBinary {
    public String addBinary(String a, String b) {
        if (a == null || a.length() == 0) return b;
        if (b == null || b.length() == 0) return a;

        int alength = a.length();
        int blength = b.length();
        int max = alength > blength ? alength : blength;
        a = reverse(a);
        b = reverse(b);
        int carray = 0;
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < max; i++) {
            int ai = i < a.length() ? a.charAt(i) - '0' : 0;
            int bi = i < b.length() ? b.charAt(i) - '0' : 0;
            int val = (ai + bi + carray) % 2;
            carray = (ai + bi + carray) / 2;
            result.append(val);
        }
        if (carray == 1) {
            result.append(carray);
        }
        return reverse(result.toString());
    }

    private String reverse(String s) {
        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            sb.append(s.charAt(i));
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        _67_AddBinary object = new _67_AddBinary();
        String a = "11";
        String b = "1";
        System.out.println(object.addBinary(a, b));
    }
}
