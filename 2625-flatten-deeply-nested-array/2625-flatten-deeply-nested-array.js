/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    if(n == 0){
        return arr;
    }
    return arr.reduce((result, d) => {
        if(Array.isArray(d) && n > 0){
            result.push(...flat(d, n - 1));
        } else {
            result.push(d);
        }
        return result;
    }, [])
};