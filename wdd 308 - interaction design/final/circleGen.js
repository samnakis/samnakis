// getting the number the user picks
var pickBtn = document.getElementsByTagName('input')[0];
pickBtn.addEventListener('click', pickNum, false);

var num = 0;

// function will run once and continue to run until user inputs valid number in the range
function pickNum() {
    do {
        num = prompt("please enter a number 1-100!");
    } while (num < 1 || num > 100);
    document.getElementById("numSelection").innerHTML = num;
}

var genBtn = document.getElementsByTagName('input')[1];
genBtn.addEventListener('click', generate, false);


// generate the circles within the range of the window
function generate() {
    for (var i = 1; i <= num; i++) {
        var circle = document.createElement("div");
        circle.classList.add("circle");

        // position
        var w = window.innerWidth;
        var h = window.innerHeight;

        // -50 keeps them from going off the edge
        var x = Math.floor(Math.random() * (w - 50));
        var y = Math.floor(Math.random() * (h - 50));

        // setting their position
        circle.style.position = "absolute";
        circle.style.top = y + "px";
        circle.style.left = x + "px";

        // appending to the field
        var field = document.getElementById('circleField');
        field.appendChild(circle);
    }
}


// change color
function getTarget(e) {
    if (!e) {
        e = window.event;
    }
    return e.target || e.srcElement;
}

function changeColor(e) {
    var target = getTarget(e);

    if (target.tagName != "div") {
        if (target.className == "circle") {
            target.setAttribute("class", "circleChanged");
        } else if (target.classList == "circleChanged") {
            target.setAttribute("class", "circle");
        } else {
            console.log("error! (within div)");
        }
    } else {
        console.log("didn't click on div");
    }
}

var clickCircle = document.getElementById('circleField');
clickCircle.addEventListener('click', changeColor, false);