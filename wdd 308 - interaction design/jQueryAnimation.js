// show/hide animation
$('#show').on("click", function() {
    $('#showHide').show(1000);
})

$('#hide').on("click", function() {
    $('#showHide').hide(1000);
})

$('#toggle').on("click", function() {
    $('#showHide').toggle(1000);
})


// sliding effect
$('#sIn').on("click", function() {
    $('#slideP').slideDown(1500);
})

$('#sOut').on("click", function() {
    $('#slideP').slideUp(1500);
})

$('#sToggle').on("click", function() {
    $('#slideP').slideToggle("fast");
})


// fading effects
$('#fIn').on("click", function() {
    $('#fadeP').fadeIn("normal");
})

$('#fOut').on("click", function() {
    $('#fadeP').fadeOut("fast");
})

$('#fToggle').on("click", function() {
    $('#fadeP').fadeTo(1000, 0.3);
})


// circle 1 animation
$('#circle1').on("click", function() {
    $(this).animate({
        width: '25px',
        height: '25px'
    })
})

// circle 2 animation
// multiple animations so things can happen at different times
$('#circle2').on("click", function() {
    $(this).animate({
        left: '100px',
        top: '25px'
    }, 1000);
    $(this).animate({
        height: '100px',
        width: '100px'
    })
    $(this).animate({
        opacity: '0.5'
    })
})

// circle 3 animation
$("#circle3").on("click", function() {
    $(this).animate({
        left: '250px'
    })
    $(this).animate({
        left: '+=50px',
        top: '75px'
    })
    $(this).animate({
        top: '+=10px',
        left: '-=30px'
    })
})