/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
    const freq1 = {}, freq2 = {};
    s.split('').forEach((ch) => {
        freq1[ch] = (freq1[ch] || 0) + 1;
    })
    t.split('').forEach((ch) => {
        freq2[ch] = (freq2[ch] || 0) + 1;
    })
    for(let c = 0; c < 26; c++){
        const currCh = String.fromCharCode(c + 97);
        if(freq1[currCh] != freq2[currCh]){
            return currCh;
        }
    }
    return '';
};