/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let returnedArray = [];
    arr.forEach((val, idx) => {
        if(Boolean(fn(val, idx)) === true){
            returnedArray.push(val);
        } 
    });
    return returnedArray;
};