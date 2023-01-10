using Uitilities;
public class Solution100 {
    public bool IsSameTree(TreeNode p, TreeNode q) {
        Stack<TreeNode> p1 = new Stack<TreeNode>();
        Stack<TreeNode> q1 = new Stack<TreeNode>();
        p1.Push(p);
        q1.Push(q);
        while(p1.Count > 0 || q1.Count > 0){
            TreeNode currentP = p1.Peek(); p1.Pop();
            TreeNode currenQ = q1.Peek(); q1.Pop();

            if(currentP == null && currenQ == null)
                continue;
            else if(currentP == null && currenQ != null)
                return false;
            else if(currentP != null && currenQ == null)
                return false;
            else if(currentP?.val != currenQ?.val)
                return false;
            
            if(currentP != null){
                p1.Push(currentP.right);
                p1.Push(currentP.left);
            }

            if(currenQ != null){
                q1.Push(currenQ.right);
                q1.Push(currenQ.left);
            }
        }
        return true;
    }
}