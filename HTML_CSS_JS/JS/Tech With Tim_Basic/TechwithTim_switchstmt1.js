function pressed() {
  var text = document.getElementById("inp-1").value;
  if (text === "red") {
    document.getElementById("header-1").style.color = "red";
  } else if (text === "green") {
    document.getElementById("header-1").style.color = "green";
  } else {
    document.getElementById("header-1").style.color = "black";
  }
}
