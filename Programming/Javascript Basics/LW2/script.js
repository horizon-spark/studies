"use strict";

const inputNode = document.getElementById("inputField");

const operationSet = new Set();
operationSet.add("/");
operationSet.add("*");
operationSet.add("-");
operationSet.add("+");

const handleClearAllButtonClick = () => {
  inputNode.value = "0";
};
const clearAllButton = document.querySelector("#clearAll");
clearAllButton.onclick = () => handleClearAllButtonClick();

const handleClearButtonClick = () => {
  const elems = inputNode.value.split(" ");
  if (elems.length === 1 && Math.abs(+elems[0]) < 10) {
    inputNode.value = "0";
    return;
  }
  if (operationSet.has(inputNode.value.at(-2))) {
    inputNode.value = inputNode.value.slice(0, inputNode.value.length - 3);
    return;
  }
  inputNode.value = inputNode.value.slice(0, inputNode.value.length - 1);
};
const clearButton = document.querySelector("#clear");
clearButton.onclick = () => handleClearButtonClick();

const handleNumberButtonClick = (button) => {
  const elems = inputNode.value.split(" ");
  if (+elems.length === 1 && +elems[0] === 0) {
    inputNode.value = "";
  }

  inputNode.value += button.id;
};
for (let i = 0; i < 10; i++) {
  const button = document.getElementById(i);
  button.onclick = () => handleNumberButtonClick(button);
}

const equalize = (arr) => {
  if (arr.length !== 3) return;
  switch (arr[1]) {
    case "/":
      if (+arr[2] === 0) {
        alert("Ошибка! Деление на ноль!");
        return 0;
      }
      return arr[0] / arr[2];
    case "*":
      return arr[0] * arr[2];
    case "-":
      return arr[0] - arr[2];
    case "+":
      return +arr[0] + +arr[2];
    default:
      return;
  }
};

const handleOperationButtonClick = (button) => {
  if (inputNode.value === "") return;

  const elems = inputNode.value.split(" ");

  if (elems.length === 3 && elems.at(-1) !== "") {
    inputNode.value = equalize(elems);
  }
  if (operationSet.has(inputNode.value.at(-2))) {
    inputNode.value = inputNode.value.slice(0, inputNode.value.length - 3);
  }
  switch (button.id) {
    case "division":
      inputNode.value += " / ";
      break;
    case "multiplication":
      inputNode.value += " * ";
      break;
    case "substraction":
      inputNode.value += " - ";
      break;
    case "addition":
      inputNode.value += " + ";
      break;
    default:
      inputNode.value = "";
  }
};
const operationButtonNodes = document.querySelectorAll(".operationButton");
for (let button of operationButtonNodes) {
  button.onclick = () => handleOperationButtonClick(button);
}

const handleEqualButtonClick = () => {
  if (inputNode.value === "") return;
  const elems = inputNode.value.split(" ");
  if (elems.length === 3 && elems.at(-1) !== "") {
    inputNode.value = equalize(elems);
  }
};
const equalButton = document.querySelector("#equal");
equalButton.onclick = () => handleEqualButtonClick();
