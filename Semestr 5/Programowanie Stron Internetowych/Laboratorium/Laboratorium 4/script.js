  
// Generacja liczby między 1 a 10
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