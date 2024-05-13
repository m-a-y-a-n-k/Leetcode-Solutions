/**
 * @param {string} s
 * @return {string}
 */

function expandAroundCenter(s, start, end) {
    while(start >= 0 && end < s.length && s[start] === s[end]){
        start--;
        end++;
    }
    return end - start - 1;
}

var longestPalindrome = function(s) {
    
    if(!s){
        return "";
    }
    
    let start = 0, end = 0;
    
    for(let i = 0; i < s.length; i++){
        const odd = expandAroundCenter(s, i, i);
        const even = expandAroundCenter(s, i, i + 1);
        
        const maxLength = Math.max(odd, even);
        
        if(maxLength > end - start){
            start = i - Math.floor( (maxLength - 1) / 2 );
            end = i + Math.floor(maxLength / 2);
        }
    }
    
    return s.substring(start, end + 1);
};