'use strict';
// (1)
// let ucFirst = function(str) {
//     if (!str) return str;
//     return str[0].toUpperCase() + str.slice(1); 
// }
// alert(ucFirst("vasya"));

// (2)
// let checkSpam = function(str) {
//     if (!str) return false;
//     let clone = str.toLowerCase();
//     return clone.includes("viagra") || clone.includes("xxx");

// }
// alert(checkSpam('buy ViAgRA now')); 
// alert(checkSpam('free xxxxx')); 
// alert(checkSpam("innocent rabbit")); 

// (3)
// let truncate = function(str,maxlength) {
//     return str.length <= maxlength ? 
//     str : str.substr(0,maxlength - 1) + '...';
// }
// alert(truncate("Вот, что мне хотелось бы сказать на эту тему:", 20));
// alert(truncate("Всем привет!", 20));

// (4)
// let extractCurrencyValue = function(str) {
//     return +str.slice(1);
// }
// alert( extractCurrencyValue('$120') === 120 ); 

