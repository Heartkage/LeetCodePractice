class Solution {
    fun candy(ratings: IntArray): Int {
        var ratingTable : MutableList<Pair<Int, Int>> = mutableListOf()
        for(i in ratings.indices)
            ratingTable.add(Pair(i, ratings[i]))
        ratingTable.sortBy {it.second}

        val candyTable : IntArray = IntArray(ratings.size) {0}

        for(i in ratingTable.indices)
        {
            val candyTableIndex = ratingTable[i].first
            val myRating = ratingTable[i].second

            var leftNeighborRating = Int.MAX_VALUE
            var rightNeighborRating = Int.MAX_VALUE
            if(candyTableIndex > 0)
                leftNeighborRating = ratings[candyTableIndex-1]
            if(candyTableIndex < ratings.size - 1)
                rightNeighborRating = ratings[candyTableIndex+1]

            var maximumCandy = 0
            if(myRating > leftNeighborRating)
                if(candyTable[candyTableIndex-1] > maximumCandy)
                    maximumCandy = candyTable[candyTableIndex-1]

            if(myRating > rightNeighborRating)
                if(candyTable[candyTableIndex+1] > maximumCandy)
                    maximumCandy = candyTable[candyTableIndex+1]

            candyTable[candyTableIndex] = maximumCandy + 1
        }

        var totalCandy = 0
        candyTable.forEach {
            print("{$it}, ")
            totalCandy += it
        }
        return totalCandy
    }
}

fun main() {
    val solution : Solution = Solution()
    val ratings : IntArray = intArrayOf(1, 0, 2)

    println(solution.candy(ratings))
}