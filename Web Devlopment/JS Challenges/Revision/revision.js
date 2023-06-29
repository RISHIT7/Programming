//Model
function fetch_data() {
  const store = [];
  for (let i = 0; i < 26; i++) {
    store[i] = 0;
  }
  const string = document.getElementById("input-text").value;
  for (let i = 0; i < string.length; i++) {
    store[string[i].charCodeAt(0) - 97] += 1;
  }
  // we have the store list correctly done
  let Max = -1;
  let ans;
  for (let i = 0; i < 26; i++) {
    if (Max < store[i]) {
      Max = store[i];
    }
  }
  for (let i = 0; i < 26; i++) {
    if (store[i] == Max) {
      ans = String.fromCharCode(i + 97);
      break;
    }
  }
  return ans;
}

//View
function render(letter) {
  console.log(letter);
  document.getElementById('ans').innerText = "";
  let el = document.createElement("div");
  el.innerText = letter;
  document.getElementById("ans").appendChild(el);
}

//Controller
function main() {
  let letter = fetch_data();
  render(letter);
}
