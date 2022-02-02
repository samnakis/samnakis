// creating objects
var person = {
    firstName: "kylie",
    lastName: "pfeifer",
    age: 21,
    height: 60,
    hairColor: "brown",
    eyeColor: "blue",
    fullName: function() {
        return this.firstName + " " + this.lastName;
    }
}

document.getElementById("fullName").innerHTML = person.fullName();

person.age = 22;
document.getElementById("newFProp").innerHTML = person.age;


// creating multiple objects
function vehicle(make, model, version, automatic, mpg, cost, discount) {
    this.make = make;
    this.model = model;
    this.manual = version;
    this.automatic = automatic;
    this.mpg = mpg;
    this.cost = cost;
    this.discount = discount;
}

var car1 = new vehicle


// creating multiple objects 2
function wddclass(cNum, cName, seats, enrolled, seatsLeft) {
    this.cNum = cNum;
    this.cName = cName;
    this.seats = seats;
    this.enrolled = enrolled;
    this.seatsLeft = function() {
        return this.seats - this.enrolled;
    }
}

var cme208 = new wddclass("cme208", "multimedia graphics", 18, 18);
var cme219 = new wddclass("cme219", "designing for the web", 18, 17);
var cme306 = new wddclass("cme306", "responsive design", 18, 18);
var cme308 = new wddclass("cme308", "interaction design", 18, 15);

document.getElementById('courseNames').innerHTML = "class names: " + cme208.cName + ", " + cme219['cName'] + ", " + cme306.cName + ", " + cme308['cName'];

document.getElementById('308seatsOpen').innerHTML = "seats left: " + cme308.seatsLeft();