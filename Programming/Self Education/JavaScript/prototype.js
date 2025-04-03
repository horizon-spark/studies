"use strict";
// (1)
// let head = {
//     glasses: 1
// };
  
// let table = {
//     pen: 3,
//     __proto__: head
// };
  
// let bed = {
//     sheet: 1,
//     pillow: 2,
//     __proto__: table
// };
  
// let pockets = {
//     money: 2000,
//     __proto__: bed
// };

// alert(pockets.pen);
// alert(bed.glasses);

// (2)
// let hamster = {
//     eat(food) {
//       this.stomach.push(food);
//     }
//   };
  
//   let speedy = {
//     stomach: [],
//     __proto__: hamster
//   };
  
//   let lazy = {
//     stomach: [],
//     __proto__: hamster
//   };
  
//   // Этот хомяк нашёл еду
//   speedy.eat("apple");
//   alert( speedy.stomach ); // apple
  
//   // У этого хомяка тоже есть еда. Почему? Исправьте
//   alert( lazy.stomach ); // apple

// (3)
// function f() {
//     alert("Hello!");
// }

// Function.prototype.defer = function(ms) {
//     setTimeout(this,ms);
// };
  
// f.defer(1000); // выведет "Hello!" через 1 секунду

// (4)
Function.prototype.defer = function(ms) {
    let f = this;
    return function(...args) {
        setTimeout(() => f.apply(this, args), ms);
    }
};

function f(a, b) {
    alert( a + b );
}

f.defer(1000)(1, 2); // выведет 3 через 1 секунду.
