// Learn more about F# at http://fsharp.org

open System
open System.Numerics
[<EntryPoint>]
let main argv =
    let ObjetoscWalca (H:float, r:float) = 3.14 * (r * r) * H
    let wynik = ObjetoscWalca (5.0, 3.0)
    Console.Write("Objetosc walca o r = 3 i H = 5 wynosi V= ")
    Console.WriteLine(wynik)
    
    let Kwadrat (x:float) = x*x , 4.0*x
    let wynik = Kwadrat(3.0)
    Console.Write("Pole i obwod kwadratu: ")
    Console.WriteLine(wynik)

    let Prostokat (a: float, b: float) = a*b , 2.0*a + 2.0*b
    let wynik = Prostokat(3.5, 3.2)
    Console.Write("Pole i obwod prostokata: ")
    Console.WriteLine(wynik)

    let Kolo (r: float) = 3.14 * r*r , 2.0 * 3.14 *r
    let wynik = Kolo(3.0)
    Console.Write("Pole i obwod kola: ")
    Console.WriteLine(wynik)

    let Wielomian (x:float, y:float) = -5.0*(y*y*y*y) + (1.0/3.0)*(x*x) + 3.0*y - 7.0
    let (wynik: float) = Wielomian(1.0, 1.0)
    Console.Write("Wielomian wynosi dla x = 1.0 i y = 1.0: ")
    Console.WriteLine(wynik)
    
    Console.Write("Wyniki jednych funkcji mozna przekazywac do innych, pdf nr1, wynik operacji: ")
    let liczba = 10
    let funkcja1 x = x+1
    let funkcja2 x = x*2
    
    let wynik = (funkcja1 >> funkcja2) liczba
    printfn "%d" wynik
    Console.ReadKey()
    0 // return an integer exit code
