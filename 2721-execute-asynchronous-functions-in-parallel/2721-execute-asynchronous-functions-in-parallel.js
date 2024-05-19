/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const results = new Array(functions.length);
        let completed = 0;
        functions.forEach((promise, index) => {
            promise()
                .then((result) => {
                    results[index] = result;
                    completed++;
                    if(completed === functions.length){
                        resolve(results);
                    }
                }).catch((error) => {
                   reject(error);
                });
        });
        if(functions.length === 0){
            resolve(results);
        }
    });
};

/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */