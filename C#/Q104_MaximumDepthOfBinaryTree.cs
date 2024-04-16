using Uitilities;
public class Solution104 {
    public int MaxDepth(TreeNode root) {
        Queue<TreeNode> bfs = new Queue<TreeNode>();
        bfs.Enqueue(root);
        int depth = 0;
        int currentCount = 1;
        while(bfs.Count > 0){
            TreeNode node = bfs.Dequeue();
            if(node != null){
                if(node.left != null)
                    bfs.Enqueue(node.left);
                if(node.right != null)
                    bfs.Enqueue(node.right);
                currentCount--;
            }
            if(currentCount == 0){
                currentCount = bfs.Count;
                depth++;
            }
        }
        return depth;
    }

    public int MaxDepthVer2(TreeNode root){
        if(root == null)
            return 0;
        else
            return Math.Max(MaxDepthVer2(root.left), MaxDepthVer2(root.right)) + 1;
    }
}