/**
 * @param {number[]} nums
 * @return {number}
 */
var subsetXORSum = function(nums) {
    let total = 0;
    for(const num of nums){
        total |= num;
    }
    return (total << (nums.length - 1));
};