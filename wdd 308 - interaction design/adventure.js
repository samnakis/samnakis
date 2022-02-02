function startGame() {
    var name = prompt("welcome to your choose your own adventure game! please start by entering your name: ");

    alert("welcome " + name + "! today we are going on a campus adventure. are you ready? click the button to continue!");

    var tool = prompt("to begin our adventure, you must select a tool. please pick your tool of choice: FLASHLIGHT, SHOVEL, or a LADDER");

    var room = prompt("you walk through fairbanks and hear a loud menacing growl coming from a room downstairs. do you ENTER or LEAVE?");

    function leaveRoom() {
        alert("you choose to leave the room. chicken.");
    }

    function enterRoom() {
        var useTool = prompt("you chose to enter the room and it is dark and empty, but you can still hear the growl. do you want to use your tool? YES or NO");

        if (useTool == "YES") {
            roomTool();
        } else {
            alert("no tool? the monster attacks and you die");
        }
    }

    function roomTool() {
        if (tool == "FLASHLIGHT") {
            alert("you use your flashlight and see it's just the sound of your classmate's stomach. they're hungry.");
        } else if (tool == "SHOVEL") {
            alert("you feel something attack you and you use your shovel to subdue the monster, congratulations!");
        } else {
            alert("the monster approaches and you climb to the top of your ladder in fear. hopefully someone will find you.")
        }
    }



    if (room == "LEAVE") {
        leaveRoom();
    } else {
        enterRoom();
    }
}