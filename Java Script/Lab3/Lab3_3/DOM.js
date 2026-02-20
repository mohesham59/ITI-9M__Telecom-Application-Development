console.log(" Task 3 ");

var navList = document.getElementById("nav");
var items = navList.children; 
items[0].innerHTML = "<strong>Mamu</strong>";

items[2].children[0].textContent = "Thains"; 

navList.removeChild(items[3]);

items[3].children[0].textContent = "Ciesta";
items[4].children[0].textContent = "Conta";

var headerDiv = document.getElementById("header");
var originalImg = headerDiv.querySelector("img");

var clonedImg = originalImg.cloneNode(true);
var footerDiv = document.createElement("div");

footerDiv.style.textAlign = "right";
footerDiv.style.marginTop = "20px";
footerDiv.appendChild(clonedImg);

document.body.appendChild(footerDiv);