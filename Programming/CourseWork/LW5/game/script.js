"use strict";

const generateGameField = (n) => {
  let field = document.createElement("table");
  field.className = "defaultTable";
  for (let i = 0; i < n; i++) {
    let row = document.createElement("tr");
    for (let j = 0; j < n; j++) {
      let cell = document.createElement("td");
      cell.className = "defaultCellColor";
      row.append(cell);
    }
    field.append(row);
  }
  document.body.append(field);
  return field;
};

let field = generateGameField(5);

let button = document.createElement("button");
button.textContent = "Поменять цвета";

const handleSwitchClick = (table) => {
  table.className =
    table.className === "defaultTable" ? "activeTable" : "defaultTable";
};

button.onclick = () => {
  handleSwitchClick(field);
};

document.body.append(button);

field.addEventListener("click", (event) => {
  if (event.target.tagName === "TD") {
    event.target.className =
      event.target.className === "defaultCellColor"
        ? "activeCellColor"
        : "defaultCellColor";
  }
});
