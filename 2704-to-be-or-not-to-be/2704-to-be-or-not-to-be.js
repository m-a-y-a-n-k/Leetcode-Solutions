/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe(valB){
            if(val === valB){
                return true;
            }
            throw new Error("Not Equal");
        },
        notToBe(valC){
            if(val !== valC){
                return true;
            }
            throw new Error("Equal");
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */