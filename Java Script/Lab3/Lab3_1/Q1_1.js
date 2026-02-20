let numbers = [];
function AddElement()
{
    var count = Number(prompt("How many numbers you want to add?"));
    
    for(let i = 0; i < count; i++)
    {
    var num = Number(prompt("Add Numbers ("+ (i+1)+") Please: "));
    numbers.push(num);
    }
}

function displayEntered()
{
    console.log(numbers);
    document.getElementById("entered").textContent = "You've entered the values of: " + numbers;

}

function sortAscending() 
{
    return [...numbers].sort((a, b) => a - b);
}

function sortDescending() 
{
    return [...numbers].sort((a, b) => b - a);
}

function displaySorting() 
{
    let asc = sortAscending();
    let desc = sortDescending();

    document.getElementById("asc").textContent =
        "Ascending Order: " + asc;

    document.getElementById("desc").textContent =
        "Descending Order: " + desc;
}

function runProgram() 
{
    AddElement();
    displayEntered();
    displaySorting();
}

runProgram();