"use strict";

const canvas = document.getElementById("canvas");
const ctx = canvas.getContext("2d");

let arrX = [
  -Math.PI,
  -Math.PI / 2,
  -Math.PI / 3,
  -Math.PI / 4,
  -Math.PI / 6,
  0,
  Math.PI / 6,
  Math.PI / 4,
  Math.PI / 3,
  Math.PI / 2,
  Math.PI,
];

let arrY = arrX.map((x) => Math.cos(x));

arrX.forEach((x, index) => {
  arrX[index] = (arrX[index] * 250) / Math.PI;
});
arrY.forEach((y, index) => {
  arrY[index] = arrY[index] * 150;
});

ctx.beginPath();
ctx.moveTo(0, 150);
ctx.lineTo(500, 150);
ctx.stroke();

ctx.beginPath();
ctx.moveTo(250, 0);
ctx.lineTo(250, 300);
ctx.stroke();

ctx.translate(250, 150);

ctx.beginPath();
ctx.moveTo(arrX[0], arrY[0]);
for (let i = 1; i < arrX.length; i++) {
  ctx.lineTo(arrX[i], arrY[i]);
}
ctx.stroke();
