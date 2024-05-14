/**
 * @param {number[]} nums
 * @return {number}
 */
var findDuplicate = function(nums) {
    for(let i = 0; i < nums.length; ++i){
        let ind = Math.abs(nums[i]);
        if(nums[ind-1] > 0){
            nums[ind-1] = -nums[ind-1];
        } else {
            return ind;
        }
    }
    return -1;
};