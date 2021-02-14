import java.util.*

class TreeNode(var `val`: Int) {
     var left: TreeNode? = null
     var right: TreeNode? = null
}

class Solution {
    fun preorderTraversal(root: TreeNode?): List<Int> {
        var answers : MutableList<Int> = mutableListOf()

        var nodeStack : Stack<TreeNode> = Stack()
        nodeStack.push(root)

        while(nodeStack.isNotEmpty())
        {
            var current : TreeNode? = nodeStack.pop()
            if(current != null)
            {
                answers.add(current.`val`)
                nodeStack.push(current.right)
                nodeStack.push(current.left)
            }
        }

        return answers
    }
}

fun main() {
    val solution : Solution = Solution()

}