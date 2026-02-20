var users = [];

function validateName() {
    var name = document.getElementById('name').value;
    var nameInput = document.getElementById('name');
    var nameError = document.getElementById('nameError');

    if (name.length > 0) {
        nameInput.className = 'valid';
        nameError.style.display = 'none';
        return true;
    } else {
        nameInput.className = 'invalid';
        nameError.style.display = 'block';
        return false;
    }
}

function validateAge() {
    var age = document.getElementById('age').value;
    var ageInput = document.getElementById('age');
    var ageError = document.getElementById('ageError');

    var ageNum = Number(age);
    if (age.length > 0 && ageNum >= 1 && ageNum <= 120) {
        ageInput.className = 'valid';
        ageError.style.display = 'none';
        return true;
    } else {
        ageInput.className = 'invalid';
        ageError.style.display = 'block';
        return false;
    }
}

function validateEmail() {
    var email = document.getElementById('email').value;
    var emailInput = document.getElementById('email');
    var emailError = document.getElementById('emailError');

    var hasAt = email.indexOf('@') > 0;
    var hasDot = email.indexOf('.') > email.indexOf('@');

    if (hasAt && hasDot && email.length > 5) {
        emailInput.className = 'valid';
        emailError.style.display = 'none';
        return true;
    } else {
        emailInput.className = 'invalid';
        emailError.style.display = 'block';
        return false;
    }
}

function addUser() {
    var nameValid = validateName();
    var ageValid = validateAge();
    var emailValid = validateEmail();

    if (nameValid && ageValid && emailValid) {
        var name = document.getElementById('name').value;
        var age = document.getElementById('age').value;
        var email = document.getElementById('email').value;

        users.push({name: name, age: age, email: email});
        displayTable();
        resetForm();
    }
}

function displayTable() {
    var table = document.getElementById('userTable');
    var tbody = document.getElementById('tableBody');

    tbody.innerHTML = '';

    for (var i = 0; i < users.length; i++) {
        var row = tbody.insertRow();
        var cell1 = row.insertCell(0);
        var cell2 = row.insertCell(1);
        var cell3 = row.insertCell(2);

        cell1.innerHTML = users[i].name;
        cell2.innerHTML = users[i].age;
        cell3.innerHTML = users[i].email;
    }

    if (users.length > 0) {
        table.style.display = 'table';
    }
}

function resetForm() {
    document.getElementById('name').value = '';
    document.getElementById('age').value = '';
    document.getElementById('email').value = '';

    document.getElementById('name').className = '';
    document.getElementById('age').className = '';
    document.getElementById('email').className = '';

    document.getElementById('nameError').style.display = 'none';
    document.getElementById('ageError').style.display = 'none';
    document.getElementById('emailError').style.display = 'none';
}

document.getElementById('name').addEventListener('keyup', validateName);
document.getElementById('age').addEventListener('keyup', validateAge);
document.getElementById('email').addEventListener('keyup', validateEmail);
document.getElementById('addBtn').addEventListener('click', addUser);
document.getElementById('resetBtn').addEventListener('click', resetForm);