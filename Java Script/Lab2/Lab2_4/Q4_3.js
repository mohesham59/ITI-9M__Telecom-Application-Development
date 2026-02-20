
    function addNumbers(...args) 
    {
        for (var i = 0; i < args.length; i++) 
        {
            if (typeof args[i] !== "number") 
            {
                throw new Error("All parameters must be numbers!");
            }
        }
        
        let sum = 0;
        for (let i = 0; i < args.length; i++) {
            sum += args[i];
        }

        return sum;
    }



    console.log(addNumbers(1, 2, 3, 4));
    console.log(addNumbers(5, 10));  