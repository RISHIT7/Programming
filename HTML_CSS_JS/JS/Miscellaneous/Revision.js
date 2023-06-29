total = 0
function addition(numbers){
    numbers.forEach(function (num) {
    total = total + num;
    });
    console.log(total);
}
addition([10,11,12,13])