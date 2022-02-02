// add item
var addBtn = document.getElementsByTagName('input')[0];
var webList = document.getElementById('webList');

function addItem() {
    var newItem = prompt("add new item:");
    var newLiItem = document.createElement("li");
    var newLiText = document.createTextNode(newItem);
    newLiItem.appendChild(newLiText);
    webList.appendChild(newLiItem);
}

addBtn.addEventListener('click', addItem, false);


// delete item
// function will get value of e or the target of the event
function getTarget(e) {
    if (!e) {
        e = window.event;
    }

    return e.getTarget || e.srcElement;
}

function deleteItem(e) {
    var target = getTarget(e);
    var tParent = target.parentNode;
    tParent.removeChild(target);
}

webList.addEventListener('click', deleteItem, false);