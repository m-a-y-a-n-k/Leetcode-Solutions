/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function(nums, k) {
    let sumMap = {0: 1};
    let count = 0, currSum = 0;
    
    for(const num of nums){
        currSum += num;
        const diff = currSum - k;
        if(sumMap[diff]){
            count += sumMap[diff];
        }
        sumMap[currSum] = (sumMap[currSum] || 0) + 1;
    }
    
    return count;
};