/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const result = [];
    
    function getCombinations(currString, open, close){
        if(currString.length == 2*n){
            result.push(currString);
            return ;
        }
        
        if(open < n){
            getCombinations(currString + '(', open + 1, close);
        }
        
        if(close < open){
            getCombinations(currString + ')', open, close + 1);
        }
    }
    
    getCombinations('', 0, 0);
    return result;
};