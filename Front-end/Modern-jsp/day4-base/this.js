
//1.使用this
// function makeUser() {
//     return {
//         name: 'John',
//         ref: this,
//     };
// }

// let user = makeUser();

// function makeUser() {
//     return {
//         name: "John",
//         ref() {
//             return this;
//         }
//     };
// }

// let user = makeUser();

// //alert(user.ref().name); // John

//2.对象计算器
// let calculator = {
//     read() {
//         this.a = +prompt("first value");
//         this.b = +prompt("second value");
//     },
//     sum() {
//         if (this.a != undefined && this.b != undefined) {
//             return this.a + this.b;
//         }
//     },
//     mul() {
//         if (this.a != undefined && this.b != undefined) {
//             return this.a * this.b;
//         }
//     },
// };

// calculator.read();
// alert(calculator.sum());
// alert(calculator.mul());

//3.链式调用
let ladder = {
    step: 0,
    up() {
        this.step++;
        return this;
    },
    down() {
        this.step--;
        return this;
    },
    showStep: function(){
        alert(this.step);
        return this;
    }
};

ladder.up().up().down().showStep().down().showStep(); // 展示 1，然后 0