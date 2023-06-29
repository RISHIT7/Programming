function add(x) {
  return (x = x + 10);
}
console.log(add(10));

function addlist(a, b) {
  return a + b;
}

console.log(addlist(10, 10));

function red() {
  console.log("red");
  document.getElementById("header-1").innerHTML = "Red";
  document.getElementById("header-1").style.color = "red";
}
function green() {
  console.log("green");
  document.getElementById("header-1").innerHTML = "Green";
  document.getElementById("header-1").style.color = "green";
}