// // 1- Try the following piece and write the answer 
// // a
// var y;  
// console.log(y);  

// // b
// console.log(y);  

// // c
// var x=10; 
// var y = 20;  
// console.log(y*x-2);  

// // d
// var y;  
// console.log(typeof y);  

// // e
// var x = "1"; 
// var y = 2; 
// console.log(x+y);  //convert number to string and do conacnt

// // f
// var x = 1;  
// var y = true; 
// console.log(x+y);  // true = 1 => 1+1=2

//====================================================================
//====================================================================

// // 2- Ask the user to enter a message then display it using the different html 
// // heading tags (from <h1> to <h6>) using Loops. DO NOT write the header 
// // element explicitly in your script!

// do
// {
//     var res = prompt("Enter your message please: ");
//     if (res === null) 
//         break;

//     if (!isNaN(res)) 
//     {
//         alert("Please enter a string value!");
//         continue;
//     }

//     break;

// } while(true);

// for(var i=1; i<=6; i++)
// {
//     document.write("<h" + i + " style='color:red'>" + res + "</h" + i + ">");
// }

//====================================================================
//====================================================================

// // 3- Write a script that takes from the user n values and returns their sum, stop 
// // receiving values from user when he enters 0 or sum exceeds 100, check that 
// // the entered data is numeric and inform the user with the total sum of the 
// // entered values. 

// var sum=0;
// var res;
// do
// {
//     res = prompt("Enter the number please: ");

//     if (res === null) 
        
//         break;

//     if (isNaN(res)) 
//     {
//         alert("Please enter a numeric value!");
//         continue;
//     }

//     res = Number(res)

//     if (res === 0) 
//         break;

//     sum += res;

// } while(sum <= 100)
    
// alert("Sum is: \n" + sum);


//====================================================================
//====================================================================


// // 4- On contact page prompt user to enter his name, make sure that name is string, 
// // and let the user enter his birth year and make sure that it is a number, and it is 
// // less than 2010, and then calculate his age. For each prompt if user input valid 
// // show him next prompt, if not valid show him the same prompt again until user 
// // enters it correctly (use loops). And after validating user input, write all user 
// // input on the page in that format: 
// // Name: ahmed 
// // Birth year: 1981 
// // Age: 30

// var nameuser;
// var age;
// var birthyear;
// do
// {
//     nameuser = prompt("Enter yor name please: ");

//     if (nameuser == null) 
//         break;

//     if (!isNaN(nameuser)) 
//     {
//         alert("Please enter a string value!");
//         continue;
//     }

//     birthyear = prompt("Enter yor birth year please: ")
    
//     birthyear = Number(birthyear)
//     if (birthyear < 2010)
//     {
//         var year = new Date();
//         age = year.getFullYear() - birthyear;
//     }
//     else
//     {
//         alert("Warning the birth year must be less than 2010")
//         break;
//     }

//     break;
    
// } while(true)
    
// alert("Name: " + nameuser);
// alert("Birth year: " + birthyear);
// alert("Age: " + age);