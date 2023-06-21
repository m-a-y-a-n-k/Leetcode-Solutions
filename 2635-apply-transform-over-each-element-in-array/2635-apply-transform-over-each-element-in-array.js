/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    let returnedArray = [];
    arr.forEach((val, index) => {
        returnedArray.push(fn(val, index));
    })
    return returnedArray;
};