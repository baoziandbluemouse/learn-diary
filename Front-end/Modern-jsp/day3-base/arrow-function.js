"use strict";

let ask = (question, yes, no) => {
    if (confirm(question)) yes();
    else no();
};

ask("do you agree?", () => alert("yes"), () => alert("no"));