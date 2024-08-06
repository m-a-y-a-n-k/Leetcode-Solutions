/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
      
    const data = {};
    arr1.forEach((a) => {
        data[a.id] = {
            ...a,
        }
    })
    arr2.forEach((a) => {
        data[a.id] = {
            ...data[a.id],
            ...a,
        }
    })
    
    return Object.values(data);
};