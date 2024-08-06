/**
 * @param {Array} arr
 * @param {Function} fn
 * @return {Array}
 */
var sortBy = function(arr, fn) {
    arr.sort((a,b) => {
        const x = fn(a);
        const y = fn(b);
        if(x < y){
            return -1;
        }
        if(x == y){
            return 0;
        }
        return 1;
    });  
    return arr;
};