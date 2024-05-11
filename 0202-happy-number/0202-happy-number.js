/**
 * @param {number} n
 * @return {boolean}
 */

function nextNumber(n){
    let next = 0;
    while(n > 0){
        next += (n % 10) * (n % 10);
        n = Math.floor(n / 10);
    }
    return next;
}

var isHappy = function(n) {
    let slow = nextNumber(n);
    let fast = nextNumber(slow);
    while(fast != 1 && fast != slow){
        slow = nextNumber(slow);
        fast = nextNumber(nextNumber(fast));
    }
    return fast == 1;
};