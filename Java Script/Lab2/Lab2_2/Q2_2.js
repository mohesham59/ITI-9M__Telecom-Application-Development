 let squareRoot;
        squareRoot = prompt("Enter a number to find its square root:");
        squareRoot = parseFloat(squareRoot);
        if (isNaN(squareRoot) || squareRoot < 0) {
            alert("Please enter a valid non-negative number for the square root.");
        } else {
            const result = Math.sqrt(squareRoot);
            alert(`The square root of ${squareRoot} is: ${result.toFixed(2)}`);
        }