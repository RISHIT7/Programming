var mp = new Map([
  ["t", 8],
  ["v", 5],
]); // similar to dictionary
console.log(mp.get("t"));
console.log(mp.has("t")); // true
console.log(mp.entries());
for (var entry of mp) {
  console.log(entry);
}
for (var entry of mp) {
  console.log(entry[0]);
}
for (var entry of mp) {
  console.log(entry[1]);
}
mp.clear();

str = "this is my new string hello";
for (var letter of str) {
  if (mp.has(letter)) {
    mp.set(letter, mp.get(letter) + 1);
  } else {
    mp.set(letter, 1);
  }
}
console.log(mp)