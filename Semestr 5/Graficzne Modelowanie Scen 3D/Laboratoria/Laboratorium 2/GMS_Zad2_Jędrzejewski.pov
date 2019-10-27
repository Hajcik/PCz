#include "colors.inc"
#include "textures.inc"
#include "stones2.inc"
     
    camera{     location < 0,  8, -30>   look_at < 0,6,  0 >     }      //      CAMERA: Zewnatrz [ Daleko / Front ]
    //camera{     location < 0,  2, -25>   look_at < 0,2,  0 >     }      //      CAMERA: Zewnatrz [ Blisko / Front ]
    //camera{     location < 8,  4,  4 >   look_at <8, 3.5, 2>     }      //      CAMERA: Zewnatrz [ Balkon / Bok PRAWO]
    //camera{     location < 15, 5,  0 >   look_at < 6, 3, 0 >     }      //      CAMERA: Zewnatrz [ Balkon / Na wprost PRAWO ]
    //camera{     location <-18, 5,  0 >   look_at < 6, 3, 0 >     }      //      CAMERA: Zewnatrz [ LEWO ] 
    //camera{     location < 0,  5,  18>   look_at < 0, 3, 0 >     }      //      CAMERA: Zewnatrz [ TYL ] 
    //camera{     location <-1,  2,-5.5>   look_at <0.8, 1, 0>     }      //      CAMERA: Œrodek [ Na mieszkanie ]
    //camera{     location < 5,  1, 1.5>   look_at <0, 1, -1 >     }      //      CAMERA: Œrodek [ Na pokój od stolika ]
    //camera{     location <-1,  4,  1 >   look_at < 5,2,-2  >     }      //      CAMERA: Œrodek [ Ujecie wyjscia na balkon, schody, okna ]
    //camera{     location < 0,  2,  0 >   look_at <-2, 1, 2 >     }      //      CAMERA: Œrodek [ Ujecie na krzeslo w lewym rogu ]
    //camera{     location <5.5,4.5, 1 >   look_at < 0, 0, -1 >    }      //      CAMERA: Œrodek [ Ujecie na pokoj z obok wyjscia na balkon ]
    //camera{     location <-5.1,1, -4 >   look_at <5, 1, -4 >     }      //      CAMERA: Maly pokoj [ 1 ]
    //camera{     location <-2,  1, -3 >   look_at <-5, 2,-6 >     }      //      CAMERA: Maly pokoj [ 2 ]
    //camera{     location <-5,  1,  2 >   look_at < 0, 1, 0 >     }      //      CAMERA: Metalowy pokój [ 1 ]
    //camera{     location <-5,  1,  0 >   look_at <-3, 1, 3 >     }      //      CAMERA: Metalowy pokój [ 2 ]
    //camera{     location <-2, 4, 5.5 >   look_at < 2, 0, 0 >     }      //      CAMERA: Drewniany pokój [ 1 ] 
    //camera{     location <5.5, 4,4.5 >   look_at <-5, -1,0 >     }      //      CAMERA: Drewniany pokój [ 2 ]
   
   #local krok=floor(clock*23); 
    
    camera{                                                        // Dooko³a domu
                location< 0, 1, -30 >
                right  x*image_width / image_height
                look_at < 0, 1, 0 >
                rotate  < 0, -360*(clock+0.1), 0>
           } 
     
                                                                   
    camera{                                                        // Z chodnika do œrodka
                location< 0.02, 1.2, -30+krok >
                
                look_at < 0, 0.5, 0 >
          } 
          
    camera{                                                        // W œrodku
                location < 0, 1.2, 1 >
                look_at < 0, 1.15, 0 >
                rotate < 0, -360*(clock+0.1), 0> 
                
          }
    
     
light_source{   < 0  , 20 , -10>    color White }  // Oswietlenie CALEJ sceny
light_source{   <-4  ,  3 , -4 >    color Blue  }  // Oswietlenie malego pokoju LD
light_source{   < 1.5,  3 ,  4 >    color Red   }  // Oswietlenie waskiego pokoju PG
light_source{   < 0  ,  3 ,  0 >    color White }  // Oswietlenie glownego pokoju PD
light_source{   <-4  ,  3 ,  2 >    color Brown }  // Oswietlenie w¹skiego pokoju LG 
   

