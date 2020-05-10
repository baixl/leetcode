package leetcode;

import leetcode.domain.TreeNode;

/**
 * author：baixiaoling
 * date: 2018/1/5
 * <p>
 * description:
 * 解题思路：
 * 递归判断，先序遍历，递归判断每个节点的值是否相等，递归退出条件是：
 * 1 遍历到了叶子节点，且都未空
 * 2 相同位置有一个节点为空，一个不为空
 * 3 相同位置节点元素的值不相等
 */
public class _100_sameTree {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }

    public static void main(String[] args) {
        _100_sameTree object = new _100_sameTree();
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(3);
        TreeNode root2 = new TreeNode(1);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(3);
        System.out.println(object.isSameTree(root1, root2));
    }
}
