"use strict";

const NUMBER_OF_ELEMENTS = 9;

let createIndicesArray = (size) => {
  let res = [];
  for (let i = 0; i < size; i++) {
    res.push(i);
  }
  return res;
};

let createRandomIndicesArray = (size) => {
  let res = [];
  let arr = createIndicesArray(size);
  while (arr.length) {
    let randItem = arr[Math.floor(Math.random() * arr.length)];
    res.push(randItem);
    arr.splice(arr.indexOf(randItem), 1);
  }
  return res;
};

let enableAllButtons = (currentCount) => {
  for (let i = 0; i < currentCount; i++) {
    document.getElementById(i).disabled = false;
  }
};

let createClickHandler = () => {
  let count = 0;
  return (button) => {
    if (button.id == count) {
      count++;
      button.disabled = true;
    } else {
      enableAllButtons(count);
      count = 0;
      alert("Неправильный порядок! Начинать нужно с нуля!");
    }
  };
};

let indices = createRandomIndicesArray(NUMBER_OF_ELEMENTS);
let clickHandler = createClickHandler();

let buttonList = document.createElement("div");
buttonList.className = "buttonList";
document.body.append(buttonList);

let buttonListNode = document.querySelector(".buttonList");

for (let i = 0; i < NUMBER_OF_ELEMENTS; i++) {
  let button = document.createElement("button");

  button.className = "button";
  button.id = indices[i];
  button.textContent = indices[i];
  button.onclick = () => clickHandler(button);

  buttonListNode.append(button);
}
