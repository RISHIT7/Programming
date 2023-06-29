function pressed() {
  var text = document.getElementById("inp-1").value;
  switch (text) {
    case "red":
      document.getElementById("header-1").style.color = "red";
      break;
    case "green":
      document.getElementById("header-1").style.color = "green";
      break;
    default:
      document.getElementById("header-1").style.color = "black";
      break;
  }
}