sky_sphere // T³o sceny
{
    pigment{ gradient y
             color_map
             {
               [0 color Red]
               [0.8 color Blue ]
             }
             scale 2
             translate -1  
           }
           
    pigment{
        bozo
        turbulence 0.65
        octaves 6
        omega 0.8
        lambda 2
        color_map {
            [0.0 0.1 color rgb <0.85, 0.85, 0.85>
                     color rgb <0.75, 0.75, 0.75> ]
            [0.1 0.5 color rgb <0.75, 0.75, 0.75> 
                     color rgbt<1, 1, 1, 1> ]
            [0.5 1.0 color rgbt<1, 1, 1, 1>
                     color rgbt<1, 1, 1, 1> ]
                  }
              scale<0.2, 0.1, 0.2>
              }
            rotate -133*x
            

}

plane{y, 0 texture{pigment{Jade}}  }  // Podloze calej sceny    


// Œcie¿ka

box{    <-1, 0, 0> <  1, 0.2, 30> texture{Rosewood} translate <0, -0.13, -36> }
box{    <-2, 0, 0> < -1, 0.2, 30> texture{White_Marble} translate<0, -0.10, -36> }
box{    < 1, 0, 0> <  2, 0.2, 30> texture{White_Marble} translate<0, -0.10, -36> } 

// Struktura domu

union
{ 
   
  difference  
  { 
    box{    <-6, 0, -6>  <6, 5, 6>              texture{pigment{brick White, Bronze brick_size 0.35 mortar 0.03}} }    // Dom, zewn¹trz
    box{    <-5.7,0.1,-5.7> <5.7,4.7,5.7>       texture{pigment{brick White, Bronze brick_size 0.35 mortar 0.03}} }    // Wyciêcie œrodka domu
    box{    <-1, 0.01, -6.1> <1, 2, -5.5>       texture{pigment{brick White, Bronze brick_size 0.35 mortar 0.03}} }    // Otwór na drzwi                                                                                             // Otwór na drzwi
    box{    <-5.5, 4.5, -5.5>, <5.5, 6, 5.5>    texture{pigment{brick White, Bronze brick_size 0.35 mortar 0.03}} }    // Wyciêcie sufitu
    
    box{    <3, 2, -5> <5, 4, -7>               texture{pigment{brick White, Bronze brick_size 0.35 mortar 0.03}} }    // okno prawo przód
    box{    <-5, 2, -5> <-4, 4, -7>             texture{pigment{brick White, Bronze brick_size 0.35 mortar 0.03}} }    // okno lewo przód
    
    box{    <5, 2.7, 0.95 > <7, 4.5, 0.05 >           texture{pigment{brick White, Bronze brick_size 0.35 mortar 0.03}} }    // wyjscie na balkon
  } 
                                    
    box{ <-5.7, 0.1, -5.7> <5.7,0.15, 5.7>      texture{pigment{hexagon  pigment{DMFWood1}, pigment{DMFWood3}, pigment{DMFWood5} scale 0.4 }}}  // Podloga
    
    box{    < 3, 2, -6> < 5, 4, -6.3>             texture{Glass} } // Prawe okno - szyba
    box{    <-5, 2, -6> <-4, 4, -6.3>             texture{Glass} }
} 
 
  
// Pomieszczenia domu 
  
union
{
 
  difference
   {  
    box{    <-5.5, 0, -5.5> <-2.8, 5,   -2.8> texture{pigment{Tom_Wood}} }     // Maly pokoj LD
    box{    <-5.3, 0, -5.3> <-3.1, 5.1, -3.1> texture{pigment{Jade}}     }     // wyciecie
    box{    <-2.6, 0, -5.0> <-3.2, 2,   -3.5> texture{pigment{Tom_Wood}} }     // drzwi
    box{    <-5  , 2, -5.0> <-4  , 4,   -7.0> texture{pigment{brick White, Bronze brick_size 0.35 mortar 0.03}} }// wyciecie okno
   }                                                           
    
