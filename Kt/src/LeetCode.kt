 class TreeNode(var `val`: Int) {
     var left: TreeNode? = null
     var right: TreeNode? = null
}

class Solution {
    fun canCompleteCircuit(gas: IntArray, cost: IntArray): Int {
        var gasTable : MutableList<Int> = mutableListOf()

        for(i in gas.indices)
            gasTable.add(gas[i] - cost[i])

        var startIndex = -1
        var index = 0
        while(index < gasTable.size)
        {
            if(gasTable[index] < 0)
                index++
            else
            {
                var leftOverGas = 0
                var i = 0
                for(i in gasTable.indices)
                {
                    val loopIndex = (index + i) % gasTable.size
                    leftOverGas += gasTable[loopIndex];
                    if(leftOverGas < 0)
                        break;
                }
                if(leftOverGas >= 0)
                    startIndex = index;

                //println("Current Index: {$index}")
                index += i + 1
            }
        }
        return startIndex
    }
}

fun main() {
    val solution : Solution = Solution()
    val gas : IntArray = intArrayOf(2, 3, 4)
    val cost : IntArray = intArrayOf(3, 4, 3)

    println(solution.canCompleteCircuit(gas, cost))
}