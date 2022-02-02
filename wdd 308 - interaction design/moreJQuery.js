$(document).ready(function() {
    // makes sure that the html file is loaded in before running javascript/jquery

    // prints first li element to console
    var navItem = $('li').html();
    console.log(navItem);

    // changes every li element to say "the beatles"
    // $('li').html("the beatles");

    // prints first ul content to log (without saving to variable first like above)
    console.log($('ul').html());

    // prints ONLY the text of the ul, not the tags like above. also prints all ul text instead of just from the first
    console.log($('ul').text());

    // adds "web content" h2 before the first ul only
    $('ul:not("#myList")').before("<h2>web content</h2>");

    // adds "happy halloween!" h2 after the last ul only
    $('#myList').after("<h2>happy halloween!</h2>");

    // adds "is awesome!" after jquery text in the last li element of the first ul
    $('ul:not("#myList") li:last-child').append(" is awesome!");

    // adds "my favorite is" before kitkat
    $('#myList li:nth-child(2)').prepend("my favorite is ");

    // adds a new li element in myList before the 3rd element
    $('#myList li:nth-child(3)').before("<li>jolly ranchers</li>");

    console.log($('h1').html());

    // keeps h1 tags around it so not actually changing to h4
    // $('h1').html("<h4>i love jquery!</h4>");

    // this actually replaces
    $('h1').replaceWith("<h4>i love jquery!</h4>");

    $('h4+h2').remove();


    // missing from lecture


    // add/delete list functions
    function addItem() {
        var newItem = prompt("new item: ");
        if (newItem) {
            var newLI = $('<li></li>').text(newItem);
        }
        $('ul:not("myList")').append(newLI);
    }

    $('#add').on("click", addItem)


    $(document).on("click", "ul:not(#myList) li", function() {
        $(this).remove();
    })
});