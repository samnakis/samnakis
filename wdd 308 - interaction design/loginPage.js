var regBtn = document.getElementById('submit');

regBtn.addEventListener("click", regUser, false);

function regUser() {
    var username = document.getElementById('user').value;
    var pass1 = document.getElementById('pass1').value;
    var pass2 = document.getElementById('pass2').value;

    var loginTxt = document.getElementById('added');

    // ^ means nothing can come before
    // /w gives chars digits or underscores
    // 8,10 means you can only have 8-10
    // $ means nothing after
    var passPtrn = /^\w{8,10}$/;

    if (pass1 == pass2) {
        if (passPtrn.test(pass1)) {
            loginTxt.innerHTML = "thank you, " + username + " for registering";

            // array is to text against login info
            var userPass = pass1;
            var userInfo = [username, userPass];
            return userInfo;
        } else {
            loginTxt.innerHTML = "your password must be between 8 and 10 characters";
        }
    } else {
        loginTxt.innerHTML = "your passwords do not match! please try again";
    }
}

// login information
function loginUser() {
    var lUsername = document.getElementById('loginUser').value;
    var lPass = document.getElementById('loginPass').value;

    // run registerUser function to get userInfo
    var userInfo = regUser();

    // test the username
    if (lUsername == userInfo[0] && lPass == userInfo[1]) {
        document.getElementById("loginText").innerHTML = "congratulations, you are now logged in!";
    } else {
        document.getElementById("loginText").innerHTML = "sorry, your information does not match that on file. please try again";
    }
}

var loginBtn = document.getElementById('login');
loginBtn.addEventListener('click', loginUser, false);