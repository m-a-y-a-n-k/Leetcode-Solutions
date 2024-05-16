/**
 * @param {string} s
 * @return {boolean}
 */

function open(char){
    return char == "(" || char == "{" || char == "[";
}

function match(ch1, ch2){
    switch(ch1){
        case ")": {
            return ch2 == "(";
        }
        case "}": {
            return ch2 == "{";
        }
        case "]": {
            return ch2 == "[";
        }
    }
    return false;
}

var isValid = function(s) {
    const stack = [];
    let result;
    s.split('').forEach((char) => {
        if(open(char)){
            stack.push(char);
        } else if(stack.length > 0 && match(char, stack[stack.length - 1])){
            stack.pop();
        } else {
            result = false;
        }
    })
    return result ?? stack.length === 0;
};