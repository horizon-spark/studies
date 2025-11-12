"use strict";

const buttonElement = document.querySelector("#button");
const select = document.querySelector("#select");
const aElem = document.querySelector("#a");
const bElem = document.querySelector("#b");
const cElem = document.querySelector("#c");

buttonElement.onclick = () => {
  const a = aElem.value ? aElem.value : 0;
  const b = bElem.value ? bElem.value : 0;
  const c = cElem.value ? cElem.value : 0;

  const functionNumber = select.value;
  const plotFunctions = [
    `${a} * x^2 + ${b} * x + ${c}`,
    `${a} * exp(${b} * x) + ${c}`,
    `${a} * cos(${b} * x) + ${c}`,
    `${a} * sin(${b} * x) + ${c}`,
    `${a} * tan(${b} * x) + ${c}`,
    `${a} * (1 / tan(${b} * x)) + ${c}`,
    `${a} * x^${b} + ${c}`,
    `${a}^x`,
  ];

  functionPlot({
    title: plotFunctions[functionNumber],
    target: "#plot",
    width: 580,
    height: 400,
    disableZoom: false,
    xAxis: {
      label: "x - axis",
      domain: [-6, 6],
    },
    yAxis: {
      label: "y - axis",
    },
    data: [
      {
        fn: plotFunctions[functionNumber],
      },
      {
        fn: "1 + x",
      },
    ],
  });
};
