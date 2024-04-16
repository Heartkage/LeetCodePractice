class Solution146(capacity: Int) {
    private var m_capacity : Int = capacity
    private var extraSpace : Int = 0
    var cache : IntArray = IntArray(3001) { -1 }
    var indexCache : IntArray = IntArray(3001) { 0 }
    var memoryQueue : Queue<Int> = LinkedList<Int>()

    fun get(key: Int): Int {
        if(cache[key] != -1)
            updateCache(key)
        return cache[key]
    }

    fun put(key: Int, value: Int) {
        updateCache(key, true)
        cache[key] = value
    }

    fun updateCache(key: Int, shouldDrop: Boolean = false) {
        if(indexCache[key] > 0)
            extraSpace++

        if(shouldDrop)
        {
            while(memoryQueue.size >= (m_capacity + extraSpace))
            {
                val dropKey = memoryQueue.remove()
                indexCache[dropKey]--
                if(indexCache[dropKey] > 0)
                    extraSpace--
                else
                    cache[dropKey] = -1
            }
        }
        memoryQueue.add(key)
        indexCache[key]++
    }
}

fun main() {
    val solution : Solution146 = Solution146(2)
    solution.put(1, 1)
    solution.put(2, 2)
    solution.put(2, 4)
    solution.get(1)
    solution.get(2)

}