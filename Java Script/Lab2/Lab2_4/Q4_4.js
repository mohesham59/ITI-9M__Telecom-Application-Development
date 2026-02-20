function getDayName(dateString) {
    const days = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
    const date = new Date(dateString);
    
    if (isNaN(date)) throw new Error("Invalid date format!");
    return days[date.getDay()];
}

console.log(getDayName("2026-02-16")); 
console.log(getDayName("2026-02-14")); 
