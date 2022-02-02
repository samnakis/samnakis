// html event handler
function oldSchool() {
    document.getElementById("htmlEH").innerHTML = "this is bad practice, don't use this one!";
}

// traditional dom
var tradBtn = document.getElementsByTagName('input')[1];

function tradFunction() {
    document.getElementById("traditional").innerHTML = "you can only attach one function to an event"
}

tradBtn.onclick = tradFunction;

// dom level 2
var dom2Btn = document.getElementsByTagName('input')[2];

function level2Text() {
    document.getElementById("level2").innerHTML = "you can only call more than one function with this one"
}

function alertMe() {
    alert("this is the second function");
}

// dom2Btn.addEventListener("click", level2Text, false);
dom2Btn.addEventListener("click", function() {
    level2Text();
    alertMe();
}, false);


// ui events
var pageText = document.getElementById('pageURL');
var lastUpdate = document.getElementById('myLastUpdate');

function displayInfo() {
    pageText.innerHTML = "URL: " + (window.location);
    lastUpdate.innerHTML = "last update: " + (document.lastModified);
}

window.addEventListener('load', displayInfo, false);


// keyboard events
var inputText = document.getElementsByTagName('input')[3];

var mykeypress = 0;

function countLetters() {
    mykeypress++;
    document.getElementById('pressNumber').innerHTML = "keypress count: " + mykeypress;
}

inputText.addEventListener('keypress', countLetters, false);


// mouse events
var dangerText = document.getElementById('danger');

function changeText() {
    dangerText.innerHTML = "you double clicked on me!";
}

dangerText.addEventListener('dblclick', changeText, false);


// form events
var dropD = document.getElementById('js');
var ddText = document.getElementById('selectText');
var selectedText;

function ddChoice() {
    var userChoice = dropD.options[dropD.selectedIndex].value;

    switch (userChoice) {
        case 'javascript':
            selectedText = "javascript is the base for all of these";
            break;
        case 'jQuery':
            selectedText = "you will learn jquery this semester";
            break;
        case 'Angular':
            selectedText = "you will become familiar with angular in wdd422";
            break;
        case 'React':
            selectedText = "react is very popular";
            break;
        default:
            selectedText = "what did you choose?";
            break;
    }

    ddText.innerHTML = selectedText;
}

dropD.addEventListener("change", ddChoice, false);