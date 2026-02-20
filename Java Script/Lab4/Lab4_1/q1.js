var box = document.getElementById("box");

box.addEventListener("click", function () {

    var newDiv = this.cloneNode(true);
    var r = Math.round(Math.random()*256);
    var g = Math.round(Math.random()*256);
    var b = Math.round(Math.random()*256);
    newDiv.style.backgroundColor = `rgb(${r},${g},${b})`;
    document.body.appendChild(newDiv);

});