'use strict';
// (1)
// let user = new Object(); - another way to create an empty object
// let user = {};
// user.name = "John";
// user.surname = "Smith";
// user.name = "Pete";
// delete user.name;

// (2)
// let schedule = {};

// alert(isEmpty(schedule));

// schedule["8:30"] = "get up";

// alert(isEmpty(schedule));

// function isEmpty(obj) {
//     for (let key in obj) {
//         return false;
//     }
//     return true;
// }

// (3)
// let salaries = {
//     John: 100,
//     Ann: 160,
//     Pete: 130
// }
// function sum(obj) {
//     let result = 0;
//     for (let key in obj) {
//         result += obj[key];
//     }
//     return result;
// }
// alert(sum(salaries));

// (4)
let menu = {
    width: 200,
    height: 300,
    title: "My menu"
  };
  
multiplyNumeric(menu);

function multiplyNumeric(obj) {
    for (let key in obj) {
        if (typeof(obj[key]) == "number") {
            obj[key] *= 2;
        }
    }
}