 let str = prompt("Enter a string to check if it is a palindrome:");

    let caseSensitive = prompt("Do you want to consider case sensitive? (yes/no)").toLowerCase();

    if (caseSensitive === "no") {
        str = str.toLowerCase();
    }

    let cleanStr = str.replace(/[^a-zA-Z0-9]/g, "");

    let reversed = cleanStr.split("").reverse().join("");

    if (cleanStr === reversed) {
        alert(`"${str}" is a palindrome!`);
    } else {
        alert(`"${str}" is NOT a palindrome.`);
    }