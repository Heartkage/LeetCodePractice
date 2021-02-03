 class TreeNode(var `val`: Int) {
     var left: TreeNode? = null
     var right: TreeNode? = null
}

class Solution {
    fun singleNumber(nums: IntArray): Int {
        nums.sort();

        var num = 0
        for(i in nums.indices step 3)
        {
            num = nums[i]

            if((i + 2) < nums.size)
                if(nums[i] != nums[i + 2])
                    break
        }
        return num
    }
}

fun main() {
    val solution : Solution

}