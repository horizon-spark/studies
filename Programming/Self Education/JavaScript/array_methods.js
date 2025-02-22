"use strict";
// (1.1)
// function camelize(str) {  // Мое решение (не изменяет регистр)
//     str = str.split('');
//     let ind;
//     while (str.findIndex(symbol => symbol == '-' ) != -1) {
//         ind = str.findIndex(symbol => symbol == '-');
//         str.splice(ind,1);
//         str[ind].toUpperCase();
//     }
//     return str.join('');
// }

// (1.2)
// function camelize(str) {    // Решение на сайте (ебнутое)
//     return str
//       .split('-')
//       .map(
//         (word, index) => index == 0 ? word : word[0].toUpperCase() + word.slice(1)
//       )
//       .join('');
// }
// alert(camelize("background-color"));
// alert(camelize("list-style-image"));
// alert(camelize("-webkit-transition")); 

// (2)
// function filterRange(arr,a,b) {
//     return arr.filter(item => (item >= a && item <= b));
// }
// let arr = [5, 3, 8, 1];

// let filtered = filterRange(arr, 1, 4);

// alert( filtered ); // 3,1 

// alert( arr ); // 5,3,8,1 

// (3)
// function filterRangeInPlace(arr,a,b) {
//     for (let i = 0; i < arr.length; i++) {
//         if (arr[i] < a || arr[i] > b) 
//             arr.splice(i,1);
//     }
//     return;
// }
// let arr = [5, 3, 8, 1];
// filterRangeInPlace(arr, 1, 4); 
// alert( arr ); 

// (4)
// let arr = [5, 2, 1, -10, 8];
// arr.sort((a,b) => b - a);
// alert(arr);

// (5)
// function copySorted(arr) {
//     return arr.slice().sort();
// }
// let arr = ["HTML", "JavaScript", "CSS"];
// let sorted = copySorted(arr);

// alert( sorted ); 
// alert( arr ); 