   difference
   { 
    box{    <-5.8, 0, -2.8> <-2.8, 5,    5.8> texture{Brass_Valley} }     // Dlugi pokoj  LG                                               
    box{    <-5.3, 0, -2.5> <-3.1, 5.1,  5.5> texture{Brass_Valley} }     // wyciecie 
    box{    <-1.5, 0, -2.0> <-3.2, 2,    0  > texture{Brass_Valley} }     // drzwi
   } 
  
   
   difference
   {
    box{    <-2.8, 0,   2> <5.8, 5,   5.8> texture{pigment{DMFWood1}} }   // Waski pokoj   PG
    box{    <-2.6, 0, 2.2> <5.6, 5.1, 5.6> texture{pigment{DMFWood1}} }   // wyciecie 
    box{    < 2.5, 0, 1.9> <3.5, 2,   2.3> texture{pigment{DMFWood1}} }   // drzwi
    box{    <-1.0, 0, 1.9> <1.0, 2,   2.3> texture{pigment{DMFWood1}} }
   }
}

 
// Drzwi wejœciowe

union
{
    box{    <-1.1, 0.01, -6.1> <0, 2, -5.8> texture{pigment{Tom_Wood }}       }  // Lewe drzwi
    box{    <0.05, 0.01, -6.1> <1.1, 2, -5.8> texture{pigment{Tom_Wood }}     }  // Prawe drzwi
    sphere{ <-0.1, 0.7 , -6.1>, 0.1 texture{PinkAlabaster}                    }  // Klamka lewa
    sphere{ <0.15, 0.7 , -6.1>, 0.1 texture{PinkAlabaster}                    }  // Klamka prawa 
    
   
}

// Drzwi balkon
merge
{   
  
    box{<0, 0, -0.02> < 0.10, 1.71, 0.95> texture{pigment{color White}} translate<5.67, 2.8, 0.03> }
    box{<-0.1, 0.2, 0.1> < 0.15, 1.6, 0.8> texture{Glass} translate<5.67, 2.8, 0.03>  transmit 0.5}
    
    sphere{<0, 0, 0> 0.05   texture{Gold_Metal} translate<5.5, 3.5, 0.06> }
             
    rotate<0, 0, 0>
    
    translate<0, 0, 0.02>        
    
}

// Balkon
merge
{              
    superellipsoid{<0.2, 0.08> texture{pigment{brick RichBlue, NewMidnightBlue, brick_size 0.3 mortar 0.03}}  translate <5.2, 11.5, 0> scale <1.4, 0.2, 3> finish {ambient 1} }
    cylinder{ < 0, 0, 0> < 0, 0, 6> 0.05 texture{Polished_Chrome} translate< 8.3, 3.2, -3 > } 
                   
                   
#declare slup=union
{   
    cylinder { < 0, 0, 0 > < 0, 0.95, 0> 0.02 texture{Polished_Chrome}  }    
}

#declare slupki=union
{
   #for(step, 0, 8, 1)
        object{ slup translate<0, 0, 0.7*step> }
   #end
}

// Krzeslo BALKON

merge
{
cylinder{<0  , 0, 0  > <0,    1, 0   > 0.04 texture{pigment{Pine_Wood}}}   
cylinder{<0.6, 0, 0  > <0.6,  1, 0   > 0.04 texture{pigment{Pine_Wood}}} 
cylinder{<0,   0, 0.6> <0,    1, 0.6 > 0.04 texture{pigment{Pine_Wood}}}  
cylinder{<0.6, 0, 0.6> <0.6,  1, 0.6 > 0.04 texture{pigment{Pine_Wood}}}

superellipsoid{ <0.3, 0.2>  texture{pigment{Apocalypse}} scale <0.4, 0.1, 0.4> translate <0.3, 0.95, 0.3> }

cylinder{<0  , 1, 0.6> <0  , 1.6,0.6 > 0.03 texture{pigment{Pine_Wood}}}
cylinder{<0.6, 1, 0.6> <0.6, 1.6,0.6 > 0.03 texture{pigment{Pine_Wood}}} 

superellipsoid{ <0.3, 0.2> texture{pigment{Apocalypse}} scale <0.42, 0.25, 0.05> translate <0.3, 1.6, 0.6> }      
scale <0.7, 0.7, 0.7>
rotate <0, 230, 0>

translate<6.8, 2.3, -1>
}
object{slupki translate<8.3, 2.25, -2.8>}
 
translate<0, 0.3, 0>
   
}

 

