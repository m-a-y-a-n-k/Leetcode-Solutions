/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function(pattern, s) {
    const words = s.split(' ');
    const map1 = new Map();
    const map2 = new Map();
    let match = true;
    if(words.length !== pattern.length){
        return false;
    }
    words.forEach((word, idx) => {
        if(!map1.get(pattern[idx])){
            map1.set(pattern[idx], word); 
        } else if(map1.get(pattern[idx]) != word){
            match = false;
        }
        if(!map2.get(word)){
            map2.set(word, pattern[idx]);
        } else if(map2.get(word) != pattern[idx]){
            match = false;
        }
    });
    return match;
};