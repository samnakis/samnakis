var answers = document.getElementById("answers");

var grades = [78, 86, 92, 77];

var myAnswers;

// problems
myAnswers = "<ol>";

myAnswers += "<li>" + grades + "</li>";

myAnswers += "<li>" + grades[1] + "</li>";

grades[1] = 83;
myAnswers += "<li>" + grades + "</li>";

myAnswers += "<li>" + grades.length + "</li>";

grades[0]++;
myAnswers += "<li>" + grades[0] + "</li>";

myAnswers += "<li>" + grades + "</li>";

myAnswers += "<li>" + grades[grades.length - 1] + "</li>";

var totalGrade = grades[0] + grades[1] + grades[2] + grades[3];
var avgGrade = totalGrade / grades.length;
myAnswers += "<li>" + avgGrade + "</li>";

myAnswers += "<li>your average grade is: " + avgGrade + "</li>";

myAnswers += "</ol>";

answers.innerHTML = myAnswers;


//extras
var pets = ["cat", "dog", "bird", "hamster", "lizard", "frog"];

var extraAnswers = document.getElementById("extraAnswers");

var petAnswers;

// add a value to the end of an array
pets.push("turtle");
petAnswers = "<p>" + pets + "</p>";

// delete a value off the end of an array
pets.pop();
petAnswers += "<p>" + pets + "</p>";

// add a value at the front of an array
pets.unshift("fish");
petAnswers += "<p>" + pets + "</p>";

// delete a value at the front of an array
pets.shift();
petAnswers += "<p>" + pets + "</p>";

// change a value in the middle of an array
pets[3] = "snake";
petAnswers += "<p>" + pets + "</p>";

// add a value in the middle of an array
pets.splice(3, 0, "snake");
petAnswers += "<p>" + pets + "</p>";

// delete a value in the middle of an array
pets.splice(3, 2);
petAnswers += "<p>" + pets + "</p>";

extraAnswers.innerHTML = petAnswers;