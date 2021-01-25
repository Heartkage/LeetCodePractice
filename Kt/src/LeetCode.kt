 class TreeNode(var `val`: Int) {
     var left: TreeNode? = null
     var right: TreeNode? = null
}

 inline fun Array<CharArray>.printAll(lambda : () -> Unit)
 {
     lambda.invoke()
     this.forEach {
         println(it)
     }
 }

fun main() {

}