$(document).ready(function() {
    var modWindow = $('#modal');

    // reveal the modal window
    $('#xBtn').on("click", function(e) {
        e.preventDefault();

        modWindow.fadeIn(500);
    })

    // calculations to center modal window
    var winH = $(window).height();
    var winW = $(window).width();
    var modH = modWindow.height();
    var modW = modWindow.width();

    modWindow.css('top', winH / 2 - modH / 2);
    modWindow.css('left', winW / 2 - modW / 2);


    // ball animation
    $(document).one("keydown", keyDown);

    var going;

    // ball movements
    var change = {
        "ArrowLeft": {
            left: "-=1"
        },
        "ArrowRight": {
            left: "+=1"
        },
        "ArrowUp": {
            top: "-=1"
        },
        "ArrowDown": {
            top: "+=1"
        }
    }

    function keyDown(e) {
        var animation = change[e.key];
        going = setInterval(keepGoing, 1);

        // this function will stop the movement
        $(document).one("keyup", keyUp);

        function keepGoing() {
            $('#myBall').css(animation);
        }
    }

    function keyUp(e) {
        clearInterval(going);

        $(document).one("keydown", keyDown);
    }
})