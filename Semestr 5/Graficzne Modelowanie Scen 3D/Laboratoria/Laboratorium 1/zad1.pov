#include "colors.inc"
#include "textures.inc"
#include "stones2.inc"
                 


//widok z zewnatrz               1
camera
{  location <0, 5, -20>
   look_at <0,0,0>
} 

//widok z wnêtrza                 2

//camera
//{  location <4,1.5, 0>
//   look_at <3,1.5,-10>
//}      

       
      

light_source
{  <0,20,-10>  
    color White   
}     

light_source
{  <0,2,0>  
    color Yellow   
}   

background
{color Blue}

plane{y, 0 texture{pigment{Jade}}}      



/*union    
{ difference
  {  box{ <-5,0,-5> <5,3.5,5> texture{pigment{brick White, Red brick_size 0.35 mortar 0.05}}} 
     
     box{ <-4.7,0.1,-4.7> <4.7,3.2,4.7> texture{pigment{White}}}   
     box{ <2.3, 0.25, -5.1> <3, 2.3, -4.6> texture{pigment{brick White, Red brick_size 0.35 mortar 0.05}}}     
  }
  box{ <-4.7, 0.1, -4.7> <4.7,0.15, 4.7> texture{pigment{hexagon  White, Orange, Brown scale 0.2 }}} 
}   
  */                                                                        


// Struktura domu

union
{ 
 
    difference  
     {
    box{    <-6, 0, -6>  <6, 5, 6>     texture{pigment{brick White, Bronze brick_size 0.35 mortar 0.03}} }    // Dom, zewn¹trz
    box{    <-5.7,0.1,-5.7> <5.7,4.7,5.7> texture{pigment{White}}  }                                          // Wyciêcie œrodka domu
    box{    <-1, 0.01, -6.1> <1, 2, 6> texture{pigment{brick White, Bronze brick_size 0.35 mortar 0.03}} }    // Otwór na drzwi                                                                                             // Otwór na drzwi
     }   
    
    box{ <-5.7, 0.1, -5.7> <5.7,0.15, 5.7> texture{pigment{hexagon  White, Orange, Brown scale 0.2 }}}        
} 

// Model drzwi wejœciowych

union
{
    box{    <-1.1, 0.01, -6.1> <0, 2, 6> texture{pigment{Tom_Wood }} }
    sphere  

} 