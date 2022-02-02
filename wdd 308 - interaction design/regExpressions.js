// string
var strInput = document.getElementById('string');

function chkString() {
    var strValue = strInput.value;
    // looking for word shoe somewhere in the string (not case sensitive)
    var strPat1 = /shoe/i;
    // looking for word web at beginning of string (case sensitive)
    var strPat2 = /^web/;
    // looking for word drink at the end of string (case sensitive)
    var strPat3 = /drink$/;
    // looking for 3 characters a-z
    var strPat4 = /[a-zA-Z]{3}/;

    var result = strPat4.test(strValue);
    document.getElementById('stringAns').innerHTML = result;
}

strInput.addEventListener('blur', chkString, false);


// zip code
var zipInput = document.getElementById('myzip');

function chkZip() {
    var zipValue = zipInput.value;

    var zipPat = /^\d{5}([\- ]?\d{4})?$/;

    var result = zipPat.test(zipValue);
    document.getElementById('zipAns').innerHTML = result;
}

zipInput.addEventListener('blur', chkZip, false);


// credit card
var creditInput = document.getElementById('ccard');

function chkCredit() {
    var creditValue = creditInput.value;

    var creditPat = /^\d{4}[- ]?\d{4}[- ]?\d{4}[- ]?\d{4}$/;

    var result = creditPat.test(creditValue);
    document.getElementById('ccAns').innerHTML = result;
}

creditInput.addEventListener('blur', chkCredit, false);


// phone number
var phoneInput = document.getElementById('phone');

function chkPhone() {
    var phoneValue = phoneInput.value;
    // \d only allows digits, [0-9] does same thing
    // the question marks says the symbol can appear once or not at all
    var phonePat = /^([\(]?)\d{3}([-\). ]?|\) )\d{3}[-. ]?\d{4}$/;

    var result = phonePat.test(phoneValue);
    document.getElementById('phoneAns').innerHTML = result;
}

phoneInput.addEventListener('blur', chkPhone, false);