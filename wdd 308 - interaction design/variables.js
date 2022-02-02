// basic variable types
// string
var currentClass = "wdd308";

// integer
var classGrade = 93;

// boolean
var requiredClass = true;

document.write(currentClass);
document.write("hello world</br>");

console.log(classGrade);
console.log("got here");

document.getElementById("myPet").innerHTML = "helllllo";

var firstName = "sam";
var lastName = "nakis";
var street = "811 w 44th st";
var city = "indianapolis";
var state = "indiana";
var zip = 46208;

document.write(firstName + " " + lastName + "</br>");
var fullName = firstName + " " + lastName;
var fullAddress = street + "</br>" + city + ", " + state + " " + zip + "</br>";
document.write(fullAddress);

document.getElementById("myAddress").innerHTML = fullName + "</br>" + fullAddress;

var x = 12;
var y = 5;
var z = "5";
var subNum = x - y;
var remainderNum = x % y;
var multiNum = y * z;

document.write("<p>" + (x + y) + "</p>");
document.write("<p>" + subNum + "</p>");
document.write("<p>" + remainderNum + "</p>");
document.write("<p>" + multiNum + "</p>");
document.write("<p>" + (y + z) + "</p>");

// all ways to increase by 1
y = y + 1;
y += 1;
y++;

// all ways to decrease by 1
y = y - 1;
y -= 1;
y--;

var newNum = 7;
document.write(newNum + "</br>");
document.write(newNum++ + "</br>"); // prints first then adds
document.write(newNum + "</br>");
document.write(++newNum + "</br>"); // adds then prints

var myCar = [2005, "nissan", "armada", "automatic", "black"];

document.write(myCar[1] + "</br>");
document.write("i own a " + myCar[0] + " " + myCar[4] + " " + myCar[1] + " " + myCar[2] + ".");