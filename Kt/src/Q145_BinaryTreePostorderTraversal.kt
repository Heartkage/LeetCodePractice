class Solution145 {
    fun postorderTraversal(root: TreeNode?): List<Int> {
        var answers : MutableList<Int> = mutableListOf()

        var nodeStack : Stack<TreeNode> = Stack()
        nodeStack.push(root)

        while(nodeStack.isNotEmpty())
        {
            var current : TreeNode? = nodeStack.pop()
            if(current != null)
            {
                if(current.left == null && current.right == null)
                    answers.add(current.`val`)
                else
                {
                    nodeStack.add(TreeNode(current.`val`))
                    if(current.right != null)
                        nodeStack.push(current.right)
                    if(current.left != null)
                        nodeStack.push(current.left)
                }
            }
        }
        return answers
    }
}