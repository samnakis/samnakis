// bank account
var bankBal = 45.67;
var toy = 45.99;
var buyToy = bankBal > toy;
console.log(buyToy);

if (buyToy) {
    document.getElementById('bank').innerHTML = "awesome, let's buy it!";
} else {
    document.getElementById('bank').innerHTML = "sorry, no toy today :(";
}


//birthday month
var today = new Date();
var currentMonth = today.getMonth() + 1;

// if (currentMonth == 4) {
//     document.getElementById('birthday').innerHTML = "yay! it's my birthday month!";
// } else {
//     document.getElementById('birthday').innerHTML = "it's not my birthday month :(";
// }

if (currentMonth != 4) {
    document.getElementById('birthday').innerHTML = "it's not my birthday month :(";
}


// right to vote
function checkAge() {
    var yourAge = document.getElementById('age').value;

    if (yourAge >= 18) {
        document.getElementById('voteAge').innerHTML = "you can vote!";
    } else if (yourAge == 17) {
        document.getElementById('voteAge').innerHTML = "you can vote next year!";
    } else {
        document.getElementById('voteAge').innerHTML = "sorry, you cannot vote yet!";
    }
}


// time of day
var dayTime = today.getHours();
var myTime = document.getElementById('myTime');
console.log(dayTime);

if (dayTime < 12) {
    myTime.innerHTML = "it's in the am.";
} else {
    myTime.innerHTML = "it's in the pm.";
}

if (dayTime < 11) {
    myTime.innerHTML += "</br>good morning!";
} else if (dayTime >= 11 && dayTime <= 16) {
    myTime.innerHTML += "</br>good afternoon!";
} else if (dayTime > 16 && dayTime <= 20) {
    myTime.innerHTML += "</br>good evening!";
} else {
    myTime.innerHTML += "</br>good night!";
}


// pass class
var midterm = 78;
var final = 87;
var totalPts = 350;
var classAvg = 85;
var myAvg = (47 + 62 + midterm + final) / totalPts;

var msg = document.getElementById('msg');

msg.innerHTML = "midterm grade: " + midterm;
var mtPass = (midterm / 110) * 100 > 50;
msg.innerHTML += "</br>pass midterm: " + mtPass;

var mtAvg = (midterm / 110) * 100;
var finalAvg = (final / 110) * 100;

if (mtAvg > 50 && finalAvg > 72) {
    msg.innerHTML += "</br>you passed the class!";
} else {
    msg.innerHTML += "</br>you did not pass the class, sorry!";
}

if ((mtAvg > 50 && finalAvg > 72) || myAvg > 80) {
    msg.innerHTML += "</br>congrats, you completed the class!";
} else {
    msg.innerHTML += "</br>you did not complete the class, sorry!";
}


// dice game
function rollDie() {
    var dieImage;

    // gets through 1-6 using floor and +1
    var die = Math.floor(Math.random() * 6) + 1;

    switch (die) {
        case 1:
            dieImage = "die_face_1.png";
            break;
        case 2:
            dieImage = "die_face_2.png";
            break;
        case 3:
            dieImage = "die_face_3.png";
            break;
        case 4:
            dieImage = "die_face_4.png";
            break;
        case 5:
            dieImage = "die_face_5.png";
            break;
        case 6:
            dieImage = "die_face_6.png";
            break;
        default:
            alert("something you went wrong");
            break;
    }

    document.getElementById("dice_1").innerHTML = '<img src="dicePics/' + dieImage + '"/>'

    // dice 2
    var die = Math.floor(Math.random() * 6) + 1;

    switch (die) {
        case 1:
            dieImage = "die_face_1.png";
            break;
        case 2:
            dieImage = "die_face_2.png";
            break;
        case 3:
            dieImage = "die_face_3.png";
            break;
        case 4:
            dieImage = "die_face_4.png";
            break;
        case 5:
            dieImage = "die_face_5.png";
            break;
        case 6:
            dieImage = "die_face_6.png";
            break;
        default:
            alert("something you went wrong");
            break;
    }

    document.getElementById("dice_2").innerHTML = '<img src="dicePics/' + dieImage + '"/>'
}


// seasons of the year
var thisMonth = today.getMonth() + 1;
var season;

switch (thisMonth) {
    case 1:
    case 2:
    case 3:
        season = "winter";
        break;
    case 4:
    case 5:
    case 6:
        season = "spring";
        break;
    case 7:
    case 8:
    case 9:
        season = "summer";
        break;
    case 10:
    case 11:
    case 12:
        season = "fall";
        break;
    default:
        alert("something went wrong!");
        break;
}

document.getElementById("season").innerHTML = "it is " + season;


// day of week
document.getElementById("potd").innerHTML = today + "</br>";
var thisDay = today.getDay();
var dayText;

// can also do with numbers
if (thisDay = "Monday" || "Tuesday") {
    document.getElementById("potd").innerHTML += "it's the beginning of the week";
} else if (thisDay = "Wednesday") {
    document.getElementById("potd").innerHTML += "it's hump day";
} else if (thisDay = "Thursday" || "Friday") {
    document.getElementById("potd").innerHTML += "it's almost the weekend";
} else {
    document.getElementById("potd").innerHTML += "yay for the weekend";
}