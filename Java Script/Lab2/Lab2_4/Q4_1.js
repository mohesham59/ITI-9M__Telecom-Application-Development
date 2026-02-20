function twoParamsOnly(a, b) {
        if (arguments.length !== 2) {
            throw new Error("Function accepts exactly 2 parameters!");
        }
        return `First: ${a}, Second: ${b}`;
    }

    try {
        console.log(twoParamsOnly(5, 10));
        console.log(twoParamsOnly(1));     
    } catch (e) {
        console.error(e.message);
    }