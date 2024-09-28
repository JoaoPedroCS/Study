const costumerCash = document.getElementById("cash");
const evaluate = document.getElementById("purchase-btn");
const changeDue = document.getElementById("change-due");
let cash = changeDue.value;

let price = 19.5;

let cid = [
  ["PENNY", 1.01],
  ["NICKEL", 2.05],
  ["DIME", 3.1],
  ["QUARTER", 4.25],
  ["ONE", 90],
  ["FIVE", 55],
  ["TEN", 20],
  ["TWENTY", 60],
  ["ONE HUNDRED", 100],
];
let bckp = cid.map((arr) => [...arr]);

const values = [0.01, 0.05, 0.1, 0.25, 1, 5, 10, 20, 100];

evaluate.addEventListener("click", () => {
  changeDue.innerHTML = "";
  let cash = parseFloat(costumerCash.value).toFixed(2);
  let change = parseFloat((cash - price).toFixed(2));
  let availableChange = parseFloat(
    cid.reduce((sum, current) => sum + current[1], 0).toFixed(2)
  );
  if (cash < price) {
    alert("Customer does not have enough money to purchase the item");
    return;
  } else if (cash == price) {
    createAppendP("No change due - customer paid with exact cash");
    return;
  } else if (change > availableChange) {
    createAppendP("Status: INSUFFICIENT_FUNDS");
    return;
  } else {
    if (availableChange == change) {
      createAppendP("Status: CLOSED");
      evalPrint(change, cid);
    } else {
      createAppendP("Status: OPEN");
      change = evalPrint(change, cid);
      if (change > 0) {
        changeDue.innerHTML = "";
        createAppendP("Status: INSUFFICIENT_FUNDS");
        cid = bckp;
        return;
      } else {
        return;
      }
    }
  }
});

function removeTrailingZeros(num) {
  let numStr = num.toString();
  numStr = numStr.includes(".") ? numStr.replace(/\.?0*$/, "") : numStr;
  return numStr;
}

function evalPrint(change, cid) {
  let times = 0;
  for (let i = 8; i > -1; i--) {
    times = 0;
    while (cid[i][1] > 0 && change >= values[i]) {
      times += 1;
      cid[i][1] -= values[i];
      change -= values[i];
      change = parseFloat(change.toFixed(2));
    }
    if (times >= 1) {
      createAppendP(
        cid[i][0] +
          ": $" +
          String(removeTrailingZeros(parseFloat(values[i] * times).toFixed(2)))
      );
    }
  }
  cid.forEach((arr) => {
    let text = arr[0] + ": $" + arr[1];
    const textElement = document.createElement("p");
    textElement.textContent = text;
    cashDisplay.appendChild(textElement);
  });
  return change;
}

function createAppendP(str) {
  const textElement = document.createElement("p");
  textElement.className = "text";
  textElement.textContent = str;
  changeDue.appendChild(textElement);
}

const priceScreen = document.getElementById("price-screen");
priceScreen.textContent = "price: $" + price;

const cashDisplay = document.getElementById("cash-drawer-display");