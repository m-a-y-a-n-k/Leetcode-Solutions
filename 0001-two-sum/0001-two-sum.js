/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const myMap = new Map();
    let result = [-1, -1];
    nums.forEach((num, idx) => {
        const diff = target - num;
        if(myMap.has(diff)){
            result = [myMap.get(diff), idx];
        }
        myMap.set(num, idx);
    })
    return result;
};