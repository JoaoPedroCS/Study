const userInput = document.getElementById('user-input');
const checkBtn = document.getElementById('check-btn');
const clearBtn = document.getElementById('clear-btn');
const resultsDiv = document.getElementById('results-div');

const isValidPhoneNumber = input => {
  if (input === '') {
    alert('Please provide a phone number');
    return;
  }

  const phoneFormat = /^(1\s?)?(\([0-9]{3}\)|[0-9]{3})[\s\-]?[0-9]{3}[\s\-]?[0-9]{4}$/;

  const textElement = document.createElement('p');
  textElement.className = 'text';

  if (phoneFormat.test(input)) {
    textElement.textContent = `Valid US number: ${input}`;
  } else {
    textElement.textContent = `Invalid US number: ${input}`;
  }

  resultsDiv.appendChild(textElement);
};

checkBtn.addEventListener('click', () => {
  isValidPhoneNumber(userInput.value);
  userInput.value = '';
});

userInput.addEventListener('keydown', e => {
  if (e.key === 'Enter') {
    isValidPhoneNumber(userInput.value);
    userInput.value = '';
  }
});

clearBtn.addEventListener('click', () => {
  resultsDiv.textContent = '';
});
