
var input = document.getElementById('myInput');
var message = document.getElementById('message');

input.addEventListener('keydown', function (e) {

    var isNumber = e.key >= '0' && e.key <= '9';
    var isBackspace = e.key === 'Backspace';
    if (!isNumber && !isBackspace) {

        e.preventDefault();

        message.textContent = 'Numbers only!';
    }

});


input.addEventListener('input', function () {

    var value = input.value;

    if (value === '') {
        message.textContent = '';
    } else {
        message.textContent = 'Valid number: ' + value;
    }

});