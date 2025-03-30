"use strict";
// (1)
// function makeCounter() {

//     function counter() {
//       return counter.count++;
//     };
  
//     counter.count = 0;

//     counter.set = function(value) {
//         counter.count = value;
//     }
//     counter.decrease = function() {
//         counter.count--;
//     }
//     /*
//         В учебнике сделано через стрелочные функции:
//         counter.set = value => count = value;
//         counter.decrease = () => count--;
//     */
  
//     return counter;
// }
  
// let counter = makeCounter();
// alert(counter.count);
// counter();
// alert(counter.count);
// counter.set(10);
// alert(counter.count);
// counter.decrease();
// alert(counter.count);

