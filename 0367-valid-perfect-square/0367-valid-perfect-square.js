/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function(num) {
    for(let k = 1; k * k <= num; k++){
        if(num % k == 0 && k * k == num){
            return true;
        }
    }
    return false;
};