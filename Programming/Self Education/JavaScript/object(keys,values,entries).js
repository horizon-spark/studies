'use strict';
// (1)
// function sumSalaries(obj) {
//     let res = 0;
//     for (let item of Object.values(obj)) {
//         res += item;
//     }
//     return res;
// }
// let salaries = {
//     "John": 100,
//     "Pete": 300,
//     "Mary": 250
//   };
  
// alert( sumSalaries(salaries) ); // 650

// (2)
function count(obj) {
    return Object.keys(obj).length;
}
let user = {
    name: 'John',
    age: 30
  };
  
alert( count(user) ); // 2