// Lampa 1 LEWA

union
{
   light_source{ <-7, 4, -4> color Yellow 
   looks_like{ sphere{ <0.1, 7, 0> 0.8 texture{pigment{color White}} finish {ambient 1} } } }
    
cylinder{ <0, 0, 0> <0, 11.2, 0> 0.25  texture{Brushed_Aluminum} translate <-6.9, 0, -4.1>} 
superellipsoid{<0.3, 0.2> texture{Chrome_Metal} translate <-6.9, 0, -4.1> } 

translate <1, 0.3, -9>
}

// Lampa 2 PRAWA

union
{
   light_source{ <-7, 4, -4> color White 
   looks_like{ sphere{ <0.1, 7, 0> 0.8 texture{pigment{color White}} finish {ambient 1} } } }
    
cylinder{ <0, 0, 0> <0, 11.2, 0> 0.25  texture{Brushed_Aluminum} translate <-6.9, 0, -4.1>} 
superellipsoid{<0.3, 0.2> texture{Chrome_Metal} translate <-6.9, 0, -4.1> } 

translate <13, 0.3, -9>
}

// Schody

#declare stopien=union
{  box{<0,0,0> <0.6, 0.4, 0.5> texture{pigment{DMFWood2}} }     } 
    
#declare schody=union
{
    #for(krok, 0, 6, 0.5)
        object{ stopien translate<0, 0.4*krok, 0.5 *krok> }
    #end
}       

object{schody   rotate<0, 0, 0>    translate<4.7, 0.1, -4>}     // Wywolanie obiektu
box{ <0, 0, 0> <0.9, 0.4, 2.5> texture{pigment{DMFWood2}} translate<4.7, 2.5, -0.5>} // Kladka na przejscie do balkonu



// Dach

prism { conic_sweep linear_spline 0, 1, 5, 
<8,8> <-8,8> <-8,-8> <8,-8> <8,8>

rotate<180, 0, 0>
translate<0, 2.2, 0>
scale<1,4,1>

pigment
    {gradient x
        color_map
        {
            [0.8 color Red]
            [0.5 color Yellow]
            [0.1 color Blue]
            [0.2 color Green]
            [0.4 color Brown]
        }    
    }
}


/////////// MEBLE

// Krzeslo 1 GLOWNY POKOJ

merge
{
cylinder{<0  , 0, 0  > <0,    1, 0   > 0.04 texture{pigment{Pine_Wood}}}   
cylinder{<0.6, 0, 0  > <0.6,  1, 0   > 0.04 texture{pigment{Pine_Wood}}} 
cylinder{<0,   0, 0.6> <0,    1, 0.6 > 0.04 texture{pigment{Pine_Wood}}}  
cylinder{<0.6, 0, 0.6> <0.6,  1, 0.6 > 0.04 texture{pigment{Pine_Wood}}}

superellipsoid{ <0.3, 0.2>  texture{Sandalwood} scale <0.4, 0.1, 0.4> translate <0.3, 0.95, 0.3> }

cylinder{<0  , 1, 0.6> <0  , 1.6,0.6 > 0.03 texture{pigment{Pine_Wood}}}
cylinder{<0.6, 1, 0.6> <0.6, 1.6,0.6 > 0.03 texture{pigment{Pine_Wood}}} 

superellipsoid{ <0.3, 0.2> texture{pigment{Tom_Wood}} scale <0.42, 0.25, 0.05> translate <0.3, 1.6, 0.6> }      
scale <0.7, 0.7, 0.7>
rotate <0, -45, 0>

translate<-2.3, 0, 1>
}

 
// Krzeslo 2 GLOWNY POKOJ 

