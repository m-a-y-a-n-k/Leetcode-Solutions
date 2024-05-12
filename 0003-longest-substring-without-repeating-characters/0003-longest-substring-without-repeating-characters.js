/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    
    const myMap = new Map();
    let start = 0, end = 0, maxLength = 0;
    for(end = 0; end < s.length; end++){
        if(myMap.has(s[end])){
            maxLength = Math.max(maxLength, end - start);
            let newStart = myMap.get(s[end]) + 1;
            while(start < newStart){
                myMap.delete(s[start]);
                start++;
            } 
        } 
        myMap.set(s[end], end);
    }
    return Math.max(maxLength, end - start);
};