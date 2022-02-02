// get day
var today = new Date();
var thisDay = today.getDay();
console.log(thisDay);

// days of the week array
var daysOfWeek = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];

var daysList = "<hr/>"

for (var i = 0; i < daysOfWeek.length; i++) {
    daysList += "</br>" + daysOfWeek[i];
    if (i == thisDay) {
        daysList += " is today";
    } else if (i == thisDay + 2) {
        daysList += " is our next class";
    }
}

document.getElementById("days").innerHTML = daysList;


// problem of the day
var grades = [77, 88, 99, 78];
var gradeSum = 0;
for (var i = 0; i < grades.length; i++) {
    gradeSum += grades[i];
}

document.getElementById("answer").innerHTML = "quiz total: " + gradeSum;

var gradeAvg = gradeSum / grades.length;

document.getElementById("answer").innerHTML += "</br>avg quiz: " + gradeAvg;


// query selector
// select from css elements
// only selects first one found
document.querySelector('h2').innerHTML = "welcome back from break!";
document.querySelector('h3').innerHTML = "welcome back to javascript!";

// class name
document.getElementsByClassName('odd')[1].style.color = "yellow";

// tag name
var listNodes = document.getElementsByTagName('ul');
listNodes[0].style.border = "2px solid red";

// query selector all
document.querySelectorAll('p')[4].style.backgroundColor = "green";

// change attribute
var alterMen = document.getElementsByClassName("alternative");
alterMen[0].setAttribute("class", "country");

// add item to list
function addItem() {
    // creates new li item with text
    var newItem = prompt("enter new item:");
    var newLIItem = document.createElement("li");
    var newLIText = document.createTextNode(newItem);
    newLIItem.appendChild(newLIText);

    // target the list to add the list item
    var list = document.getElementsByTagName('ul');
    var myList = list[list.length - 1];
    myList.appendChild(newLIItem);
}

// delete item from list
function deleteItem() {
    // target correct list
    var list = document.getElementsByTagName('ul');
    var myList = list[list.length - 1];

    // remove list item
    var lastItem = myList.lastElementChild;
    myList.removeChild(lastItem);
}