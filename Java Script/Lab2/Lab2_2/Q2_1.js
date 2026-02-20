 let radius;
        radius = prompt("Enter the radius of the circle:");
        radius = parseFloat(radius);
        if (isNaN(radius) || radius <= 0) {
            alert("Please enter a valid positive number for the radius.");
        } else {
            const area = Math.PI * Math.pow(radius, 2);
            alert(`The area of the circle with radius ${radius} is: ${area.toFixed(2)}`);
        }
