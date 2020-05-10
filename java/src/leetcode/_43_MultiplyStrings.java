package leetcode;

import java.util.ArrayList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2017/12/20
 * <p>
 * description:
 * Given two non-negative integers num1 and num2 represented as strings,
 * return the product of num1 and num2.
 * Note:
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * <p>
 * 题意：两个字符串表示的非负整数相乘，用字符串的形式返回积。
 * 思路：逐位相乘。
 * 关键：中间结果如何保存
 */
public class _43_MultiplyStrings {
    public String multiply(String num1, String num2) {
        // todo
        if (num1 == null || num1.length() == 0 || num1.equals("0")
                || num2 == null || num2.length() == 0 || num2.equals("0")) return "0";

        int[] restable = new int[num1.length() + num2.length()]; // 存放乘积，低位存低位

        if (num1.length() < num2.length()) {
            return multiply(num2, num1);
        }

        int len1 = num1.length();
        int len2 = num2.length();
        int len3 = len1 + len2;
        int[] num3 = new int[len3];// 保存结果，低位保存结果的高位

        int carry, product;
        for (int i = len1 - 1; i >= 0; i--) {
            carry = 0;

            int j = 0;
            for (j = len2 - 1; j >= 0; j--) {
                product = carry + num3[i + j + 1] +
                        Character.getNumericValue(num1.charAt(i)) *
                                Character.getNumericValue(num2.charAt(j));
                num3[i + j + 1] = product % 10;
                carry = product / 10;
            }
            num3[i + j + 1] = carry;
        }

        StringBuilder sb = new StringBuilder();
        int i = 0;
        while (i < len3 - 1 && num3[i] == 0)
            i++;
        while (i < len3) {
            sb.append(num3[i++]);
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        _43_MultiplyStrings object = new _43_MultiplyStrings();
        System.out.println(object.multiply("99", "99"));
    }
}
