/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        preOrder(root, res);
        return res;
    }
    public void preOrder(TreeNode root, List<Integer> res){
        if(root != null){
            res.add(root.val);
            if(root.left != null)
                preOrder(root.left, res);
            if(root.right != null)
                preOrder(root.right, res);
        }
    }
}