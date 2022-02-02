// current course
var courseNumber = "wdd308";
var courseName = "interaction design";
var creditHours = 3;
var required = true;

var fullCourseName = courseNumber + ": " + courseName;

document.write("i am currently enrolled in " + fullCourseName + ".");


// course load
var myCreditHours = [15, 20, 15, 15];

document.getElementById("creditHrs").innerHTML = "credit hours by semester: " + myCreditHours;

var totalCreditHours = myCreditHours[0] + myCreditHours[1] + myCreditHours[2] + myCreditHours[3];
document.getElementById("creditHrs").innerHTML += "</br>total credit hours: " + totalCreditHours;

var year1Hours = myCreditHours[0] + myCreditHours[1];
var year2Hours = myCreditHours[2] + myCreditHours[3];
var avgPerYear = (year1Hours + year2Hours) / 2;
document.getElementById("creditHrs").innerHTML += "</br>average per year: " + avgPerYear;

document.getElementById("creditHrs").innerHTML += "</br>average per semester: " + (totalCreditHours / 4);


// school supplies
var answers = document.getElementById("ssAnswers");
var ssAnswers;

ssAnswers = "<ol>";

var subtotal = ((2 * 75) + 5 + 30 + (4 * 2) + (3 * 0.75) + 6);
ssAnswers += "<li>subtotal: $" + subtotal + "</li>";

var discountSavings = (subtotal * 0.10).toFixed(2);
ssAnswers += "<li>discount savings: $" + discountSavings + "</li>";

var tax = (subtotal - discountSavings) * 0.08;
var totalPrice = (subtotal + tax).toFixed(2);
ssAnswers += "<li>total: $" + totalPrice + "</li>";

ssAnswers += "</ol>";

answers.innerHTML = ssAnswers;


// your information
var myInfo = {
    firstName: "sam",
    lastName: "nakis",
    age: 21,
    address: "811 w 44th st.",
    hometown: "indianapolis",
    state: "indiana",
    fullAddress: function() {
        return this.address + "</br>" + this.hometown + ", " + this.state;
    }
}

document.getElementById("myInfoAnswer").innerHTML = myInfo.firstName + " " + myInfo.lastName + "</br>" + myInfo.fullAddress();


// my friends
function friendInfo(fName, lName, fAge, email, meet, funFact) {
    this.fName = fName;
    this.lName = lName;
    this.fAge = fAge;
    this.email = email;
    this.meet = meet;
    this.funFact = funFact;
}

var friend1 = new friendInfo("mackenzie", "knudson", 21, "mknudson@butler.edu", "mutual friend", "is a pharmacy major");

var friend2 = new friendInfo("taylor", "lalevee", 21, "tlalevee@butler.edu", "mutual friend", "is a csd major");

document.getElementById("friends1").innerHTML = friend1.fName + " " + friend1.lName + ": " + friend1.funFact;

document.getElementById("friends2").innerHTML = friend2.fName + " " + friend2.lName + ": " + friend2.funFact;