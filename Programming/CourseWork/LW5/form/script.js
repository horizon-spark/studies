"use strict";

const nameField = document.getElementById("name");
const surnameField = document.getElementById("surname");
const ageField = document.getElementById("age");
const table = document.getElementById("table");
const checkButton = document.getElementById("checkButton");
const addButton = document.getElementById("addButton");
const clearButton = document.getElementById("clearButton");

const validateString = (str) => {
  let words, res;
  if (str.includes(" ")) {
    words = str
      .split(" ")
      .map(
        (elem) =>
          elem[0].toUpperCase() + elem.slice(1, elem.length).toLowerCase()
      );
    res = words.join(" ");
  } else if (str.includes("-")) {
    words = str
      .split("-")
      .map(
        (elem) =>
          elem[0].toUpperCase() + elem.slice(1, elem.length).toLowerCase()
      );
    res = words.join("-");
  } else {
    res = str[0].toUpperCase() + str.slice(1, str.length).toLowerCase();
  }
  console.log(res);
  return res;
};

const handleCheckClick = () => {
  if (!nameField.value || !surnameField.value || !ageField.value) {
    alert("Необходимо заполнить все поля");
    return;
  }
  if (nameField.value.length < 2 || surnameField.value.length < 2) {
    alert("Введите полные имя и фамилию");
    return;
  }
  nameField.value = validateString(nameField.value);
  surnameField.value = validateString(surnameField.value);
  if (isNaN(ageField.value)) {
    alert("Возраст должен быть числом");
    return;
  }
  if (ageField.value < 0 || ageField.value > 120) {
    alert("Введите корректный возраст");
    return;
  }
  if (ageField.value % 1 !== 0) {
    alert("Возраст должен быть целым числом");
    return;
  }
  alert("Данные введены корректно");
  addButton.disabled = false;
};

checkButton.onclick = () => {
  handleCheckClick();
  return false;
};

nameField.onchange = () => {
  if (!addButton.disabled) addButton.disabled = true;
};

surnameField.onchange = () => {
  if (!addButton.disabled) addButton.disabled = true;
};

ageField.onchange = () => {
  if (!addButton.disabled) addButton.disabled = true;
};

const handleAddClick = (table, surname, name, age) => {
  let tr = document.createElement("tr");
  tr.innerHTML = `<td>${surname}</td><td>${name}</td><td>${age}</td>`;
  table.append(tr);
};

addButton.onclick = () => {
  handleAddClick(table, surnameField.value, nameField.value, ageField.value);
  return false;
};

const handleClearClick = (table) => {
  table.innerHTML = "<tr><th>Фамилия</th><th>Имя</th><th>Возраст</th></tr>";
};

clearButton.onclick = () => {
  handleClearClick(table);
  return false;
};
