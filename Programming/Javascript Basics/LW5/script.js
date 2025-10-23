"use strict";

const canvas = document.getElementById("canvas");
const context = canvas.getContext("2d");
context.font = "22px Verdana";

const center = { x: 250, y: 150 };
const r1 = 100,
  r2 = 110;

context.beginPath();
context.arc(center.x, center.y, 3, 0, 2 * Math.PI, true);
context.fill();

context.beginPath();
context.arc(center.x, center.y, r1, 0, 2 * Math.PI, true);
context.arc(center.x, center.y, r2, 0, 2 * Math.PI, true);

context.moveTo(center.x + r1, center.y);

for (let alf = 0; alf <= 2 * Math.PI; alf += Math.PI / 6) {
  context.arc(center.x, center.y, r1, alf, alf + Math.PI / 6, false);
  context.moveTo(
    center.x + r2 * Math.cos(alf + Math.PI / 6),
    center.y + r2 * Math.sin(alf + Math.PI / 6)
  );
}
context.stroke();

context.beginPath();
context.lineWidth = 2.5;
context.moveTo(center.x, center.y);
context.lineTo(center.x, center.y - r1 + 20);
context.stroke();

context.beginPath();
context.moveTo(center.x, center.y);
context.lineTo(center.x, center.y + r1 - 50);
context.stroke();
