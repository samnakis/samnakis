function yearBorn() {
    // getting first name
    var nameInput = document.getElementById('fullName').value;
    var fullNameSplit = nameInput.split(" ");
    var firstName = fullNameSplit[0];

    document.getElementById('firstName').innerHTML = firstName;

    // getting birth year
    var ageInput;
    ageInput = parseFloat(document.getElementById('age').value);

    var today = new Date();
    var currentYear = today.getFullYear();

    var yearB = currentYear - ageInput;

    document.getElementById('yearBorn').innerHTML = yearB;
}