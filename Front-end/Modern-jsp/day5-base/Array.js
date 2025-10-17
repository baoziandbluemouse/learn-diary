
// 使用数组
// let styles = ["Jazz", "Blues"];
// styles.push("Rock-n-Roll");
// let idx = (styles.length - 1 + 1) / 2;
// styles[idx] = "Classics";
// alert(styles.shift());
// styles.unshift("Rap", "Reggae");


//输入数字求和
function sumInput() {
    let a = [];
    while (true) {
        let b = prompt("type the number", 0);
        if (b === "" || b === null || !isFinite(b)) break;
        a.push(+b);
    }
    let sum = 0;
    for (let x of a) {
        sum += x;
    }
    return sum;
}

//alert(sumInput());


//最大子段和

function getMaxSubSum(arr) {
    let maxx = 0;
    let f = [];
    f[0] = arr[0];
    for (let i = 1; i < arr.length; i++) {
        f[i] = Math.max(f[i - 1] + arr[i], arr[i]);
    }
    for (let x of f) {
        maxx = Math.max(maxx, x);
    }
    return maxx;
}

alert(getMaxSubSum([-1, -2, -3]));