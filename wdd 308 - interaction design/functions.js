// simple function
function changeText() {
    document.getElementById('changeTxt').innerHTML = "this text has been changed!";
}
changeText();


// another simple function
function printBottom() {
    document.write("this function does not take parameters")
}
printBottom();


// yet another simple function
function printConsole() {
    console.log("hello, world!");
}
printConsole();


// simple function with a parameter
function printName(firstName) {
    console.log(firstName);
}
printName("sam");
printName("mackenzie");
printName("taylor");


// using parameters: rectangle perimeter calculator
var height = 10;
var width = 12;

function calcPerimeter(pHeight, pWidth) {
    var recPerm = (2 * pHeight) + (2 * pWidth);
    return recPerm;
}
document.getElementById("panswer").innerHTML = calcPerimeter(height, width) + " feet";

// another option
var recPermAnswer = calcPerimeter(5, 9);
document.getElementById("panswer").innerHTML += "</br>" + recPermAnswer + " feet";


// simple function: square foot calculator
function calcArea() {
    var aHeight = document.getElementById("height").value;
    var aWidth = document.getElementById("width").value;

    var area = aHeight * aWidth;
    document.getElementById("answer").innerHTML = area + " sq. ft.";
}


// testing
function testing() {
    return "dog";
    return "cat";
}
console.log(testing());
// this only returns one value


// multiple values function: rectangle properties
function newRectangle(height, width) {
    var recPerimeter = (2 * height) + (2 * width);
    var recArea = height * width;

    var recInfo = [recArea, recPerimeter];
    return recInfo;
}
document.getElementById("multiAnswer").innerHTML = "area: " + newRectangle(3, 8)[0] + " sq ft</br>" + "perimeter: " + newRectangle(3, 8)[1] + " feet";


// button functions
function stranger() {
    alert("well, hello stranger!");
}


// button functions with parameters
function wizard(name, job) {
    document.getElementById("future").innerHTML = "welcome " + name + ", the " + job + "!";
}


// another button function
function addItem() {
    var newItem = prompt("add item: ");
    console.log(newItem);
}