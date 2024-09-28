const numberInput = document.getElementById("number");
const convertBtn = document.getElementById("convert-btn");
const outputSpan = document.getElementById("output");

function convert() {
  if (numberInput.value === "") {
    outputSpan.textContent = "Please enter a valid number";
    return;
  } else if (numberInput.value === "e") {
    outputSpan.textContent = "Please enter a valid number";
    return;
  } else {
    const inputValue = numberInput.value;
    outputSpan.textContent = romanNumeral(inputValue);
  }
}

convertBtn.addEventListener("click", convert)

function romanNumeral(str) {
    try {
        parseInt(str);
    } catch (error) {
        return "Please enter a valid number";
    }

    if (parseInt(str) >= 4000) {
        return "Please enter a number less than or equal to 3999";
    } else if (parseInt(str) <= 0) {
        return "Please enter a number greater than or equal to 1";
    }


    const romanNumerals = [
        { numeral: "M", value: 1000 },
        { numeral: "CM", value: 900 },
        { numeral: "D", value: 500 },
        { numeral: "CD", value: 400 },
        { numeral: "C", value: 100 },
        { numeral: "XC", value: 90 },
        { numeral: "L", value: 50 },
        { numeral: "XL", value: 40 },
        { numeral: "X", value: 10 },
        { numeral: "IX", value: 9 },
        { numeral: "V", value: 5 },
        { numeral: "IV", value: 4 },
        { numeral: "I", value: 1 }
    ];
    let result = "";
    let num = parseInt(str);
    for (let i = 0; i < romanNumerals.length; i++) {
        while (num >= romanNumerals[i].value) {
        result += romanNumerals[i].numeral;
        num -= romanNumerals[i].value;
        }
    }
    return result;
}
