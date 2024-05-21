/**
 * @param {Array} arr
 * @param {number} size
 * @return {Array}
 */
var chunk = function(arr, size) {
    
    const result = [];
    let idx = 0;
    
    while(idx < arr.length){
        const sub = [];
        for(let k = 0; k < size && idx < arr.length; ++k){
            sub.push(arr[idx++]);
        }
        result.push(sub);
    }
    
    return result;
};
