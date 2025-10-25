// Promise常用方法
//工厂函数，创造一个Promise
const makePromise = () => new Promise((resolve, reject) => {
    // 设定异步任务，1秒后完成，并调用resolve，将结果传递出去
    setTimeout(() => {
        //设定50%概率出错
        if (Math.random() > 0.5) resolve("promise完成");
        else reject("promise出错");
    }, 1000);
});
//执行5次
for (let i = 0; i < 5; i++) {
    const promise = makePromise();
    console.log("promise开始，状态为：", promise);
    // 设定任务完成后执行的回调函数，正常结束时执行then里面的回调函数，出错时执行catch里面的回调函数
    // 两个回调函数只会执行一个，不可能都执行
    promise.then((result) => {
        console.log(result); // 这个result就是调用resolve是传入的参数
        console.log("promise完成，状态为：", promise);
    }).catch((err) => {
        console.log(err);
        console.log("promise出错，状态为：", promise);
    });
}

// async / await语法糖

const sleep = (ms) => new Promise(res => setTimeout(res, ms));

const makeAsync = async () => {
    // sleep()会返回一个Promise，它也是可以用await等待的
    // 相当于等待resolve，并将resolve的参数作为返回值
    await sleep(1000);
    if (Math.random() > 0.5) return "async 完成"; // 这里return后面的内容等价于调用resolve时传入的参数
    else throw "async 错误"
}

// await 只能在async函数中使用，否则会报错
// 但是js不允许顶层使用await，所以需要用立即执行函数包起来
(async () => {
    // 执行5次
    for (let i = 0; i < 5; i++) {
        const asyncFunction = makeAsync();
        console.log("async开始，状态为：", asyncFunction);
        try {
            const result = await asyncFunction;
            console.log(result);
            console.log("async完成，状态为：", asyncFunction);
        } catch (error) {
            console.log(error);
            console.log("async出错，状态为：", asyncFunction);
        }
    }
})(); // 声明一个async函数，然后用()调用，立即执行
