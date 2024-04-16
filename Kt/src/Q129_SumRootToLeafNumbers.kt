class Solution129 {
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