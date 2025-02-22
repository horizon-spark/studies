"use strict";
let readNumber = function() {
    let num;
    do {
        num = prompt("Insert a number",0);
    } while (!isFinite(num));
    if (num === null || num === "") return null;
    return +num;
}
alert(readNumber());