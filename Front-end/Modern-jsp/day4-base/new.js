function Calculator() {
    this.read = function () {
        this.a = +prompt("first", 0);
        this.b = +prompt("second", 0);
    };
    this.sum = function () {
        if (this.a != undefined && this.b != undefined) {
            return this.a + this.b;
        }
    };
    this.mul = function () {
        if (this.a != undefined && this.b != undefined) {
            return this.a * this.b;
        }
    };
};

// let calculator = new Calculator();
// calculator.read();

// alert("Sum=" + calculator.sum());
// alert("Mul=" + calculator.mul());

function Accumulator(startingValue) {
    this.value = startingValue;
    this.read = function () {
        this.value += +prompt("num?", 0);
    }
}

let accumulator = new Accumulator(1); // 初始值 1

accumulator.read(); // 添加用户输入的 value
accumulator.read(); // 添加用户输入的 value

alert(accumulator.value); // 显示这些值的总和