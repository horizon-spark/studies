"use strict";
// (1)
// function delay(ms) {
//     return new Promise(resolve => setTimeout(resolve, ms));
// }
  
// delay(3000).then(() => alert('выполнилось через 3 секунды'));

// (2)
// async function loadJson(url) {
//     let response = await fetch(url);

//     if (response.status == 200) {
//         let json = await response.json();
//         return json;
//     }

//     throw new Error(response.status);
// }

// loadJson('no-such-user.json') // (3)
//   .catch(alert); // Error: 404

// (3)
// class HttpError extends Error {
//     constructor(response) {
//       super(`${response.status} for ${response.url}`);
//       this.name = 'HttpError';
//       this.response = response;
//     }
//   }
  
//   async function loadJson(url) {
//     let response = await fetch(url);
    
//     if (response.status == 200) {
//         let json = await response.json();
//         return json;
//     } 

//     throw new HttpError(response);
//   }
  
//   // Запрашивать логин, пока github не вернёт существующего пользователя.
//   async function demoGithubUser() {
//     let user;
//     while (true) {
//         let name = prompt("Введите логин?", "iliakan");
    
//         try {
//             user = await loadJson(`https://api.github.com/users/${name}`);
//             break;
//         } catch(err) {
//             if (err instanceof HttpError && err.response.status == 404) {
//                 alert("Такого пользователя не существует, пожалуйста, повторите ввод.");
//               } else {
//                 throw err;
//               }
//         }
//     }

//     alert(`Полное имя: ${user.name}.`);
//     return user;
//   }
  
//   demoGithubUser();

// (4)
async function wait() {
    await new Promise(resolve => setTimeout(resolve, 1000));
  
    return 10;
  }
  
  function f() {
    wait().then(res => alert(res));
  }

  f();