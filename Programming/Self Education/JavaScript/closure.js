"use strict";
// (1)
// function sum(first) {
//     return function(second) {
//         return first + second;
//     }
// }
// alert( sum(1)(2) );
// alert( sum(5)(-1) );

// (2)
// function inBetween(a,b) {
//     return function(elem) {
//         return elem >= a && elem <= b;
//     }
// }
// function inArray(arr) {
//     return function(elem) {
//         return arr.includes(elem); 
//     }
// }
// let arr = [1, 2, 3, 4, 5, 6, 7];

// alert( arr.filter(inBetween(3, 6)) ); // 3,4,5,6

// alert( arr.filter(inArray([1, 2, 10])) ); // 1,2

// (3)
// function byField(fieldName) {
//     return (a,b) => a[fieldName] > b[fieldName] ? 1 : -1;
// }
// let users = [
//     { name: "Иван", age: 20, surname: "Иванов" },
//     { name: "Пётр", age: 18, surname: "Петров" },
//     { name: "Анна", age: 19, surname: "Каренина" }
//   ];

// users.sort(byField('name'));
// users.sort(byField('age'));

// (4)
function makeArmy() {
    let shooters = [];
  
    let i = 0;
    while (i < 10) {
      let j = i;
      let shooter = function() {
        alert( j ); // должна выводить порядковый номер
      };
      shooters.push(shooter); // и добавлять стрелка в массив
      i++;
    }
    // ...а в конце вернуть массив из всех стрелков
    return shooters;
  }
  
let army = makeArmy();
  
// все стрелки выводят 10 вместо их порядковых номеров (0, 1, 2, 3...)
army[0](); // 10 от стрелка с порядковым номером 0
army[1](); // 10 от стрелка с порядковым номером 1
army[2](); // 10 ...и т.д.