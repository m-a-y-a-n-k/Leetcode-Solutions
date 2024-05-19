/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    const size = nums.length;
    const answer = Array(size).fill(1);
    let left = 1, right = 1;
    for(let i = 0; i < size; ++i){
        answer[i] *= left;
        left *= nums[i];
    }
    for(let j = size - 1; j >= 0; --j){
        answer[j] *= right;
        right *= nums[j];
    }
    return answer;
};