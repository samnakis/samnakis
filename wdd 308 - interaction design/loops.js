// for loops

for (var i = 0; i < 5; i++) {
    document.getElementById('for').innerHTML += "number: " + i + "</br>";
}

var grades = [77, 88, 99, 78];
var gradeSum = 0;
for (var i = 0; i < grades.length; i++) {
    gradeSum += grades[i];
}
document.write("grade total: " + gradeSum);


// while loops
var days = 3;

while (days > 0) {
    if (days == 1) {
        document.getElementById("while").innerHTML += "there is only " + days + " day until fall break begins!</br>";
    } else {
        document.getElementById("while").innerHTML += "there are " + days + " days until fall break begins</br>";
    }
    days--;
}


// do while loops (always runs at least once)
var cheers = 50;
do {
    document.getElementById("doWhile").innerHTML += "give " + cheers + " cheers for fall break!</br>"
    cheers -= 5;
} while (cheers > 0);


// examples
// 1.
var months = ["January", "February", "March", "April", "May", "June"];

for (var i = 0; i < months.length; i++) {
    document.getElementById("months").innerHTML += months[i] + "</br>";
}

// 1 - dropdown
var ddText = "<select>";

for (var i = 0; i < months.length; i++) {
    ddText += '<option value="' + months[i] + '">' + months[i] + '</option>';
}
ddText += "</select>";

document.getElementById("months2").innerHTML = ddText;


// 2.
var answers = document.getElementById("monthOL");
var mol;

mol = "<ol>";

var allMonths = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
for (var i = 0; i < allMonths.length; i++) {
    mol += "<li>" + allMonths[i] + "</li>";
}

mol += "</ol>";

answers.innerHTML = mol;


// 3.
var slices = 9;
while (slices > 2) {
    document.getElementById("pizza").innerHTML += "there are " + slices + " slices of pizza left" + "</br>";
    slices--;
}


// 4.
var count = 15;
do {
    document.getElementById("numCount").innerHTML += "num count: " + count + "</br>";
    count++;
} while (count < 20)


// 5.
var pizzaSlices = 10;
while (pizzaSlices > 1) {
    document.getElementById("pizza2").innerHTML += "another slice down the hatch, " + pizzaSlices + " slices left!</br>";
    pizzaSlices--;
    if (pizzaSlices == 1) {
        document.getElementById("pizza2").innerHTML += "there is only " + pizzaSlices + " slice left!</br>";
        break;
    }
}