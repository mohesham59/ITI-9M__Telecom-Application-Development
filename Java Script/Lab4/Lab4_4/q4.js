var images = document.querySelectorAll("#Bulls img");
var bulls = document.getElementById("Bulls");

var index = 0;
var interval = null;

function move() {
  images[index].src = "photos/1.jpg";

  index = (index + 1) % images.length;

  images[index].src = "photos/2.jpg";
}

function start() {
  if (interval !== null) return;
  interval = setInterval(move, 500);
}

function stop() {
  clearInterval(interval);
  interval = null;
}

images.forEach(function (img) {
  img.addEventListener("mouseover", stop);
  img.addEventListener("mouseout", start);
});

start();
