function random(a, b) {
  return Math.random() * (b - a) + a;
}
console.log(random(1, 100));

function reversString(String) {
  string = String.split("").reverse().join("");
  return string;
}
console.log(reversString("I am Rishit"))

function reversInt(Int){
    string = Int.toString()
    gnirts = string.split('').reverse().join('')
    return gnirts
}
console.log(reversInt(367542))