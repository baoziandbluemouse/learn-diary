
//使用Date
let date = new Date(2012, 1, 20, 3, 12);
//alert(date);


//表示星期
function getWeekDay(date) {
    let days = ['SU', 'MO', 'TU', 'WE', 'TH', 'FR', 'SA'];
    return days[date.getDay()];
}

// let date2 = new Date(2014, 0, 3); // 3 Jan 2014
// alert(getWeekDay(date2)); // FR


//欧洲星期表示法
function getLocalDay(date) {

    let day = date.getDay();

    if (day == 0) { // weekday 0 (sunday) is 7 in european
        day = 7;
    }

    return day;
}


//许多天之前是多少号
function getDateAgo(date, days) {
    let copy = new Date(date);
    copy.setDate(date.getDate() - days);
    return copy.getDate();
}

//let date3 = new Date(2015, 0, 2);

// alert(getDateAgo(date3, 1)); // 1, (1 Jan 2015)
// alert(getDateAgo(date3, 2)); // 31, (31 Dec 2014)
// alert(getDateAgo(date3, 365)); // 2, (2 Jan 2014)


//某月的最后一天

function getLastDayOfMonth(year, month) {
    let date = new Date(year, month + 1, 0);
    return date.getDate();
}


// alert(getLastDayOfMonth(2012, 0)); // 31
// alert(getLastDayOfMonth(2012, 1)); // 29
// alert(getLastDayOfMonth(2013, 1)); // 28

function formatDate(date) {
    let diff = new Date() - date;
    if (diff < 1000) { // 少于 1 秒
        return 'right now';
    }
    let sec = Math.floor(diff / 1000);
    if (sec < 60) {
        return sec + 'sec.ago';
    }
    let min = Math.floor(sec / 60);
    if (min < 60) {
        return min + 'min.ago';
    }
    // 格式化 date
    // 将前置 0 加到一位数 day /month/hours/minutes 前
    let d = date;
    d = [
        '0' + d.getDate(),
        '0' + (d.getMonth() + 1),
        '' + d.getFullYear(),
        '0' + d.getHours(),
        '0' + d.getMinutes()
    ].map(component => component.slice(-2)); // 得到每个组件的后两位

    return d.slice(0, 3).join('.') + ' ' + d.slice(3).join(':');
}

alert(formatDate(new Date(new Date - 1))); // "right now"

alert(formatDate(new Date(new Date - 30 * 1000))); // "30 sec. ago"

alert(formatDate(new Date(new Date - 5 * 60 * 1000))); // "5 min. ago"

// 昨天的日期如：31.12.2016 20:00
alert(formatDate(new Date(new Date - 86400 * 1000)));