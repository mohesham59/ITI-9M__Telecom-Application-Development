let users = [];

function UsersNum() {
    let count = Number(prompt("Enter the number of persons: "));

    for (let i = 0; i < count; i++) {

        // ===== Name Validation =====
        let name;
        let nameRegex = /^[A-Za-z]{4,9}$/;

        do {
            name = prompt("Enter user (" + (i + 1) + ") name:");
        } while (!nameRegex.test(name));

        // ===== Age Validation =====
        let age;

        do {
            age = Number(prompt("Enter user age:"));
        } while (age <= 10 || age >= 60);

        // Store User
        users.push({ name, age });
    }

    printUsersTable();
}

function printUsersTable() {

    let table = document.getElementById("usersTable");
    table.innerHTML = "";

    for (let user of users) {
        table.innerHTML += `
            <tr>
                <td>${user.name}</td>
                <td>${user.age}</td>
            </tr>
        `;
    }
}

UsersNum();
