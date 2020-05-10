package leetcode;

import leetcode.domain.TreeNode;

import java.util.ArrayList;
import java.util.List;

/**
 * author：baixiaoling
 * date: 2018/1/7
 * <p>
 * description:
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * <p>
 * For example:
 * Given binary tree [1,null,2,3],
 * 1
 * \
 * 2
 * /
 * 3
 * return [1,3,2].
 * <p>
 * Note: Recursive solution is trivial, could you do it iteratively?
 * 二叉树的中序遍历
 */
public class _94_BinaryTreeInorderTraversal {
    List<Integer> result = new ArrayList<>();

    public List<Integer> inorderTraversal(TreeNode root) {

        if (root == null) return result;
        help(root);
        return result;
    }

    private void help(TreeNode node) {
        if (node == null) return;
        help(node.left);
        result.add(node.val);
        help(node.right);
    }


    // 不使用类的局部变量
    public List<Integer> inorderTraversal2(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;
        helper(res, root.left);
        res.add(root.val);
        helper(res, root.right);
        return res;

    }

    private void helper(List<Integer> res, TreeNode node) {
        if (node == null) return;
        helper(res, node.left);
        res.add(node.val);
        helper(res, node.right);
    }


    public static void main(String[] args) {
        _94_BinaryTreeInorderTraversal objecct = new _94_BinaryTreeInorderTraversal();
        TreeNode root = new TreeNode(1);
        TreeNode node1 = new TreeNode(2);
        TreeNode node2 = new TreeNode(3);
        node1.left = node2;
        root.right = node1;
        System.out.println(objecct.inorderTraversal(root));

    }
}
