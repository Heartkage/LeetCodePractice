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
            val regexString : String = regexCharArray.concatToString()
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
        routeTrace[beginWord] = true
        routeDistance[beginWord] = 0
        wordList.forEach{
            it.addPath(wordList, availableRoute)
            routeTrace[it] = false
            routeDistance[it] = Int.MAX_VALUE
        }

        PrintRoutes(availableRoute)
        var searchList : ArrayList<String> = arrayListOf();
        searchList.add(beginWord)


        while(!searchList.isEmpty())
        {

        }

        return 0
    }
}

fun main() {
    val s : Solution = Solution()

    val wordList : List<String> = listOf("hot","dot","dog","lot","log","cog")

    s.ladderLength("hit", "cog", wordList)

}