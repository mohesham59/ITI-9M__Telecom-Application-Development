let name;
            const nameRegex = /^[A-Za-z\s]+$/;

            do {
                name = prompt("Enter your name:");
            } while (!name || !nameRegex.test(name.trim()));


            let phoneNumber;
            const phoneRegex = /^\d{8}$/;

            do {
                phoneNumber = prompt("Enter your phone number:");
            } while (!phoneNumber || !phoneRegex.test(phoneNumber.trim()));


            let mobile;
            const mobileRegex = /^(010|011|012|015)\d{8}$/;

            do {
                mobile = prompt("Enter mobile:");
            } while (!mobile || !mobileRegex.test(mobile.trim()));
            

            let email;
            const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.com$/;

            do {
                email = prompt("Enter your email:");
            } while (!email || !emailRegex.test(email.trim()));


            document.write("<h1>Name: " + name + "</h1>");
            document.write("<h1>Phone Number: " + phoneNumber + "</h1>");
            document.write("<h1>Mobile Number: " + mobileNumber + "</h1>");
            document.write("<h1>Email: " + email + "</h1>");