/**
 * @param {string} columnTitle
 * @return {number}
 */
var titleToNumber = function(columnTitle) {
    const reversedColumnTitle = columnTitle.split('').reverse().join('');
    let fact = 1;
    return reversedColumnTitle.split('').reduce((acc, curr) => {
        acc += (curr.charCodeAt(0) - 64) * fact;
        fact *= 26;
        return acc;
    }, 0);
};