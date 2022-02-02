$(document).ready(function() {
    $('.acBtn').on("click", function() {
        $(this).next().slideToggle(1500);
    })
});