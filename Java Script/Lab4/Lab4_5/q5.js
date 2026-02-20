    document.addEventListener('keydown', function(e) {
      
       var output = document.getElementById('output');

      output.innerHTML = `<p>Key: ${e.key}</p> <p>ASCII Code: ${e.keyCode}</p>`;

    });