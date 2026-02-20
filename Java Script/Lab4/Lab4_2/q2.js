var inp = document.querySelector("#Answer");
var lastOperator = false;

function enternum(num) {
    inp.value += num;
    lastOperator = false;
}

function enterOp(op) {
    if (inp.value === "" && (op === "+" || op === "/" || op === "*")) {
        return;
    }

    if (inp.value === "") return;

    if (lastOperator) {
        inp.value = inp.value.slice(0, -1) + op;
    } else {
        inp.value += op;
    }

    lastOperator = true;
}

function entereq() {
    try {
        inp.value = eval(inp.value);
    } catch {
        inp.value = "Error";
    }
}

function entercl() {
    inp.value = "";
    lastOperator = false;
}
