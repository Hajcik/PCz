#include "colors.inc"
#include "textures.inc"
#include "stones2.inc"
     
    camera{     location < 0,  8, -15>   look_at < 0,6,  0 >     }      //      CAMERA: Zewnatrz [ Daleko / Front ]
         
light_source{   < 0  , 20 , -10>    color White }  // Oswietlenie CALEJ sceny
sky_sphere // Tło sceny
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


// DECLARE

#declare random1 = seed(1432);
#declare random2 = seed(7123);
#declare random3 = seed(9910);

// MACRO

#macro kolor(kkolor, ktekstura, kpigment)

texture{color{kkolor}}
texture{pigment{kpigment}}
texture{ktekstura}

#end



#macro szyba(wsp_x, wsp_y, wsp_z)
    box{ <0, 0, 0> <1, 1, 0.1> texture{Glass} }
    translate <wsp_x, wsp_y, wsp_z>
#end

#macro pietro(tx, ty, tz)
union
{
    difference
    {
    box{ <0, 0, 0> <12, 4, 3> texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} }
    box{ <0.2, 0.1, 0.2> < 11.8, 3.9, 2.8> texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}}}
    
    box{ <1, 1, -1> <2, 2, 1> texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} }
    box{ <3, 1, -1> <4, 2, 1> texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} }
    box{ <5, 1, -1> <6, 2, 1> texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} }
    box{ <7, 1, -1> <8, 2, 1> texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} }
    box{ <9, 1, -1> <10, 2, 1> texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} }   
    
    box{ <1, 2.5, -1> <2, 3.5, 1>  texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} }
    box{ <3, 2.5, -1> <4, 3.5, 1>  texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} }
    box{ <5, 2.5, -1> <6, 3.5, 1>  texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} }
    box{ <7, 2.5, -1> <8, 3.5, 1>  texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} }
    box{ <9, 2.5, -1> <10, 3.5, 1> texture{pigment{color rgb< rand(random1), rand(random2), rand(random3)>}} } 
     
    }  
    // Szyby
    object{ szyba(1, 2, 0) }
    object{ szyba(3, 2, 0) }
    object{ szyba(5, 2, 0) }
    object{ szyba(7, 2, 0) }
    object{ szyba(9, 2, 0) }
    
    object{ szyba(1, 2.5, 0) }
    object{ szyba(3, 2.5, 0) }
    object{ szyba(5, 2.5, 0) }
    object{ szyba(7, 2.5, 0) }
    object{ szyba(9, 2.5, 0) }
                                                                       
    box{ <0, 0, 0> <12, 0.1, 3> texture{pigment{hexagon White, Orange, Brown scale 0.3}}}
    translate <tx, ty, tz>    // miejsce na scenie
}
#end  



#macro blok(ilosc_pieter, wx, wy, wz, wsp_x, wsp_y, wsp_z)
  
  
  #for(krok, 0, ilosc_pieter, 1)
    object{ pietro(wx, wy, wz) translate<0, 4*krok, 0> }
  
  #end
  translate<wsp_x, wsp_y, wsp_z>
    
#end 

union
{
   
blok(4, 0, 0, 0, 0, 0, 0)

}

    


