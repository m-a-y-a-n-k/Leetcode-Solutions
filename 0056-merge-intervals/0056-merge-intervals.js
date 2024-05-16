/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    if(!intervals.length){
        return [];    
    }
    intervals.sort((a, b) => a[0] - b[0]);    
    let v = intervals[0];
    const result = [];

    for(const x of intervals){
        if(x[0] <= v[1]){
            v[1] = Math.max(x[1], v[1]);   
        } else {
            result.push(v);
            v = x;
        }
    }
    result.push(v);
    return result;
};