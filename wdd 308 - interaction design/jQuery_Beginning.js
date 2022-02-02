$(document).ready(function() {
    // colors the second element of the first ul red by adding class hot
    $('ul:not("#drinkList") li:nth-child(2)').addClass("hot");

    // form
    submitForm = () => {
        var myName = $('input[name="name"]').val();
        var myComment = $('textarea').val();
        alert("hello " + myName + "! thank you for your following comment: " + myComment);
    }
    $('#formBtn').on("click", submitForm);


    // table button/colors
    $('#tableBtn').click(function() {
        $('#drinkList li').each(function() {
            var attrChange = $(this).attr('class');
            if (attrChange == "hot") {
                $(this).attr('class', 'cold');
            } else {
                $(this).attr('class', 'hot');
            }
        })
    })


    // image button
    $('#imgBtn').click(function() {
        $('img').attr({
            "width": "100px",
            "height": "auto",
            "title": "jQuery logo"
        })
    })

});