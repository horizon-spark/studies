"use strict";

const canvas = document.getElementById("canvas");
const context = canvas.getContext("2d");
context.font = "20px Verdana";

const center = { x: 250, y: 150 };
const r1 = 100,
  r2 = 110,
  r3 = 140;

context.beginPath();
context.arc(center.x, center.y, 5, 0, 2 * Math.PI, true);
context.fill();

context.beginPath();
context.arc(center.x, center.y, r1, 0, 2 * Math.PI, true);
context.arc(center.x, center.y, r2, 0, 2 * Math.PI, true);
context.stroke();
context.beginPath();
context.arc(center.x, center.y, r3, 0, 2 * Math.PI, true);
context.stroke();

context.moveTo(center.x + r1, center.y);
const clockNumbers = [4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3];

for (let alf = 0, i = 0; alf <= 2 * Math.PI; alf += Math.PI / 6, i++) {
  context.arc(center.x, center.y, r1, alf, alf + Math.PI / 6, false);
  context.moveTo(
    center.x + r2 * Math.cos(alf + Math.PI / 6),
    center.y + r2 * Math.sin(alf + Math.PI / 6)
  );
  context.fillText(
    clockNumbers[i],
    center.x + (r2 + 18) * Math.cos(alf + Math.PI / 6) - 9,
    center.y + (r2 + 17) * Math.sin(alf + Math.PI / 6) + 7
  );
  context.stroke();
}

context.translate(center.x, center.y);
context.rotate(-Math.PI);

context.beginPath();
context.fillStyle = "green";
context.fillRect(-2, 0, 5, 80);
context.stroke();

let iter = 1;
let timerId = setInterval(() => {
  context.clearRect(-3, 0, 8, 85);

  if (iter < 31) {
    context.fillStyle = "green";
  } else if (iter < 46) {
    context.fillStyle = "yellow";
  } else if (iter < 60) {
    context.fillStyle = "red";
  } else {
    alert("Вы проиграли!");
    iter = 0;
  }

  context.beginPath();
  context.arc(0, 0, 5, 0, 2 * Math.PI, true);
  context.fill();

  context.rotate(-Math.PI / 30);
  context.fillRect(-2, 0, 5, 80);
  context.stroke();
  iter++;
  console.log(iter);
}, 1000);

const LeosBirthday = document.getElementById("LeosBirthday");

LeosBirthday.oninput = () => {
  let inputValue = LeosBirthday.value;
  console.log(inputValue);
  if (inputValue == 1828) {
    clearTimeout(timerId);
    let div = document.createElement("div");
    const audio = document.querySelector("audio");
    audio.volume = 0;
    div.innerHTML += `<p>Ваше время ещё не пришло</p>`;
    document.body.append(div);
  }
};