merge
{
cylinder{<0  , 0, 0  > <0,    1, 0   > 0.04 texture{pigment{Pine_Wood}}}   
cylinder{<0.6, 0, 0  > <0.6,  1, 0   > 0.04 texture{pigment{Pine_Wood}}} 
cylinder{<0,   0, 0.6> <0,    1, 0.6 > 0.04 texture{pigment{Pine_Wood}}}  
cylinder{<0.6, 0, 0.6> <0.6,  1, 0.6 > 0.04 texture{pigment{Pine_Wood}}}

superellipsoid{ <0.3, 0.2>  texture{Jade} scale <0.4, 0.1, 0.4> translate <0.3, 0.95, 0.3> }

cylinder{<0  , 1, 0.6> <0  , 1.6,0.6 > 0.03 texture{pigment{Pine_Wood}}}
cylinder{<0.6, 1, 0.6> <0.6, 1.6,0.6 > 0.03 texture{pigment{Pine_Wood}}} 

superellipsoid{ <0.3, 0.2> texture{pigment{Jade}} scale <0.42, 0.25, 0.05> translate <0.3, 1.6, 0.6> }      
scale <0.7, 0.7, 0.7>
rotate <0, 60, 0>

translate<4.5, 0, 1>
} 

// Krzeslo 3 GLOWNY POKOJ

merge
{
cylinder{<0  , 0, 0  > <0,    1, 0   > 0.04 texture{pigment{Pine_Wood}}}   
cylinder{<0.6, 0, 0  > <0.6,  1, 0   > 0.04 texture{pigment{Pine_Wood}}} 
cylinder{<0,   0, 0.6> <0,    1, 0.6 > 0.04 texture{pigment{Pine_Wood}}}  
cylinder{<0.6, 0, 0.6> <0.6,  1, 0.6 > 0.04 texture{pigment{Pine_Wood}}}

superellipsoid{ <0.3, 0.2>  texture{pigment{Sapphire_Agate}} scale <0.4, 0.1, 0.4> translate <0.3, 0.95, 0.3> }

cylinder{<0  , 1, 0.6> <0  , 1.6,0.6 > 0.03 texture{pigment{Pine_Wood}}}
cylinder{<0.6, 1, 0.6> <0.6, 1.6,0.6 > 0.03 texture{pigment{Pine_Wood}}} 

superellipsoid{ <0.3, 0.2> texture{pigment{Sapphire_Agate}} scale <0.42, 0.25, 0.05> translate <0.3, 1.6, 0.6> }      
scale <0.7, 0.7, 0.7>
rotate <0, 115, 0>

translate<4.2, 0, -0.3>
} 

// Stolik GLOWNY POKOJ

merge
{
cylinder{<0, 0, 0> <0, 0.05, 0> 0.55  texture{pigment{White_Wood}} translate<3, 1.0, -2> }   
cylinder{<0, 0, 0> <0, 0.05, 0> 0.55  texture{pigment{White_Wood}} translate<3, 0.8, -2> rotate <0, 0, 0>}

cylinder{<0, 0, 0> <0, 1, 0> 0.03 texture{pigment{Cherry_Wood}} translate<2.6, 0, -1.75>}   // nogi
cylinder{<0, 0, 0> <0, 1, 0> 0.03 texture{pigment{Cherry_Wood}} translate<2.6, 0, -2.25>}
cylinder{<0, 0, 0> <0, 1, 0> 0.03 texture{pigment{Cherry_Wood}} translate<3.4, 0, -1.75>}
cylinder{<0, 0, 0> <0, 1, 0> 0.03 texture{pigment{Cherry_Wood}} translate<3.4, 0, -2.25>}

translate<0.8, 0, 2.3>
}

