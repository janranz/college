"use strict";

$(document).ready(function()
{
    function toggleLabCheck()
    {
        // console.log("wow such toggle.");
        if(this.checked)
        {
            $("#labSec").fadeIn();
            toggleDisable("#labSec :input", false);
        } else
        {
            toggleDisable("#labSec :input",true);
            $("#labSec").fadeOut();
            $("#labSec :input").each(function(){
                $(this).prop('disabled', true);
            });

        }
    }
    function toggleDisable(d,b)
    {
        $(d).each(function(){
            $(this).prop("disabled", b)
        });
    }
    // add-remove functions
    function addStudy(e)
    {
        e.preventDefault()
        var classPack = [];
        var keyID = $("#cID").val();
        console.log("ID and type: ",keyID, typeof(keyID))
        var userInputs = $(".schedForm :input").not('#cID,:input[type=button],:input[type=submit],:input[type=reset]'); // skips userID length:8
        var labBool = userInputs.eq(4)[0].checked;
        console.log("userInputs",userInputs);
        for(let m = 0; m < userInputs.length ;m++)
        {
            var smol = userInputs.eq(m).val()
            if(m == 4 && labBool)
            {
                classPack.push("YES");
                continue;
            }else if(m == 4 && !labBool)
            {
                classPack.push("NO");
                for(let c = 5; c < userInputs.length; c++)
                {
                    classPack.push("-");
                }
                break;
            }
            classPack.push(smol);
        }
        console.log("classPack: ",classPack);
        storeLocal(keyID.toUpperCase(),classPack);
        newUpdateDB();
    }
    function newUpdateDB()
    {
        $("#schedTab").DataTable().clear().draw();
        for(var m = 0; m < localStorage.length; m++)
        {
            var tempKey = localStorage.key(m);
            var tempDict = JSON.parse(localStorage.getItem(tempKey))
            $("#schedTab").DataTable().row.add([tempKey,tempDict[0],tempDict[1],tempDict[2],tempDict[3],tempDict[4],tempDict[5],tempDict[6],tempDict[7],tempDict[8]]).draw();
        }
    }
    function removeStudy()
    {
        var userRemove = $("#remID").val().toUpperCase();
        console.log(userRemove);
        if(!(localStorage.getItem(userRemove) === null))
        {
            localStorage.removeItem(userRemove);
            newUpdateDB();
            $("#delNotif").html("Class successfully removed.");
        } else
        {
            $("#delNotif").html("Invalid Class ID.");
        }
    }
    //localStorage functions
    function storeLocal(k,v)
    {
        localStorage.setItem(k,JSON.stringify(v));
    }
    function clearLocal()
    {
        if(window.confirm("This will clear both local storage and table."))
        {
            console.log("clearing local storage...");
            localStorage.clear();
            $("#schedTab").DataTable().clear().draw();
        } else{console.log("clear aborted by user");}  
    }
    // 'global' ops
    $("#schedTab").DataTable();
    toggleDisable("#labSec :input",true);
    $(".schedForm").on('submit',function(e)
    {
        addStudy(e);
    });
    $(".schedForm")[0].reset();
    $("#remID").val('');
    $("#delNotif").html('');
    newUpdateDB();
    $("#remClassByID").on("click",removeStudy);
    $("#clearStore").on("click",clearLocal);
    $("#labCheck").on("change",toggleLabCheck);
});

/*
Information being stored:
[ 9 COLUMNS ] Consider[][]?
Class ID | Class Title | Start Time | Finish Time | Class Room | Is Lab?
                                    | Lab Start   | Lab Finish | Lab Room


    // function updateDB(k)
    // {
    //     var testPull = JSON.parse(localStorage.getItem(k));
    //     // console.log("Test pull: ", testPull, testPull[2], typeof(testPull[1]));
    //     $("#schedTab").DataTable().row.add([k,testPull[0],testPull[1],testPull[2],testPull[3],testPull[4],testPull[5],testPull[6],testPull[7],testPull[8]]).draw();
    // }
*/