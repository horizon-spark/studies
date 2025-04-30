"use strict";
let names = ['iliakan', 'remy', 'no.such.users'];
async function getUsers(names) {
    let users = [];
    for (let name of names) {
        let response = await fetch(`https://api.github.com/users/${name}`);
        if (response.ok) {
            users.push(response.json());
        } else {
            users.push(null);
        }
    }
    return users;
}
let users = getUsers(names);
for (let user of users) {
    alert(user);
}