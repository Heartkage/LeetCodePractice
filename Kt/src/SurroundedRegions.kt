class Solution {
    fun solve(board: Array<CharArray>): Unit {

    }
}

fun main() {
    val s : Solution = Solution()

    var board : Array<CharArray> = arrayOf(
        charArrayOf('X','X','X','X'),
        charArrayOf('X','O','O','X'),
        charArrayOf('X','X','O','X'),
        charArrayOf('X','O','X','X'))

    board.printAll(){
        println("Board Before:")
    }
    s.solve(board)
    board.printAll(){
        println("Board After:")
    }

}