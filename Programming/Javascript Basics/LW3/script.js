import { API_KEY } from "./apiKey.js";

const inputText = document.querySelector(".inputText");
const outputText = document.querySelector(".outputText");
const translations = document.querySelector(".translations");

let timerId = 1;

const PART_OF_SPEECH = new Map();
PART_OF_SPEECH.set("noun", "сущ")
  .set("verb", "гл")
  .set("adjective", "прил")
  .set("adverb", "нар")
  .set("pronoun", "мест")
  .set("preposition", "предл")
  .set("conjunction", "союз")
  .set("article", "артикль")
  .set("particle", "част")
  .set("interjection", "межд");

inputText.oninput = function () {
  clearTimeout(timerId);

  timerId = setTimeout(async function () {
    if (inputText.value === "") return;

    const url = `https://dictionary.yandex.net/api/v1/dicservice.json/lookup?key=${API_KEY}&lang=en-ru&text=${inputText.value}`;
    const response = await fetch(url);

    const defs = document.querySelectorAll(".definitions");
    console.log(defs);
    for (let def of defs) {
      def.remove();
    }

    if (response.ok) {
      const result = await response.json();
      console.log(result);

      if (result.def.length === 0) {
        outputText.value = "Слово не найдено";
        return;
      }

      result.def.forEach((element) => {
        let div = document.createElement("div");
        div.className = "definitions";
        let ol = document.createElement("ol");

        div.innerHTML =
          element.pos && PART_OF_SPEECH.get(element.pos)
            ? `<p>${PART_OF_SPEECH.get(element.pos)}</p>`
            : "<p>неизв</p>";

        element.tr.forEach((definition) => {
          ol.innerHTML += `<li>${definition.text}</li>`;
        });
        div.append(ol);
        translations.append(div);
      });
      outputText.value = result.def[0].tr[0].text;
    } else {
      alert("Ошибка HTTP: " + response.status);
    }
  }, 1000);
};
