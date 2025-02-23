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

// (6)
// function Calculator() {
//     this.methods = {
//         "-": (a,b) => a - b,
//         "+": (a,b) => a + b
//     };
//     this.calculate = function(str) {
//         let arr = str.split(" ");
//         let a = +arr[0];
//         let op = arr[1];
//         let b = +arr[2];
//         if (!this.methods[op] || isNaN(a) || isNaN(b)) {
//             return NaN;
//         }
//         return this.methods[op](a,b);
//     }
//     this.addMethod = function(name,func) {
//         this.methods[name] = func;
//     }
// }
// let powerCalc = new Calculator;
// powerCalc.addMethod("*", (a, b) => a * b);
// powerCalc.addMethod("/", (a, b) => a / b);
// powerCalc.addMethod("**", (a, b) => a ** b);

// let result = powerCalc.calculate("2 ** 3");
// alert( result );

// (7)
// let vasya = { name: "Вася", age: 25 };
// let petya = { name: "Петя", age: 30 };
// let masha = { name: "Маша", age: 28 };

// let users = [ vasya, petya, masha ];

// let names = users.map((obj) => obj.name);

// alert( names ); // Вася, Петя, Маша

// (8)
// let vasya = { name: "Вася", surname: "Пупкин", id: 1 };
// let petya = { name: "Петя", surname: "Иванов", id: 2 };
// let masha = { name: "Маша", surname: "Петрова", id: 3 };

// let users = [ vasya, petya, masha ];

// let usersMapped = users.map( user => ({
//     fullName: `${user.name} ${user.surname}`,
//     id: user.id
// }));

// /*
// usersMapped = [
//   { fullName: "Вася Пупкин", id: 1 },
//   { fullName: "Петя Иванов", id: 2 },
//   { fullName: "Маша Петрова", id: 3 }
// ]
// */

// alert( usersMapped[0].id ) // 1
// alert( usersMapped[0].fullName ) // Вася Пупкин

// (9)
// function sortByAge(arr) {
//     arr.sort((obj1, obj2) => obj1.age - obj2.age);
// }
// let vasya = { name: "Вася", age: 25 };
// let petya = { name: "Петя", age: 30 };
// let masha = { name: "Маша", age: 28 };

// let arr = [ vasya, petya, masha ];

// sortByAge(arr);

// // теперь: [vasya, masha, petya]
// alert(arr[0].name); // Вася
// alert(arr[1].name); // Маша
// alert(arr[2].name); // Петя