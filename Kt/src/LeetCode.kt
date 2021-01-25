class TreeNode(var `val`: Int) {
    var left: TreeNode? = null
    var right: TreeNode? = null
}

class Solution {
    fun sumNumbers(root: TreeNode?): Int {
        return RecursiveAddNumber(root, 0)
    }

    fun RecursiveAddNumber(node: TreeNode?, parentValue: Int): Int{
        return if(node == null)
            0
        else if(node.left == null && node.right == null)
            node.`val` + parentValue*10
        else {
            var answer = 0
            val nextValue = parentValue*10 + node.`val`
            answer += RecursiveAddNumber(node.left, nextValue)
            answer += RecursiveAddNumber(node.right, nextValue)
            answer
        }
    }
}

fun main() {
    val solution : Solution

}