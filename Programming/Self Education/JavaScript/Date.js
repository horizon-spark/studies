'use strict';
// (1)
// let date = new Date(2012,1,20,3,12);
// alert(date);

// (2)
// function getWeekDay(date) {
//     let weekDays = ["SU","MO","TU","WE","TH","FR","SA"];
//     return weekDays[date.getDay()];
// }
// let date = new Date(2012, 0, 3);  // 3 января 2012 года
// alert( getWeekDay(date) );        // нужно вывести "ВТ"

// (3)
// function getLocalDay(date) {
//     let weekDays = ["MO","TU","WE","TH","FR","SA","SU"];
//     if (date.getDay() == 0) return weekDays[7];
//     return weekDays[date.getDay() - 1];
// }
// let date = new Date(2012, 0, 3);  // 3 января 2012 года
// alert( getLocalDay(date) );       // вторник, нужно показать 2

// (4)
// function getDateAgo(date, days) {
//     return new Date(+date - 1000 * 3600 * 24 * days);
// }

// let date = new Date(2015, 0, 2);

// alert( getDateAgo(date, 1) ); // 1, (1 Jan 2015)
// alert( getDateAgo(date, 2) ); // 31, (31 Dec 2014)
// alert( getDateAgo(date, 365) ); // 2, (2 Jan 2014)

// (5)
// function getLastDayOfMonth(year, month) {
//     let date = new Date(year, month + 1, 0);
//     return date.getDate();
// }

// alert( getLastDayOfMonth(2012, 0) ); // 31
// alert( getLastDayOfMonth(2012, 1) ); // 29
// alert( getLastDayOfMonth(2013, 1) ); // 28

// (6)
// function getSecondsToday() {
//     let date = new Date();
//     return 3600 * date.getHours() + 60 * date.getMinutes() + date.getSeconds();
// }
// alert(getSecondsToday());
