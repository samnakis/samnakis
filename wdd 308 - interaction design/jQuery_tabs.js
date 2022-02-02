$(document).ready(function() {
    // listen for clicked link
    $('nav li a').on("click", function() {
        // remove active status from all links
        // happens so quickly so you won't see
        $('nav li').removeClass('activeLink');

        // add active status to clicked link
        $(this).parent().addClass('activeLink');


        // get current tab's href value
        var currentTab = $(this).attr("href");
        console.log(currentTab);

        // find the id value of each section
        $('section').each(function() {
            var currentSection = $(this).attr("id");
            // compare id value to href value
            if (currentTab != currentSection) {
                $(this).removeClass('active');
            } else {
                $(this).addClass('active');
            }
        })
    })
})