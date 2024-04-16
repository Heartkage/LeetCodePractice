class Solution {
    private val DIRECTION_COUNT = 4
    private val x_direction : List<Int> = listOf(-1, 0, 1, 0)
    private val y_direction : List<Int> = listOf(0, -1, 0, 1)

    private var m_visitedPoints : MutableList<BooleanArray> = mutableListOf()
    private var m_visitedPath : MutableSet<Pair<Int, Int>> = mutableSetOf()
    private var foundExit : Boolean = false
    fun solve(board: Array<CharArray>): Unit {
        board.forEach {
            m_visitedPoints.add(BooleanArray(it.count()) { false })
        }

        for(y in 0 until board.count()){
            for(x in 0 until board[y].count()){
                if(board[y][x] == 'O' && !m_visitedPoints[y][x]){
                    foundExit = false
                    m_visitedPath.clear()
                    dfs(board, x, y)
                    if(!foundExit){
                        m_visitedPath.forEach{
                            board[it.second][it.first] = 'X'
                        }
                    }
                }
            }
        }
    }

    fun dfs(_board: Array<CharArray>, _x: Int, _y: Int) : Unit{
        val point : Pair<Int, Int> = Pair(_x, _y)
        if(m_visitedPoints[_y][_x])
            return
        else
        {
            m_visitedPoints[_y][_x] = true
            m_visitedPath.add(point)
        }

        for(i in 0 until DIRECTION_COUNT)
        {
            val nextX = _x + x_direction[i]
            val nextY = _y + y_direction[i]
            if(!(nextX in 0 until _board[_y].count() && nextY in 0 until _board.count()))
                foundExit = true
            else if(_board[nextY][nextX] == 'O')
                dfs(_board, nextX, nextY)
        }
    }
}

fun main() {
    val s : Solution = Solution()

    var board : Array<CharArray> = arrayOf(
        charArrayOf('O','O','X','X'),
        charArrayOf('X','O','O','X'),
        charArrayOf('X','X','O','X'),
        charArrayOf('X','O','X','X'),
        charArrayOf('X','X','X','X'))

    board.printAll(){
        println("Board Before:")
    }
    s.solve(board)
    board.printAll(){
        println("Board After:")
    }

}