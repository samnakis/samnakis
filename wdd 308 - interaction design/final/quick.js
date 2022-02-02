// setting variables
var timePerGame = 60;
var pointsPerClick = 10;
var highScores = [0, 0, 0, 0, 0];

var interval;
var timer;
var timeLeft;
var targetTimer;
var playerScore;

var field = document.getElementById('targetField');
field.addEventListener('click', hitTarget);

// adding event listener to start button
var startBtn = document.getElementsByTagName('input')[0];
startBtn.addEventListener('click', playGame, false);

// function that runs the game
function playGame() {
    // hiding the button once clicked
    startBtn.style.display = "none";
    playerScore = 0;
    interval = 5000;

    runTimer();
    showScore();
    startTargetTimer();
    showNextTarget();
}

function endGame() {
    startBtn.style.display = "block";

    removeTarget();
    checkScores();
    clearInterval(targetTimer);
    playAgain();
}

function playAgain() {
    var again = prompt("do you want to play again? type Y for yes and N for no.")

    if (again == 'Y' || again == 'y') {
        alert("have fun! once you press okay, the game will start!");
        playGame();
    } else if (again == 'N' || again == 'n') {
        alert("thanks for playing!");
    } else {
        alert("invalid response! try again!");
        playAgain();
    }
}

function runTimer() {
    var count = 60,
        timer = setInterval(function() {
            document.getElementById("timeLeft").innerHTML = count--;
            if (count < 0) {
                clearInterval(timer);
                endGame();
            }
        }, 1000);
}

function showNextTarget() {
    removeTarget();

    var target = document.createElement("div");
    target.classList.add("target");

    // position
    var w = window.innerWidth;
    var h = window.innerHeight;

    // -50 keeps them from going off the edge
    var x = Math.floor(Math.random() * (w - 50));
    var y = Math.floor(Math.random() * (h - 50));

    // setting their position
    target.style.position = "absolute";
    target.style.top = y + "px";
    target.style.left = x + "px";

    // appending to the field
    field.appendChild(target);
}

// clearing any remaining target from the field
function removeTarget() {
    if (field.hasChildNodes) {
        field.innerHTML = "";
    }
}

function hitTarget(e) {
    playerScore += pointsPerClick;
    showScore();
    shortenInterval();
    removeTarget();
    showNextTarget();
}

function showScore() {
    document.getElementById("score").innerHTML = playerScore;
}

function startTargetTimer() {
    targetTimer = setInterval(showNextTarget, interval);
}

function shortenInterval() {
    clearInterval(targetTimer);
    interval = interval * 0.93;
    startTargetTimer();
}

function checkScores() {
    alert("game over! your score is: " + playerScore);

    if (playerScore >= highScores[4]) {
        alert("congratulations! you have the new highest score!");

        // resetting scores
        highScores[0] = highScores[1];
        highScores[1] = highScores[2];
        highScores[2] = highScores[3];
        highScores[3] = highScores[4];
        highScores[4] = playerScore;

        document.getElementById("hs1").innerHTML = highScores[4];
        document.getElementById("hs2").innerHTML = highScores[3];
        document.getElementById("hs3").innerHTML = highScores[2];
        document.getElementById("hs4").innerHTML = highScores[1];
        document.getElementById("hs5").innerHTML = highScores[0];

    } else if (playerScore < highScores[4] && playerScore >= highScores[3]) {
        alert("congratulations! you have a new high score!");

        // resetting scores
        highScores[0] = highScores[1];
        highScores[1] = highScores[2];
        highScores[2] = highScores[3];
        highScores[3] = playerScore;

        document.getElementById("hs2").innerHTML = highScores[3];
        document.getElementById("hs3").innerHTML = highScores[2];
        document.getElementById("hs4").innerHTML = highScores[1];
        document.getElementById("hs5").innerHTML = highScores[0];

    } else if (playerScore < highScores[3] && playerScore >= highScores[2]) {
        alert("congratulations! you have a new high score!");

        // resetting scores
        highScores[0] = highScores[1];
        highScores[1] = highScores[2];
        highScores[2] = playerScore;

        document.getElementById("hs3").innerHTML = highScores[2];
        document.getElementById("hs4").innerHTML = highScores[1];
        document.getElementById("hs5").innerHTML = highScores[0];

    } else if (playerScore < highScores[2] && playerScore >= highScores[1]) {
        alert("congratulations! you have a new high score!");

        // resetting scores
        highScores[0] = highScores[1];
        highScores[1] = playerScore;

        document.getElementById("hs4").innerHTML = highScores[1];
        document.getElementById("hs5").innerHTML = highScores[0];

    } else if (playerScore < highScores[1] && playerScore >= highScores[0]) {
        alert("congratulations! you have a new high score!");

        // resetting score
        highScores[0] = playerScore;

        document.getElementById("hs5").innerHTML = highScores[0];
    }
}