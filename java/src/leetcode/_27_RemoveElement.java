package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/18
 * <p>
 * description:
 * <p>
 * Given an array and a value, remove all instances of that value in-place and return the new length.
 * Do not allocate extra space for another array, you must do this by modifying the
 * input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 * demo：
 * Given nums = [3,2,2,3], val = 3,
 * Your function should return length = 2, with the first two elements of nums being 2.
 */
public class _27_RemoveElement {

    /*
    同26
    使用左右指针，i j
    遍历数组，当碰到val和当前值相等时，第增i，当不相等时，将当前位置的值复制到j上。递增j
     */
    public int removeElement(int[] nums, int val) {
        if (nums == null)
            return 0;
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == val) {
                continue;
            }
            nums[j] = nums[i];
            j++;
        }
        return j;
    }

    public static void main(String[] args) {
        _27_RemoveElement object = new _27_RemoveElement();
        int nums[] = {1};
        System.out.println(object.removeElement(nums, 1));
    }
}
