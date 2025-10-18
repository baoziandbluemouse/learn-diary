

//闭包sum
function sum(first) {
    let a = first;
    return function (second) {
        return a + second;
    }
}

alert(sum(1)(2));
alert(sum(5)(-1));