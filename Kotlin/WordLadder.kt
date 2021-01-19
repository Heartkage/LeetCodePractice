class Solution {
    inline fun String.addPath(_wordList: List<String>, _availableRoute : MutableMap<String, MutableList<String>>)
    {
        val targetWord :String = this;
        //println("This Word: $targetWord")
        var routes : MutableList<String> = mutableListOf()
        _availableRoute[targetWord] = routes

        for(i in 0 until (targetWord.length))
        {
            val regexCharArray = targetWord.toCharArray()
            regexCharArray[i] = '.'
            val regexString : String = String(regexCharArray)
            //println("Modified Word: $regexString")
            val r1 = Regex(regexString)

            _wordList.forEach{
                if(it != targetWord)
                {
                    if(r1.matches(it))
                    {
                        _availableRoute[targetWord]?.add(it)
                    }
                }
            }
        }

    }

    fun PrintRoutes(availableRoute: MutableMap<String, MutableList<String>>){
        availableRoute.forEach{
            println("---Current Word (${it.key}) has ${it.value.count()} routes---")
            print("[Words]: ")
            it.value.forEach{
                print("${it} ")
            }
            println()
            println("--End of This Word--")
        }
    }

    fun ladderLength(beginWord: String, endWord: String, wordList: List<String>): Int {
        val availableRoute: MutableMap<String, MutableList<String>> = mutableMapOf()
        val routeTrace : MutableMap<String, Boolean> = mutableMapOf()
        val routeDistance : MutableMap<String, Int> = mutableMapOf()

        beginWord.addPath(wordList, availableRoute);
        routeTrace[beginWord] = false
        routeDistance[beginWord] = 0
        wordList.forEach{
            if(it != beginWord)
            {
                it.addPath(wordList, availableRoute)
                routeTrace[it] = false
                routeDistance[it] = Int.MAX_VALUE
            }
        }

        //PrintRoutes(availableRoute)
        var searchList : ArrayList<String> = arrayListOf();
        searchList.add(beginWord)

        var foundTarget : Boolean = false
        while(searchList.isNotEmpty())
        {
            // Find Shortest Distance
            var shortestPath : String = ""
            var shortestDistance = Int.MAX_VALUE
            searchList.forEach{
                if(!routeTrace[it]!!)
                {
                    val targetDistance = routeDistance[it] ?: Int.MAX_VALUE
                    if(targetDistance < shortestDistance)
                    {
                        shortestDistance = targetDistance
                        shortestPath = it
                    }
                }
            }

            if(shortestPath != "")
            {
                searchList.remove(shortestPath)
                routeTrace[shortestPath] = true

                availableRoute[shortestPath]!!.forEach {
                    if(!routeTrace[it]!!)
                    {
                        val nextDistance = shortestDistance + 1
                        if (routeDistance[it]!! > nextDistance)
                            routeDistance[it] = nextDistance
                        searchList.add(it)
                        if(it == endWord)
                            foundTarget = true
                    }
                }
            }
            else
                break

            if(foundTarget)
                break
        }

        return if (foundTarget) routeDistance[endWord]!!+1 else 0
    }
}

fun main() {
    val s : Solution = Solution()


    val wordList : List<String> = listOf("hot","dog","cog","pot","dot")
    println(s.ladderLength("hot", "dog", wordList))

}