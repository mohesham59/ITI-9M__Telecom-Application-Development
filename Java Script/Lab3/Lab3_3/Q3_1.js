console.log(" Task 3 ");

var navList = document.getElementById("nav");
var items = navList.children;


items[0].innerHTML = "<strong>Memo</strong>";
items[1].children[0].textContent = "Articles";
items[2].children[0].textContent = "Photos";
items[3].children[0].textContent = "About";
items[4].children[0].textContent = "Clients";
items[5].children[0].textContent = "Contact";


var headerDiv = document.getElementById("header");
headerDiv.style.textAlign = "right";


var originalImg = headerDiv.querySelector("img");
var clonedImg = originalImg.cloneNode(true);
var footerDiv = document.createElement("div");

footerDiv.style.textAlign = "left";
footerDiv.style.marginTop = "50px";
footerDiv.style.borderTop = "2px solid #ccc";

footerDiv.appendChild(clonedImg);
document.body.appendChild(footerDiv);


navList.style.listStylePosition = "inside"; 

navList.style.direction = "ltr";