/**
 * @param {number} columnNumber
 * @return {string}
 */

function getChar(colNo){
    return String.fromCharCode(colNo + 65);
}

var convertToTitle = function(columnNumber) {
    let columnString = "";
    while(columnNumber > 0){
        columnNumber--;
        columnString = getChar(columnNumber % 26) + columnString;
        columnNumber = Math.floor(columnNumber / 26);
    }
    return columnString;
};