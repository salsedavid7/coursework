function clearScreen() {
    document.getElementById("result").value = "";
   }
   
function display(value) {
    document.getElementById("result").value += value;
    for(var i = 0; i < 100; i++){ 
        if(document.getElementById("result").value[i] == "."){
            document.getElementById("dot").disabled= true
        }
        if(document.getElementById("result").value[i] == "+" || document.getElementById("result").value[i] == "-" || document.getElementById("result").value[i] == "*" || document.getElementById("result").value[i] == "/"){
            document.getElementById("dot").disabled= false
        }
    }
}

function calculate() {
    var eq = document.getElementById("result").value;
    var ans = eval(eq);
    document.getElementById("result").value = ans; 
   
   }