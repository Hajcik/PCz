open System
open System.Diagnostics
open System.Runtime.InteropServices

[<EntryPoint>]
let main argv = 
    //1,2
    (*
    printf "Wpisz swoje imie: "
    let name = Console.ReadLine()
    printf "Wpisz swoje nazwisko: "
    let surname = Console.ReadLine()
    printf "Twoje imie to %s %s" name surname )*)
    //3
    (*let volume radius length : float =
        let pi = 3.14159
        length*pi*radius*radius
    let vol = volume 3.0 5.0
    printfn "Volume %g " vol*)
    //4
    (*let field r : float =
        let pi = 3.14159
        pi*r*r/2.0
    let circuit r : float = 
        let pi = 3.14159
        2.0*pi*r
    
    let fiel = field 5.0
    let circui = circuit 5.0
    printfn "Pole kola wynosci %g a obwód %g" fiel circui*)
    //5
    (*let wielomian x y : float =
        (-5.0*y**4.0+1.0/3.0*x**2.0+3.0*y-7.0)
    let spr = wielomian 3.0 5.0
    printf "Wielomian %g " spr*)
    //6
    (*let rec rekurencja a n q =
        if n<2 then
            a
        else 
            q * rekurencja a (n-1) q
    Console.WriteLine(rekurencja 1 2 5)*)
    //7
    (*let x = 25
    let y = 46 
    //a
    printfn("%u %u") x y
    //b
    printfn("      %u %u") x y
    //c
    printfn("%u %u 000000") x y
    //d
    printfn("+%u +%u") x y
    //e
    printfn("%o %o") x y
    //f
    printfn("%X %X") x y*)

    //8
    let z = 56.123
    printfn "%E" z
    printfn "%.4f" z

    Console.ReadKey() |> ignore
    let main argv =

    let rec fib n = 
        if n <= 2 then 1
        else fib (n-2) + fib (n-1)

    Console.WriteLine(fib 6)


    let rec fib1 n = 
        match n with
        | 1 | 2 -> 1
        | n -> fib (n-2) + fib (n-1)

    Console.WriteLine(fib1 6)

   
    let rec suma lista =
        match lista with
        | head::tail -> head + suma tail
        | [] -> 0 

    let tablica = [for i in 1..10000 -> i]

    let stopWatch = System.Diagnostics.Stopwatch.StartNew()
   //topWatch.Reset()
    stopWatch.Start()
    Console.WriteLine(suma tablica)
    stopWatch.Stop()
    printfn "%f" stopWatch.Elapsed.TotalSeconds

    let suma1 lista = 
        let rec loop lista acc = 
            match lista with
            | head::tail -> loop tail (acc + head)
            |  [] -> acc
        loop lista 0

    stopWatch.Reset()
    stopWatch.Start()
    Console.WriteLine(suma1 tablica)
    stopWatch.Stop()
    printfn "%f" stopWatch.Elapsed.TotalSeconds

    Console.ReadKey() |> ignore;
    open System
[<EntryPoint>]
let main argv = 
    //fibonaczi
    (*
    let rec fib n = 
        if n<=2 then 1
        else fib (n-2) + fib (n-1)
    
    Console.WriteLine(fib 5)
    *)
    //2
    (*
    let sprawdzenie (x,y) =
        if x%4 = y%4 then true
        else false
    Console.WriteLine(sprawdzenie (5,5)) *)
    //5
   (* let funkcja (x,y) =
        match x%y with
        | 0-> None
        | _-> Some (x%y)
    Console.WriteLine(funkcja (20,12)) *)
    //6
    (*
    let posortowana = List.sort [-4; 2; 9; -11; 0; 4]
    printfn "Lista posortowana: %A" posortowana
    let suma = List.sum[5..67]
    printfn "suma %d" suma
    let srednia = List.average[3.5;6.3;632.3;]
    printfn "srednia %.2f " srednia
    let srednia2 = List.averageBy (fun x-> x*x) [3.5;6.3;632.3;]
    printfn "srednia %.2f " srednia2
    let lista = [1..5]
    let lista2 = [for i in 1..5 -> i*i]
    let zip2 = List.zip lista lista2
    printfn "polaczenie 2 list %A " zip2
    let nowa = List.map (fun x-> x*x+1) lista
    printfn "nowa lista %A" nowa
    let parzyste = List.filter (fun x-> x%2 =0 )[1..100]
    printfn "parzyste: %A "parzyste *)
    //7
    (*
    let tablica = [|1;2;3|]
    printfn "Tablica %A" tablica
    let tablica1 = Array.create 5 1
    printfn "Tablica1 %A" tablica1
    tablica.[2] <-7
    printfn "Tablica zmiana %A" tablica
    Array.set tablica1 2 7
    printfn "Tablica1 %A" tablica1
    printfn "indeks 2 tablicy %A" tablica.[2]
    printfn "indeks 2 tablicy1 %A" (Array.get tablica1 2)
    let tablica2 = Array.empty
    printfn "Pusta tab2 %A" tablica2
    let tablica3 : int array = Array.zeroCreate 5
    printfn "Tablica3 %A" tablica3
    Array.fill tablica3 1 3 5
    printfn "Tablica3 %A" tablica3
    let tablica5 = Array.sub tablica3 1 2
    printfn "Tablica5 %A" tablica5
    let tablica6 = Array.append tablica3 tablica5
    printfn "Tablica5 i 3 %A" tablica6
    let tablica7 = Array2D.init 2 3 (fun i j -> (i+1)*(j+1))
    printfn "Tablica7 %A" tablica7
*)
    
    Console.ReadKey() |> ignore
    let main argv = 
    //1
    //let liczby =  [1.0;5.0;3.0;72.0;23.0] 
    (*
    let srednia lista =
        List.average lista
    Console.WriteLine(srednia liczby) *)
    //2
    (*
    let zadanie2 lista =
        let sr = List.average lista
        List.filter (fun x-> x>sr) lista
    Console.WriteLine(zadanie2 liczby)  
    *)
    //3
    (*
    let minMax lista =
        match lista with
        |[] -> None
        |_-> Some(List.max lista,List.min lista)
    
    Console.WriteLine(minMax liczby
    
    
    
