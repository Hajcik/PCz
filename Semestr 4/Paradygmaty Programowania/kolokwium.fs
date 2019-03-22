open System

[<EntryPoint>]
let main argv =
// Zadanie 1
    let funkcja n =
        if n<=50 then n*n
        else if n%7=0 then 1
        else 0
    Console.WriteLine("Zadanie1: Jeżeli podzielne przez 7 to 1, jak nie to 0")
    Console.WriteLine(funkcja 63)
    Console.WriteLine(funkcja 59)
    Console.WriteLine(funkcja 13)
// Zadanie 2
    let rec zad x =
        match x with
        | 0 | 1 -> 1
        | _ -> x + zad (x-1)
    Console.WriteLine("Zadanie2: ")
    Console.WriteLine(zad 5)
// Zadanie 3
    let lista = [1; -2; 3; -8; 5]
    let mutable min = List.min lista
    let mutable max = List.max lista
    let funkcja = min * max
    Console.WriteLine("Zadanie3: ")
    Console.WriteLine(funkcja)
// Zadanie 4
    let tablica = [|for i in 1..10 -> i*i|]
    Console.WriteLine("Zadanie4: ")
    printfn "Parzyste: %A" (Array.filter (fun x -> x%2 = 0) tablica)
// Zadanie 5
//    let rec pierwsza n x h =
//        if x%x = 0 && x%1 = 0 then n = h
//        h++
       
    Console.ReadKey() |> ignore
 
    0 // return an integer exit code
