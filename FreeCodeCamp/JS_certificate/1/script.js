const textInput = document.getElementById("text-input");
const checkBtn = document.getElementById("check-btn");
const resultSpan = document.getElementById("result");

function check() {
  if (textInput.value === "") {
    alert("Please input a value");
    return;
  } else {
    const inputValue = textInput.value;
    resultSpan.textContent = inputValue;
    if (isPalindrome(inputValue)) {
      resultSpan.textContent += " is a palindrome";
    } else {
      resultSpan.textContent += " is not a palindrome";
    }
  }
}

checkBtn.addEventListener("click", check);

textInput.addEventListener("keydown", function (event) {
  if (event.key === "Enter") {
    check();
  }
});

function alphanumeric(input) {
    return input.replace(/[^a-zA-Z0-9]/g, '');
}

function isPalindrome(str) {
  const reversedStr = alphanumeric(str).split("").reverse().join("").toLowerCase();
  str = alphanumeric(str).toLowerCase();
  return str === reversedStr;
}