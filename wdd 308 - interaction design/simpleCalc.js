// dating
var ticketNum = 2;
var ticketCost = 14;
var totalCost = ticketNum * ticketCost;

document.getElementById("ticketNum").innerHTML = "tickets: " + ticketNum;
document.getElementById("ticketCost").innerHTML = "ticket cost: $" + ticketCost;
document.getElementById("ttCost").innerHTML = "total cost: $" + totalCost;


// pizza
var numPizzas = 4;
var studentEat = 2.5;
var slicesPer = 8;

var slicesTotal = numPizzas * slicesPer;

var studentsFed = Math.floor(slicesTotal / studentEat);

var remainingPizza = slicesTotal % studentEat;

document.getElementById("profPizza").innerHTML = "she could feed " + studentsFed + " students :)" + "</br>there would be " + remainingPizza + " slices leftover!";


// monty
var adultPrice = 12;
var childPrice = 6;
var drinkPrice = 1.5;

var adultTickets = 2;
var childTickets = 1;
var drinksOrdered = 3;

var montyTotal = (adultPrice * adultTickets) + (childPrice * childTickets) + (drinkPrice * drinksOrdered);

document.getElementById("Monty").innerHTML = "$" + montyTotal;