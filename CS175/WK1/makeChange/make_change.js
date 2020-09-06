var $ = function (id) {
    return document.getElementById(id);
}

var makeChange = function(m)
{
    let remain = m;
    let quarter, nickel, dime, penny;

    quarter = Math.floor(remain / 25);
    remain = Math.floor(remain % 25);
    dime = Math.floor(remain / 10);
    remain = Math.floor(remain % 10);
    nickel = Math.floor(remain / 5);
    remain = Math.floor(remain % 5);
    penny = remain;

    $('quarters').value = quarter;
    $('dimes').value = dime;
    $('nickels').value = nickel;
    $('pennies').value = penny;


}

function checkInput()
{
    let userInput = parseInt($('cents').value);
    console.log('Attempted input is: ', userInput);

    if(isNaN(userInput) || !(userInput >= 0 && userInput <= 99))
    {
        console.log('bad input from user');
        alert('Please enter a whole number between 0 and 99.');
        resetFields();
    } else {makeChange(userInput);}
}

function resetFields()
{
    $('quarters').disabled = true;
    $('dimes').disabled = true;
    $('nickels').disabled = true;
    $('pennies').disabled = true;

    $('cents').value = '';
    $('quarters').value = '';
    $('dimes').value = '';
    $('nickels').value = '';
    $('pennies').value = '';
}

window.onload = function () {
    resetFields();
    $('change').onclick = checkInput;
    $('clearAll').onclick = resetFields;
}