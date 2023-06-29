function Upper(name) {
  list = [];
  name.forEach(function (str) {
    list.push(str.toUpperCase());
  });
  console.log(list);
}
Upper(["rishit", "jakharia"]);

function upper(name) {
  list = [];
  name.forEach(function (str) {
    list.push(str);
    list.push(str);
  });
  console.log(list);
}
upper(["rishit", "jakharia"]);

function arraySum(numArray) {
  let total = 0;

  numArray.forEach(function (num) {
    total = total + num;
  });

  console.log(total);
}
arraySum([1, 2, 3]);
arraySum([5, -2, 7, 0]);
