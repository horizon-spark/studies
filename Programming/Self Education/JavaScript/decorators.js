"use strict";
// (1)
// function spy(func) {

//     function wrapper(...args) {
//         wrapper.calls.push(args);
//         return func.apply(this, args);
//     }

//     wrapper.calls = [];

//     return wrapper;
// }
// function work(a, b) {
//     alert( a + b ); // произвольная функция или метод
//   }
  
// work = spy(work);

// work(1, 2); // 3
// work(4, 5); // 9

// for (let args of work.calls) {
//   alert( 'call:' + args.join() ); // "call:1,2", "call:4,5"
// }

// (2)
// function delay(f, ms) {

//     return function() {
//         setTimeout(() => f.apply(this, args), ms);
//     };

// }

// let f1000 = delay(alert, 1000);

// f1000("test"); // показывает "test" после 1000 мс

// (3)
