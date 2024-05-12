/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    const setNums = new Set(nums1);
    const resultSet = new Set();
    nums2.forEach((num2) => {
        if(setNums.has(num2)){
            resultSet.add(num2);
        }
    })
    
    return Array.from(resultSet);
};