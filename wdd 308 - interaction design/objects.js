var hotel = {
    name: "mariott",
    rooms: 100,
    booked: 87,
    pool: true,
    roomType: ["single", "double", "suite"],
    checkAvailability: function() {
        return this.rooms - this.booked;
    }
}

// changes value
hotel.booked = 56;
// checks and doesn't see above in hotel so adds them
hotel.gym = true;
hotel.pets = false;

document.write(hotel.name);
document.write("</br>" + hotel.roomType[1]);

document.write("</br>" + hotel.checkAvailability());

document.write("</br>allow pets: " + hotel.pets);

// create multiple objects from one object
function vehicle(year, make, model, manual, mpg, fuelEff) {
    this.year = year;
    this.make = make;
    this.model = model;
    this.manual = manual;
    this.mpg = mpg;
    this.fuelEff = function() {
        if (this.mpg > 35)
            return true;
        else
            return false;
    }
}

var charger = new vehicle(2021, "dodge", "charger", false, 15);
document.write("</br>is this charger fuel efficient? " + charger.fuelEff());

var armada = new vehicle(2005, "nissan", "armada", false, 20);
document.write("<p>i have a " + armada.year + " " + armada.make + " " + armada.model + "</p>");