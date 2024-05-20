/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    if(n <= 2){
        return n;
    }
    const ans = Array(n+1).fill(0);
    ans[1] = 1;
    ans[2] = 2;
    
    for(let k = 3; k <= n; k++){
        ans[k] = ans[k-1] + ans[k-2];
    }
    
    return ans[n];
};