const image = document.querySelector("#people");

const getCoords = (elem) => {
  let box = elem.getBoundingClientRect();

  return {
    top: box.top + window.pageYOffset,
    right: box.right + window.pageXOffset,
    bottom: box.bottom + window.pageYOffset,
    left: box.left + window.pageXOffset,
  };
};

const generateRandomCoordsInRange = ({ top, right, bottom, left }) => {
  left = Math.ceil(left);
  right = Math.floor(right);
  top = Math.ceil(top);
  bottom = Math.floor(bottom);

  let x = Math.floor(Math.random() * (right - left + 1) + left);
  let y = Math.floor(Math.random() * (bottom - top + 1) + top);

  return { x, y };
};

const target = generateRandomCoordsInRange(getCoords(image));

document.addEventListener("click", (e) => {
  const pictureBordersCoords = getCoords(image);
  if (
    e.pageX > pictureBordersCoords.right ||
    e.pageX < pictureBordersCoords.left ||
    e.pageY > pictureBordersCoords.bottom ||
    e.pageY < pictureBordersCoords.top
  ) {
    return;
  }

  console.log(`x = ${e.pageX}, y = ${e.pageY}`);

  const initialDiagonal = Math.sqrt(
    Math.pow((pictureBordersCoords.bottom - pictureBordersCoords.top) / 2, 2) +
      Math.pow((pictureBordersCoords.right - pictureBordersCoords.left) / 2, 2)
  );

  const distance = Math.sqrt(
    Math.pow(e.pageX - target.x, 2) + Math.pow(e.pageY - target.y, 2)
  );

  if (distance > initialDiagonal) {
    console.log("Северный полюс");
  } else if (distance <= initialDiagonal && distance > initialDiagonal / 2) {
    console.log("Холодно");
  } else if (
    distance <= initialDiagonal / 2 &&
    distance > initialDiagonal / 4
  ) {
    console.log("Тепло");
  } else if (
    distance <= initialDiagonal / 4 &&
    distance > initialDiagonal / 8
  ) {
    console.log("Горячо");
  } else if (
    distance <= initialDiagonal / 8 &&
    distance > initialDiagonal / 16
  ) {
    console.log("Обожжешься");
  } else {
    console.log("Шпион найден");
  }
});

console.log(getCoords(image));
console.log(target);
