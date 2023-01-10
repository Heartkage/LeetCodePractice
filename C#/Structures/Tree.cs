namespace Uitilities{
    //Definition for a binary tree node.
    public class TreeNode{
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public class TestTree{
        public List<TreeNode> GenerateTestCase(int _amount = 1, int _depth = 1, bool _isSameVal = true){
            List<TreeNode> nodes = new List<TreeNode>();
            
            for(int i = 0; i < _amount; i++){
                int currentVal = 1;
                Queue<TreeNode> treeQueue = new Queue<TreeNode>();
                var rand = new System.Random();
                for(int j = 0; j < Math.Pow(2, _depth-1); j++){
                    int nextVal = _isSameVal ? currentVal : ((rand.Next()%2 == 0) ? currentVal : 87);
                    TreeNode node = new TreeNode(nextVal);
                    treeQueue.Enqueue(node);
                    currentVal++;
                }
                int n = treeQueue.Count;
                while(n > 1){
                    TreeNode nodeL = treeQueue.Dequeue();
                    TreeNode nodeR = treeQueue.Dequeue();
                    TreeNode node = new TreeNode(currentVal++, nodeL, nodeR);
                    treeQueue.Enqueue(node);
                    n = treeQueue.Count;
                }
                
                if(treeQueue.Count == 1)
                    nodes.Add(treeQueue.Dequeue());
                else
                    nodes.Add(null);
            }


            return nodes;
        }

        public void PrintPreOrderTree(TreeNode head){
            Stack<TreeNode> s = new Stack<TreeNode>();
            s.Push(head);
            while(s.Count > 0){
                var cur  = s.Peek();
                s.Pop();
                if(cur != null){
                    Console.WriteLine(cur.val);
                    s.Push(cur.right);
                    s.Push(cur.left);
                }
            }
        }
    }
}