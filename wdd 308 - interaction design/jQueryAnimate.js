$(document).ready(function() {
    // 1.
    var name;
    name = prompt("what is your name?");

    // 2.
    if (name) {
        var newLI = $('<li></li>').text(name);
    }
    $('ul').append(newLI);

    // 3.
    $('div').append(name);

    // 4.
    $('input').on("click", function() {
        $('div').animate({
            left: '200px',
            width: '300px',
            fontSize: '24px'
        }, 1000);
        $('div').animate({
            top: '200px',
            opacity: '0.5',
            fontSize: '34px'
        }, 1000);
        $('div').animate({
            left: '-=200px',
            opacity: '0.2',
            fontSize: '24px'
        }, 1000);
        $('div').animate({
            top: '-=200px',
            width: '200px',
            opacity: '1.0',
            fontSize: '14px'
        }, 1000);
    })
});