using Uitilities;
public class Solution783 {
    private void BFS(TreeNode node, List<int> vals){
        if(node == null)
            return;
        BFS(node.left, vals);
        vals.Add(node.val);
        BFS(node.right, vals);
    }
    public int MinDiffInBST(TreeNode root) {
        List<int> vals = new List<int>();
        BFS(root, vals);
        int minimumVal = int.MaxValue;
        for(int i = 1; i < vals.Count; i++){
            if(vals[i] - vals[i-1] < minimumVal)
                minimumVal = vals[i] - vals[i-1];
        }
        return minimumVal;
    }
}