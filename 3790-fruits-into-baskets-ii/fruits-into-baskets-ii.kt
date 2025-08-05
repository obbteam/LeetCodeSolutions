class Solution {
    fun numOfUnplacedFruits(fruits: IntArray, baskets: IntArray): Int {
    var count = 0
    for (i in 0..fruits.size - 1) {
        var found = false
        for (j in 0..baskets.size - 1){
            if (fruits[i] <= baskets[j]){
                found = true
                baskets[j] = Int.MIN_VALUE
                break
            }
        }
        if (!found)
            count++
    }
    return count
}
}