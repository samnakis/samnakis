function startGame() {
    // start of the game
    var name = prompt("hello there! welcome to the haunted house! be prepared to start your journey! before we begin, what's your name?");

    alert("thanks " + name + "! now you can start your journey! as you play, you will type your response in ALL CAPS exactly as it appears when presented the option. now go ahead and press the button to begin!")

    // decision 1
    var enter = prompt("you walk up to an old, creepy, dark house. do you want to enter through the FRONT or walk around to the BACK of the house?");

    var nextRoomFront;

    function enterFront() {
        // choice 1, decision 2
        nextRoomFront = prompt("you entered through the front door and are presented with a grand staircase right in front of you. do you want to take the STAIRS up or STAY on the main floor and keep exploring?");
    }

    var nextRoomBack;

    function enterBack() {
        // choice 2, decision 3
        nextRoomBack = prompt("you walk around to the back of the house. do you want to enter through the back DOOR or continue to explore the large YARD?");
    }

    var nextRoomTop;

    function stairs() {
        // choice 1, decision 4
        nextRoomTop = prompt("you arrive at the top staircase and look around. do you want to go LEFT towards the outdoor balcony or RIGHT towards what you believe are the bedrooms?");
    }

    var nextRoomMain;

    function mainFloor() {
        // choice 2, decision 5
        nextRoomMain = prompt("you wander into the next room off of the foyer which is dark, but you believe it to be a main living room. do you want to light a FIRE in the fireplace or search for a WEAPON?");
    }

    var backHouse;

    function backDoor() {
        // choice 1, decision 6
        backHouse = prompt("you enter the small back door into a kitchen and it smells like something is cooking. do you want to grab a KNIFE or attempt to find the LIGHT switch?");
    }

    var backYard;

    function yard() {
        // choice 2, decision 7
        backYard = prompt("you wander around the large backyard for a bit. do you want to head towards the PUMPKIN patch or RUN back to the front and attempt to leave?");
    }

    function playAgain() {
        var play = prompt("thanks for completing a story " + name + "! do you want to try again? YES or NO.");
        if (play == "YES") {
            startGame();
        } else {
            alert("alright, maybe another time!");
        }
    }


    if (enter == "FRONT") {
        enterFront();
        if (nextRoomFront == "STAIRS") {
            stairs();
            if (nextRoomTop == "LEFT") {
                // choice 1, decision 8
                alert("you chose to step out on to the balcony. you feel at peace until you hear the sound of cracking beneath you. turns out the balcony was unstable and you fall to the back yard. you aren't dead, but you will have to wait for help as both of your legs are now broken. guess you'll have to see if anyone finds you in the morning...");
                playAgain();
            } else if (nextRoomTop == "RIGHT") {
                // choice 2, decision 9
                alert("you chose to head toward what you think are the bedrooms. you're heading down a long corridor full of paintings. it's dead quiet, but you feel like someone is watching you. wait, did that painting's eyes just move?! you run out of the haunted mansion screaming for help, but nobody is around.");
                playAgain();
            } else {
                alert("there was an error. please try again!");
            }
        } else if (nextRoomFront == "STAY") {
            mainFloor();
            if (nextRoomMain == "FIRE") {
                // choice 1, decision 10
                alert("you chose to try and light a fire in the fireplace. after successfully doing this using the convenient fire starting tools left next to the fireplace, the room lights up. you realize this is actually your grandma's mansion and that's why you came here in the first place! she's just really bad at cleaning i guess... you go and find the guest room and sleep peacefully!");
                playAgain();
            } else if (nextRoomMain == "WEAPON") {
                // choice 2, decision 11
                alert("you fumble around the room looking for anything that could be used as a weapon. unfortunately, you knock a glass vase over in the process and hear loud footsteps echoing through the mansion, coming your way. you angered the owner, and the next thing you know, you go unconscious. oops, you shouldn't have done that...");
                playAgain();
            } else {
                alert("there was an error. please try again!");
            }
        } else {
            alert("there was an error. please try again!");
        }
    } else if (enter == "BACK") {
        enterBack();
        if (nextRoomBack == "DOOR") {
            backDoor();
            if (backHouse == "KNIFE") {
                // choice 1, decision 12
                alert("you chose to look for a knife in the kitchen to defend yourself. as you're frantically searching, you hear someone else. looks like someone else got to the knives first. uh oh...");
                playAgain();
            } else if (backHouse == "LIGHT") {
                // choice 2, decision 13
                alert("you chose to look for a light switch in the kitchen. you found one, but unfortunately the power doesn't seem to be working. however, you do find a lantern with a candle and a match on the table! you light it, and go to check out the oven. when you open it, you realize someone is baking cookies, yum! this leads you to remember that this is actually your grandma's house, and you've been worried for no reason! silly you, now go enjoy some fresh baked cookies!");
                playAgain();
            } else {
                alert("there was an error. please try again!");
            }
        } else if (nextRoomBack == "YARD") {
            yard();
            if (backYard == "PUMPKIN") {
                // choice 1, decision 14
                alert("you chose to head towards the pumpkin patch. when you approach, you realize it's all of your friends sitting around a fire and carving pumpkins! you forgot this was their family's house, and they're all outside because the power is out inside. you were worried for nothing! you grab a pumpkin and join them!");
                playAgain();
            } else if (backYard == "RUN") {
                // choice 2, decision 15
                alert("you start to run away and can see the main street, but suddenly find yourself on the ground. you tripped over a huge tree branch, i mean, did you really not see that?! you're trying to stay conscious, but you hit your head pretty hard and feel yourself falling asleep. hopefully someone finds you soon...");
                playAgain();
            } else {
                alert("there was an error. please try again!");
            }
        } else {
            alert("there was an error. please try again!");
        }
    } else {
        alert("there was an error. please try again!");
    }
}