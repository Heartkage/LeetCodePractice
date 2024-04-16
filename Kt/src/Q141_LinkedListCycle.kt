class ListNode(var `val`: Int) {
    var next: ListNode? = null
}

 class Solution {
    fun hasCycle(head: ListNode?): Boolean {
        var tortoise = head
        var hare = head

        do{
            tortoise = tortoise?.next
            hare = hare?.next?.next
        } while(tortoise != hare)

        return tortoise != null;
    }

    fun detectCycle(head: ListNode?): ListNode? {
        var tortoise = head
        var hare = head

        do{
            tortoise = tortoise?.next
            hare = hare?.next?.next
        } while(tortoise != hare)

        return if(tortoise != null) {
            hare = head
            while(hare != tortoise){
                hare = hare?.next
                tortoise = tortoise?.next
            }
            hare
        } else
            null
    }
}

fun main() {
    val solution : Solution = Solution()
    val node : ListNode = ListNode(7)

    println(solution.hasCycle(node))
}