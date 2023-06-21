/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let returnVal = init;
    nums.forEach((val, index) => {
        returnVal = fn(returnVal, val);
    })
    return returnVal;
};