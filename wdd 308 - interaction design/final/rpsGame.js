var playBtn = document.getElementsByTagName('input')[0];
playBtn.addEventListener('click', playGame, false);

var gamesPlayed = 0;
var p1Wins = 0;
var p2Wins = 0;
var ties = 0;

function playGame() {
    gamesPlayed++;

    // player 1
    var rpsImagep1;

    // gets through 1-3 using floor and +1
    var rps = Math.floor(Math.random() * 3) + 1;

    switch (rps) {
        case 1:
            rpsImagep1 = "rock.png";
            break;
        case 2:
            rpsImagep1 = "paper.png";
            break;
        case 3:
            rpsImagep1 = "scissors.png";
            break;
        default:
            alert("something went wrong!");
            break;
    }

    document.getElementById("p1").innerHTML = '<img src="rpsPics/' + rpsImagep1 + '"/>'


    // player 2
    var rpsImagep2;

    // gets through 1-3 using floor and +1
    var rps = Math.floor(Math.random() * 3) + 1;

    switch (rps) {
        case 1:
            rpsImagep2 = "rock.png";
            break;
        case 2:
            rpsImagep2 = "paper.png";
            break;
        case 3:
            rpsImagep2 = "scissors.png";
            break;
        default:
            alert("something went wrong!");
            break;
    }

    document.getElementById("p2").innerHTML = '<img src="rpsPics/' + rpsImagep2 + '"/>'


    // printing result
    if (rpsImagep1 == rpsImagep2) {
        document.getElementById("result").innerHTML = "it's a tie!";
        ties++;
    } else if (rpsImagep1 == "rock.png" && rpsImagep2 == "scissors.png") {
        document.getElementById("result").innerHTML = "player 1 wins!";
        p1Wins++;
    } else if (rpsImagep1 == "scissors.png" && rpsImagep2 == "paper.png") {
        document.getElementById("result").innerHTML = "player 1 wins!";
        p1Wins++;
    } else if (rpsImagep1 == "paper.png" && rpsImagep2 == "rock.png") {
        document.getElementById("result").innerHTML = "player 1 wins!";
        p1Wins++;
    } else {
        document.getElementById("result").innerHTML = "player 2 wins!";
        p2Wins++;
    }

    // overall stats
    document.getElementById("games").innerHTML = gamesPlayed;
    document.getElementById("p1Win").innerHTML = p1Wins;
    document.getElementById("p2Win").innerHTML = p2Wins;
    document.getElementById("ties").innerHTML = ties;
}