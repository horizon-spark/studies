'use strict';
// let val = prompt("Insert a number", "");  // (3)
// if (val > 0) {
//     alert(1);
// } else if (val < 0) {
//     alert(-1);
// } else {
//     alert(0);
// }

// let result = (a + b < 4) ? "A few" : "A lot of"; // (4)

let login = prompt("Insert login","");
let massage = (login == "Employee") ? "Hi" : 
    (login == "CEO") ? "Hello" : 
    (login == "") ? "No login" : "";
alert(message);