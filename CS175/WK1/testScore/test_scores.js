var names = [];
var scores = [];

var $ = function (id) {
	return document.getElementById(id);
}

function validateInputs()
{
	let userName = $('name').value;
	let userScore = parseFloat($('score').value);

	if(userName == '' || !(userScore >= 0 && userScore <= 100))
	{
		alert('Please enter a valid name and score.');
		resetFields();
		
	} else
	{
		addToResults(userName,userScore);
		resetFields();
	}

}

function addToResults(m,k)
{
	names.push(m);
	scores.push(k);
	console.log('Names array: ',names,'\n','Scores array: ',scores);	
}

function calcResults()
{
	let findHighIndex = 0;
	let findAvg = 0;
	let findLowIndex = 0;
	let buildStr= 'Names and Scores: \n';
	// since conditions must be met on input, both arrays will remain parallel and of same size
	let SIZE = names.length;
	if(!SIZE)
	{
		console.log('no inputs!');
		alert('Please add a name and score before attempting to display results.')
		return;
	}
	for (i = 0; i < SIZE; i++)
	{
		console.log('in here!');
		if(scores[i] > scores[findHighIndex])
		{
			findHighIndex = i;
		}

		if(scores[i] < scores[findLowIndex])
		{
			findLowIndex = i;
		}
		findAvg += scores[i];
		if(i == (SIZE - 1))
		{
			findAvg = (findAvg * 1.0) / SIZE;
		}
	}
	console.log('Highest score at Index: ',findHighIndex,' is: ',scores[findHighIndex], 'All average scores: ', findAvg.toFixed(2));
	// display data
	for (i = 0; i < SIZE; i++)
	{
		buildStr += names[i] + ': ' + scores[i] + '\n';
	}
	buildStr += '\n' + names[findHighIndex] + ' scored the highest: ' + scores[findHighIndex] + "\n";
	buildStr += '\n' + names[findLowIndex] + ' scored the lowest: ' + scores[findLowIndex] + "\n";
	buildStr += '\nThe average score was: ' + findAvg.toFixed(2);

	$('results').value = buildStr;
	$('name').focus();
}

function resetFields()
{
	// does not clear lists
	$('name').value = '';
	$('score').value = '';
	$('results').value = '';
	$('name').focus();
}

window.onload = function ()
{
	resetFields();
	$('add').onclick = validateInputs;
	$('display').onclick = calcResults;
}


