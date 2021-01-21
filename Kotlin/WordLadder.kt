import java.lang.StringBuilder
import java.text.SimpleDateFormat
import java.util.*
import kotlin.collections.ArrayList

class Solution {
    inline fun String.addPath(_routeHashMap: MutableMap<String, MutableList<String>>, _availableRoute : MutableMap<String, MutableList<String>>)
    {
        val targetWord :String = this;
        //println("This Word: $targetWord")
        var routes : MutableList<String> = mutableListOf()
        _availableRoute[targetWord] = routes

        for(i in 0 until (targetWord.length))
        {
            val sb = StringBuilder()
            sb.append(targetWord.substring(0, i)).append('.').append(targetWord.substring(i+1, targetWord.length))
            val modifiedString : String = sb.toString()
            //println("Modified String: $modifiedString")
            if(_routeHashMap.containsKey(modifiedString)) {
                var tempList : MutableList<String> = mutableListOf()
                _routeHashMap[modifiedString]?.forEach {
                    _availableRoute[it]?.add(targetWord)
                    tempList.add(it)
                }
                _routeHashMap[modifiedString]?.add(targetWord)
                if(_availableRoute.containsKey(targetWord))
                    _availableRoute[targetWord]?.addAll(tempList)
                else
                    _availableRoute[targetWord] = tempList
            }
            else
            {
                _routeHashMap[modifiedString] = mutableListOf()
                _routeHashMap[modifiedString]?.add(targetWord)
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
        val routeHashMap: MutableMap<String, MutableList<String>> = mutableMapOf()

        val routeTrace : MutableMap<String, Boolean> = mutableMapOf()
        val routeDistance : MutableMap<String, Int> = mutableMapOf()

        val sdf = SimpleDateFormat("hh:mm:ss")
        var now = sdf.format(Date())
        println("Start Time: $now")

        beginWord.addPath(routeHashMap, availableRoute);
        routeTrace[beginWord] = false
        routeDistance[beginWord] = 0
        wordList.forEach{
            if(it != beginWord)
            {
                it.addPath(routeHashMap, availableRoute)
                routeTrace[it] = false
                routeDistance[it] = Int.MAX_VALUE
            }
        }

        now = sdf.format(Date())
        println("Create Route Done Time: $now")

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

        now = sdf.format(Date())
        println("Complete Time: $now")
        return if (foundTarget) routeDistance[endWord]!!+1 else 0
    }
}

fun main() {
    val s : Solution = Solution()
    val wordList : List<String> = listOf("cm","so","sm","ci","ca","sq")
    println(s.ladderLength("qa", "sq", wordList))
}