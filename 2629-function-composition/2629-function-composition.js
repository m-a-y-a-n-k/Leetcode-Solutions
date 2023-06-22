/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
	return function(x) {
        let returnValue = x;
        for(let i = 0; i < functions.length; i++){
            returnValue = functions[functions.length - 1 - i](returnValue);
        }
        return returnValue;
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */