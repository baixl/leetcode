package leetcode;

/**
 * author：baixiaoling
 * date: 2017/12/18
 * <p>
 * description:
 */
public class _26_RemoveDuplicatesfromSortedArray {
    /*
    https://siddontang.gitbooks.io/leetcode-solution/content/array/remove_duplicates_from_sorted_array.html
    1 使用左右两个指针，当有指针和左指针元素不相等时：复制右指针元素到左指针下一个位置，左指针加1
    不能使用额外的空间
     */
    public int removeDuplicates(int[] nums) {
        if (nums == null)
            return 0;
        if (nums.length == 1)
            return 1;
        int j = 0;
        for (int i = 1; i < nums.length; i++) {
            if (nums[j] != nums[i]) {
                nums[++j] = nums[i];
            }
        }
        return j + 1;
    }

    public static void main(String[] args) {
        _26_RemoveDuplicatesfromSortedArray obejct = new _26_RemoveDuplicatesfromSortedArray();
        int[] nums = {1, 1, 2};
        int ret = obejct.removeDuplicates(nums);
        System.out.println(ret);
    }
}
