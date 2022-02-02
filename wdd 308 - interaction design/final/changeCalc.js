// getting the amount of change the user picks
var changeBtn = document.getElementsByTagName('input')[0];
changeBtn.addEventListener('click', enterChange, false);

var change = 0;

// function will run once and continue to run until user inputs valid number in the range
function enterChange() {
    do {
        change = prompt("please enter how much change you have (up to 99 cents)! you will be asked to re-enter if you enter a value more than 99.");
    } while (change < 1 || change > 99);
    document.getElementById("changeSelection").innerHTML = change;
}


var calcBtn = document.getElementsByTagName('input')[1];
calcBtn.addEventListener('click', calculate, false);

// initializing variables
var changeRemaining = 0;
var numQuarters = 0;
var numDimes = 0;
var numNickels = 0;
var numPennies = 0;

// calculate the change
function calculate() {
    // divide the change by the value of the coin
    numQuarters = change / 25;
    // take the floor to get the rounded down whole number
    numQuarters = Math.floor(numQuarters);
    // set the change equal to change mod the value so you have the correct remaining amount
    change = change % 25;

    // repeat process above for all coins
    numDimes = change / 10;
    numDimes = Math.floor(numDimes);
    change = change % 10;

    numNickels = change / 5;
    numNickels = Math.floor(numNickels);
    change = change % 5;

    numPennies = change / 1;
    numPennies = Math.floor(numPennies);
    change = change % 1;

    // input values calculated above to the print out
    document.getElementById("quarters").innerHTML = numQuarters;
    document.getElementById("dimes").innerHTML = numDimes;
    document.getElementById("nickels").innerHTML = numNickels;
    document.getElementById("pennies").innerHTML = numPennies;
}