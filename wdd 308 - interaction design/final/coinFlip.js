var flipBtn = document.getElementsByTagName('input')[0];
flipBtn.addEventListener('click', flip, false);

// result counting variables
var numFlips = 0;
var numHeads = 0;
var numTails = 0;
var resultTxt;

function flip() {
    var coinImg;

    numFlips++;

    // gets through 1-2 using floor and +1
    var flip = Math.floor(Math.random() * 2) + 1;

    // different flip cases
    switch (flip) {
        case 1:
            coinImg = "head.png";
            numHeads++;
            resultTxt = "heads";
            break;
        case 2:
            coinImg = "tail.png";
            numTails++;
            resultTxt = "tails";
            break;
        default:
            alert("something went wrong!");
            break;
    }

    // setting correct image
    document.getElementById("coin").innerHTML = '<img src="coinPics/' + coinImg + '"/>'


    // result table
    var myTable = document.querySelector("table");

    var newRow = document.createElement('tr');
    myTable.appendChild(newRow);

    var newFlipData = document.createElement('td');
    var newFlipText = document.createTextNode(numFlips);
    newFlipData.append(newFlipText);

    newRow.appendChild(newFlipData);


    var newResultData = document.createElement('td');
    var newResultText = document.createTextNode(resultTxt);
    newResultData.append(newResultText);

    newRow.appendChild(newResultData);


    // ratio
    var ratio = numHeads / numTails;
    if (numFlips == 1) {
        document.getElementById('ratio').innerHTML = "n/a, only one flip";
    } else {
        document.getElementById("ratio").innerHTML = ratio;
    }
}