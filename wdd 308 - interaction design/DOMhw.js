var itemList = document.getElementsByTagName('li');
// 1
itemList[0].style.color = "crimson";

// 2
itemList[1].style.color = "teal";

// 3
itemList[2].style.background = "pink";

// 4
itemList[4].style.background = "skyBlue";

// 5
itemList[6].style.background = "lightGray";
itemList[6].style.color = "royalBlue";

// 6
var newItem = "sam nakis"
var newLIItem = document.createElement("li");
var newLIText = document.createTextNode(newItem);
newLIItem.appendChild(newLIText);

var list = document.getElementsByTagName('ol');
var myList = list[list.length - 1];
myList.appendChild(newLIItem);

// 7
// this shifts the numbers of the ordered list, but you can still see the item labeled "item 4" is gone!
elem = document.querySelectorAll('li')[3];
elem.remove();