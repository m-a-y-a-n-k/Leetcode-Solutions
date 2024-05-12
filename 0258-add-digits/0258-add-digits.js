/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    let ans = num;
    do {
        let sum = 0;
        while(ans > 0){
            let digit = ans % 10;
            sum += digit;
            ans = Math.floor(ans / 10);
        }
        ans = sum;
    } while(ans >= 10);
    return ans;
};