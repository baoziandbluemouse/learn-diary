let user = {};
user.name = "john";
user.surname = "Smith";
user.name = "Pete";
delete user.name;

let schedule = {};

alert(isEmpty(schedule)); // true

schedule["8:30"] = "get up";

alert(isEmpty(schedule)); // false

function isEmpty(obj) {
    for (let x in obj) {
        //如果进入循环，代表有属性，返回false
        return false;
    }
    return true;
}

let salaries = {
    John: 100,
    Ann: 160,
    Pete: 130
}

alert(sumObj(salaries));

function sumObj(obj) {
    let sum = 0;
    for (let x in obj) {
        sum += obj[x];
    }
    return sum;
}


// 在调用之前
let menu = {
    width: 200,
    height: 300,
    title: "My menu"
};

multiplyNumeric(menu);

for (let key in menu) {
    console.log(menu[key]);
}

// 调用函数之后
// menu = {
//     width: 400,
//     height: 600,
//     title: "My menu"
// };

function multiplyNumeric(obj) {
    for (let key in obj) {
        if (typeof obj[key] == 'number') {
            obj[key] *= 2;
        }
    }
}

