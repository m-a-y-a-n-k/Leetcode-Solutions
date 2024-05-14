/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let profitMax = 0;
    const maxPrices = Array(prices.length);
    maxPrices[prices.length - 1] = 0;
    for(let j = prices.length - 2; j >= 0; --j){
        maxPrices[j] = Math.max(maxPrices[j + 1], prices[j], prices[j+1]);
    }
    for(let i = 0; i < maxPrices.length; ++i){
        profitMax = Math.max(profitMax, maxPrices[i] - prices[i]);
    }    
    return profitMax;
};