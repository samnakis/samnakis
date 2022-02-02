// 1
var today = new Date();

var thisDay = today.getDate();
var thisMonth = today.getMonth();
var thisYear = today.getFullYear();

var months = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];

monthName = months[thisMonth];

document.getElementById("date").innerHTML = monthName + " " + thisDay + ", " + thisYear;


// 2
var monthAnswer = "";

for (var i = 0; i < months.length; i++) {
    monthAnswer += "</br>" + months[i];
    if (i == thisMonth) {
        monthAnswer += " --> Current Month";
    }
}

document.getElementById("monthList").innerHTML = monthAnswer;


// 3
var monthDD = '<select id="dropdown">';

for (var i = 0; i < months.length; i++) {
    monthDD += '<option value=' + i + '>' + months[i] + '</option>';
}
monthDD += "</select>";

document.getElementById("monthDropDown").innerHTML += monthDD;


// extra credit
var holidays = ["New Year's Day", "Valentine's Day", "St. Patrick's Day", "Easter", "Mother's Day", "Father's Day", "Fourth of July", "Start of School", "Labor Day", "Halloween", "Thanksgiving", "Christmas"];

function getOption() {
    var select = document.getElementById('dropdown');
    var value = select.options[select.selectedIndex].value;
    // console.log(value);

    document.getElementById("holiday").innerHTML = holidays[value];
}

// function submitForm() {
//     console.log(document.getElementById('dropdown').value);
//     document.getElementById("monthDropDown").innerHTML += holidays[value];
// }

// console.log(document.getElementById('dropdown').value);

// function update() {
//     var select = document.getElementById("dropdown");
//     var value = select.options[select.selectedIndex].value;

//     document.getElementById("monthDropDown").innerHTML += "</br>" + holidays[value];

//     console.log(value);
// }