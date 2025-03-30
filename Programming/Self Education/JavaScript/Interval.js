"use strict";
// (1.1)
// function printNumbers(from, to) {
//     let count = from;
//     let timerId = setInterval(function() {
//         alert(count);
//         if (count == to) {
//             clearInterval(timerId);
//         }
//         count++;
//     }, 1000);
// }
// printNumbers(1,10);

// (1.2)
function printNumbers(from, to) {
    let count = from;
    setTimeout(function run() {
        alert(count);
        if (count < to) {
            setTimeout(run, 1000);
        }
        count++;
    }, 1000);
}
printNumbers(5,10);
