package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/13
 * <p>
 * description:
 */
public class _11_ContainerWithMostWater {
    /*
    暴力解法 ,O(n^2)，无法通过leetcode大集合case
     */
    public int maxArea2(int[] height) {
        int max = 0;
        for (int i = 0; i < height.length; i++) {
            for (int j = i + 1; j < height.length; j++) {
                int currentWater = (j - i) * Math.min(height[i], height[j]);
                if (max < currentWater) {
                    max = currentWater;
                }
            }
        }
        return max;
    }

    /*
    O(n):使用两个指针 i，j分别指向数组的首位，
    ai<aj: i++
    ai>=aj:i--
    解释：当ai<aj时，短板在i，无论如何移动j（向前或向后），都不可能找到比当前area更大的j，只能通过移动i来使得面积更大
    反之亦然。
     */
    public int maxArea(int[] height) {
        int max = 0;
        int i = 0, j = height.length - 1;
        while (i < j) {
            int area = (j - i) * Math.min(height[j], height[i]);
            if (area > max) {
                max = area;
            }
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return max;
    }

    public static void main(String[] args) {
        int[] test = {1, 1};
        _11_ContainerWithMostWater object = new _11_ContainerWithMostWater();
        System.out.println(object.maxArea(test));
    }
}
