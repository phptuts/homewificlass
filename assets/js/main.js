$(document).on("ready", function() {
    
    $.getJSON("/lightstate", function(data){
        if(data === true) {
            $("#light-switch").prop("checked", true);
        }
        else {
            $("#light-switch").prop("checked", false);
        }
    })
    
    $("#light-switch").on("change", function() {
        var isON = $(this).is(":checked");   
        $.getJSON("/lightswitch/" + isON, function() {});
    });
    
});