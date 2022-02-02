$(document).ready(function() {
    // add item
    function addItem() {
        var newItem = prompt("new item:");
        if (newItem) {
            var newLI = $('<li></li>').text(newItem);
            newLI.animate({
                width: '200px',
                opacity: '1'
            });
            $("#webList").append(newLI);

            // hover effect - need to copy so new items have hover effect
            $(newLI).hover(function() {
                $(this).css("background-color", "crimson");
            }, function() {
                $(this).css("background-color", "teal");
            });
        }
    }

    $('input').on("click", addItem);


    // hover effect
    $('#webList li').hover(function() {
        $(this).css("background-color", "crimson");
    }, function() {
        $(this).css("background-color", "teal");
    });


    // delete item
    $(document).on("click", "#webList li", function() {
        $(this).animate({
            width: '0px',
            opacity: '0'
        }, "slow", deleteItem);
    });

    function deleteItem() {
        $(this).remove();
    }
});