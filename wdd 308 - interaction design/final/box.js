var submitBtn = document.getElementsByTagName('input')[2];

submitBtn.addEventListener("click", calculate, false);

var space = document.getElementById("rectangleSpace");

function calculate() {
    // clearing existing rectangle in the div
    if (space.hasChildNodes) {
        space.innerHTML = "";
    }

    // getting the user input
    var width = document.getElementsByTagName('input')[0].valueAsNumber;
    var height = document.getElementsByTagName('input')[1].valueAsNumber;

    // printing the area
    var area = width * height;
    document.getElementById("sqft").innerHTML = area;

    // making the rectangle
    var rectangle = document.createElement("div");
    rectangle.classList.add("rectangle");

    // setting new pixel values based on instruction
    var widthPx = width * 10;
    var heightPx = height * 10;

    // setting rectangle style properties
    rectangle.style.width = widthPx + "px";
    rectangle.style.height = heightPx + "px";

    // appending the rectangle to the page
    space.appendChild(rectangle);
}