var Images = ["1.jpg","2.jpg","3.jpg","4.jpg","5.jpg","6.jpg"];
var Index = 0;
var Img = document.getElementById("gallery");
var slideInterval = null;

// Show Image Function
function showImage() {
    Img.src = "photo/" + Images[Index];
}

// Next
function next() {
    Index++;
    if (Index >= Images.length) Index = 0;
    showImage();
}

// Previous
function prev() {
    Index--;
    if (Index < 0) Index = Images.length - 1;
    showImage();
}

// Start Slideshow
function startSlide() {
    if (slideInterval !== null) return; 

    slideInterval = setInterval(function () {
        next();
    }, 1500);
}

// Stop Slideshow
function stopSlide() {
    clearInterval(slideInterval);
    slideInterval = null;
}
console.log(Img);

