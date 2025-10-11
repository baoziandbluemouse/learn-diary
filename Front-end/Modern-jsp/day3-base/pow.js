"use strict";

let x = +prompt("number");
let n = +prompt("jie");

function pow(x, y)
{
    let res = 1;
    for (let i = 1; i <= y; i++)
    {
        res *= x;
    }
    return res;
}

if (n < 1)
{
    alert(`Power ${n} is not supported, use a positive integer`);
} else {
    alert(pow(x, n));
}