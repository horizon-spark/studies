"use strict";
// (1)
// let styles = ["Jazz", "Blues"];
// alert(styles);
// styles.push("Rock-n-Roll");
// alert(styles);
// styles[Math.floor((styles.length - 1) / 2)] = "Classic";
// alert(styles);
// alert(styles.shift());
// alert(styles);
// styles.unshift("Rap", "Raggy");
// alert(styles);

// (2)
// function sumInput() {
//     let arr = [];
//     let value;
//     while (1) {
//         value = prompt("Insert a number","");
//         if ( value === "" || value === null || !isFinite(value) ) break;
//         arr.push(+value);
//     }
//     let sum = 0;
//     for (let elem of arr) {
//         sum += elem;
//     }
//     return sum;
// }
// alert( sumInput() );

// (3)
function getMaxSubSum(arr) {
    let max = 0;
    let currSum = 0;
    for (let num of arr) {
        currSum += num;
        if (max < currSum) max = currSum;
        if (currSum < 0) currSum = 0;
    }
    return max;
}
alert(getMaxSubSum([-1, 2, 3, -9])) //       == 5 
alert(getMaxSubSum([2, -1, 2, 3, -9])) //    == 6
alert(getMaxSubSum([-1, 2, 3, -9, 11])) //   == 11
alert(getMaxSubSum([-2, -1, 1, 2]))  //      == 3
alert(getMaxSubSum([100, -9, 2, -3, 5])) //  == 100
alert(getMaxSubSum([1, 2, 3])) //            == 6