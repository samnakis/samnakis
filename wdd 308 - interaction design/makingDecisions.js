// problem 1
var age = prompt("hello user! what is your age?");
if (age > 26) {
    document.getElementById("p1Answer").innerHTML = "spaceship navigation granted!";
} else {
    document.getElementById("p1Answer").innerHTML = "spaceship navigation denied!";
}


// problem 2
var grades = [87, 56, 92, 77];
var gradeSum = 0;
for (var i = 0; i < grades.length; i++) {
    gradeSum += grades[i];
}
gradeAvg = (gradeSum / grades.length);

if (gradeAvg > 75) {
    document.getElementById("p2Answer").innerHTML = "you are in the top 25% of the class, congrats!";
} else if (gradeAvg <= 75 && gradeAvg >= 60) {
    document.getElementById("p2Answer").innerHTML = "you passed the class!";
} else {
    document.getElementById("p2Answer").innerHTML = "sorry, you did not pass the class, better luck next time!";
}


// problem 3
function getRandomNum() {
    var ranNum = Math.floor(Math.random() * 5) + 1;

    switch (ranNum) {
        case 1:
            document.getElementById("p3Answer").innerHTML = ranNum + ": this is the lowest number you can get";
            break;
        case 2:
            document.getElementById("p3Answer").innerHTML = ranNum + ": this is the lowest even number you can get";
            break;
        case 3:
            document.getElementById("p3Answer").innerHTML = ranNum + ": right smack in the middle";
            break;
        case 4:
            document.getElementById("p3Answer").innerHTML = ranNum + ": good number!";
            break;
        case 5:
            document.getElementById("p3Answer").innerHTML = ranNum + ": way to roll!";
            break;
        default:
            alert("something went wrong!");
            break;
    }
}


// problem 4
function getQuestion4() {
    var love = prompt("i am loving javascript! are you? YES or NO");
    if (love == "YES") {
        document.getElementById("p4Answer").innerHTML = "awesome!!";
    } else if (love == "NO") {
        document.getElementById("p4Answer").innerHTML = "i'm sorry, i hope it gets better for you";
    } else {
        document.getElementById("p4Answer").innerHTML = "something went wrong! please try again and enter your answer in all CAPS!";
    }
}