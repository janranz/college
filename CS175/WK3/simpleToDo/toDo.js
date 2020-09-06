"use strict";


$(document).ready(function()
{
    function toggleLabCheck()
    {
        let dis = $("#lRoom").prop('disabled');
        console.log(dis);
        // console.log("wow such toggle.");
        if(this.checked)
        {
            // console.log("Visible");
            // $("#labSec").fadeIn();
            toggleDisable("#labSec :input", false);
        } else
        {
            toggleDisable("#labSec :input",true);
            // $("#labSec").fadeOut(); // check that this is not submitting fields
            // $("#labSec :input").each(function(){
            //     $(this).prop('disabled', true);
            // });

        }
    }
    function toggleDisable(d,b)
    {
        $(d).each(function(){
            $(this).prop("disabled", b)
        });
    }
    (function(){toggleDisable("labSec :input",true);});
    $("#labCheck").on("change",toggleLabCheck);
});