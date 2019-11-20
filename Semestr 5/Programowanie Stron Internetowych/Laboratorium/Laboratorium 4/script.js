// Generacja liczby między 1 a 10 --- Zad1
var y = Math.floor(Math.random() * 10 + 1); 
                
document.getElementById("submitguess").onclick = function(){ 
       
var x = document.getElementById("guessField").value; 

if(x == y) 
{     
   alert("Zgadłeś, to jest liczba " + document.getElementById("guessField").value +" :D"); 
} 
else if(x > y)   
{ 
    alert("Spróbuj liczbę mniejszą ;)"); 
} 
else             
{ 
    alert("Spróbuj liczbę większą ;)") 
} 
}


// Operacja mnożenia i dzielenia --- Zad2

function mnoz()
{
    num1 = document.getElementById("1_liczba").value;
    num2 = document.getElementById("2_liczba").value;
    document.getElementById("wynik").innerHTML = num1 * num2;
}

function dziel()
{
    num1 = document.getElementById("1_liczba").value;
    num2 = document.getElementById("2_liczba").value;
    if(num2 == 0)
    { 
        document.getElementById("wynik").innerHTML = "Nie dzielimy przez 0"; 
    }
    else
    {
        document.getElementById("wynik").innerHTML = num1 / num2;
    }
}

function konwersjaCnaF()
{
    cels = document.getElementById("celsjusz").value;

    document.getElementById("wynik_konwersji").innerHTML = (cels * (9/5)) + 32;
}

function konwersjaFnaC()
{
    
}
