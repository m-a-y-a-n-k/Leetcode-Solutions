/**
 * @param {Function} fn
 * @return {Object}
 */
Array.prototype.groupBy = function(fn) {
    const groupedResult = {};
    for(const val of this){
        const key = fn(val);
        if(groupedResult[key]){
            groupedResult[key].push(val);        
        } else {
            groupedResult[key] = [val];
        }
    }
    return groupedResult;
};

/**
 * [1,2,3].groupBy(String) // {"1":[1],"2":[2],"3":[3]}
 */