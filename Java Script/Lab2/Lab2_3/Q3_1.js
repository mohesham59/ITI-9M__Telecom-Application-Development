let numbers = [];
    for (let i = 0; i < 3; i++) {
        let num = parseFloat(prompt(`Enter number ${i+1}:`));
        numbers.push(num);
    }

    let a = numbers[0];
    let b = numbers[1];
    let c = numbers[2];

    let sum = a + b + c;
    let multiplication = a * b * c;
    let division = a / b / c;

    document.write(`sum of the 3 values ${a}+${b}+${c} = ${sum}`);
    document.write(`<br>multiplication of the 3 values ${a}*${b}*${c} = ${multiplication}`);
    document.write(`<br>division of the 3 values ${a}/${b}/${c} = ${division}`);