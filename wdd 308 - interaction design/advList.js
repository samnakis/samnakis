// code from html
function getTarget(e) {
    if (!e) {
        e = window.event;
    }
    return e.target || e.srcElement;
}

var viewInfo = document.querySelector('main');
viewInfo.addEventListener('click', displayInfo, false);

function displayInfo(e) {
    var target = getTarget(e);
    if (target.tagName == "H2") {
        var tParent = target.parentNode;
        var parentDiv = tParent.children;
        console.log(parentDiv[1]);
        if (parentDiv[1].style.display == "none") {
            parentDiv[1].style.display = "block";
        } else {
            parentDiv[1].style.display = "none";
        }
    }
}

var myList = document.querySelector("#codeBox ul");
var addBtn = document.getElementsByTagName('input')[0];

addBtn.addEventListener('click', addItem, false);

function addItem() {
    var newItem = prompt("New Item:");
    var newLI = document.createElement('li');
    var newLIText = document.createTextNode(newItem);
    newLI.appendChild(newLIText);

    // MY CODE
    // add icons to new items
    var trashIcon = document.createElement("img");
    trashIcon.setAttribute("src", "https://s3-us-west-2.amazonaws.com/s.cdpn.io/27019/trashcanIcon.png");
    trashIcon.setAttribute("class", "listIcon");
    newLI.appendChild(trashIcon);
    // end my code

    myList.appendChild(newLI);
}



// MY CODE

// add icon to existing items

// i was having trouble getting the the query selector to get the list, so i did it this way instead
var list = document.getElementById("codeBox").getElementsByTagName("li");

var listLength = list.length;

for (var i = 0; i < list.length; i++) {
    var trashIcon = document.createElement("img");
    trashIcon.setAttribute("src", "https://s3-us-west-2.amazonaws.com/s.cdpn.io/27019/trashcanIcon.png");
    trashIcon.setAttribute("class", "listIcon");
    list[i].appendChild(trashIcon);
}


// trash or grey out items
function changeProp(e) {
    var target = getTarget(e);
    // console.log("target: " + target.tagName);
    var tParent = target.parentNode;
    // console.log("parent: " + tParent.tagName);

    if (tParent.tagName == "LI") {
        tParent.remove();
        // console.log("clicked on trash can");
    } else if (tParent.tagName == "UL") {
        // if the item already has the class selected (the item is already greyed out), ungrey it
        if (target.classList.contains("selected")) {
            target.setAttribute("class", "");
        }
        // if the item does not have the class selected, grey it out
        else {
            // console.log("clicked on li");
            target.setAttribute("class", "selected");
        }
    } else {
        console.log("error!");
    }
}


var ul = document.getElementsByTagName('ul')[0];
ul.addEventListener('click', changeProp, false);