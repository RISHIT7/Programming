//Model
function pickApples(list) {
  let i = 2;
  let new_list = list.filter(function (todo) {
    if (i > 0 && todo == "apple") {
      i--;
      console.log(i);
      return false;
    } else {
      return true;
    }
  });
  console.log(new_list);
  render(new_list);
}
//View
function render(list) {
  document.getElementById("div-display").innerText = "";
  list.forEach((ele) => {
    const element = document.createElement("div");
    element.innerText = ele;
    document.getElementById("div-display").appendChild(element);
  });
}
