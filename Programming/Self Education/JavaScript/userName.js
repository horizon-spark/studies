let name, result = false;
while (1) {
    name = prompt("What is your name?", "");
    result = comfirm(`Your name is ${name}, correct?`);
    if (result == true) break;
}
alert(`Your name is ${name}`);