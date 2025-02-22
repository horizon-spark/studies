'use strict';
// function checkAge(age) 
// {
//     return age > 18 ? true : confirm("Родители разрешили?"); 
// }

// function checkAge(age)
// {
//     return age > 18 || confirm("Родители разрешили?");
// }

// function min(a,b)
// {
//     return a < b ? a : b;
// }

function pow(x,n)
{
    let res = 1;
    for (let i=0;i<n;i++) {
        res *= x;
    }
    return res;
}

let x = prompt("Insert a number","");
let n = prompt("Insert a degree","");
alert(pow(+x,+n));