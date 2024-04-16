class Solution136{
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
