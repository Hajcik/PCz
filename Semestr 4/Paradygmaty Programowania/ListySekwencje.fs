open System

[<EntryPoint>]
let main argv =

// Sekwencje
    let seq1 = seq {1 .. 10 }
    let seq2 = seq {0 .. 10 .. 100 }
    let seq3 = seq { for i in 1 .. 10 do yield i * i}
    let seq4 = seq { for i in 1 .. 10 -> i * i}
    printfn "seq1: %A" seq1
    printfn "seq2: %A" seq2
    printfn "seq3: %A" seq3
    printfn "seq4: %A" seq4
    Console.WriteLine()
// Listy
    let lista  = [1; 2; 3]
    let lista6 = [1 .. 5]
    let lista2 = [
        1
        2
        3 ]
    let lista3 = [for i in 1..10 -> i*i]
    let lista4 = 1 :: 2 :: 3 :: 4 :: []
    let lista5 = List.init 5 (fun x-> x*2)
    
// Dodawanie kolejnego elementu na poczatek listy:
    let przykladowa_lista = [1;2;3]
    let y = 10::przykladowa_lista
    printfn "Czy lista jest pusta : %b" (przykladowa_lista.IsEmpty)
    printfn "Długość listy : %d" (przykladowa_lista.Length)
    printfn "Pierwszy element listy : %d" (przykladowa_lista.Head)
    printfn "Drugi element listy : %d" (przykladowa_lista.Tail.Head)
    printfn "Trzeci element listy : %d" (przykladowa_lista.Tail.Tail.Head)
    printfn "Element o indeksie(1) : %d" (przykladowa_lista.Item(1))
    Console.WriteLine()
// Sortowanie listy
    let posortowana_lista = List.sort [-4; 2; 9; -11; 0; 16; 4]
    printfn "Lista posortowana: %A" posortowana_lista
    Console.WriteLine()
// Wyszukiwanie pierwszego elementu listy spełniającego kryterium:
    let Szukana = List.find (fun x -> x % 79 = 0) [80 .. 200]
    printfn "pierwsza liczba podzielna przez 17: %d" Szukana
    Console.WriteLine()
// Suma elementów
    let suma = List.sum [5 .. 56]
    printfn "suma: %d" suma
    let suma2 = List.sumBy (fun x -> x*x) [1 .. 10]
    printfn "suma kwadratow elementow z listy: %d" suma2
    Console.WriteLine()
// Wartość średnia z elementów:
    let srednia = List.average [3.5; 8.6; 4.3; 1.0]
    printfn "srednia: : %.2f" srednia
    let srednia2 = List.averageBy (fun x -> x*x) [3.5; 8.6; 4.3; 1.0]
    printfn "srednia z kwadratów elementów z listy: %.2f" srednia2
    Console.WriteLine()
// Łączenie list
    let zip2 = List.zip lista lista2
    printfn "połączenie dwóch: %A" zip2
    Console.WriteLine()
// Utworzenie nowej na podstawie starej
    let nowa = List.map (fun x -> x*x + 1) lista
    printfn "nowa lista na podstawie istniejącej: %A" nowa
// Filtrowanie listy
    let parzyste = List.filter (fun x -> x%2 = 0) [1..100]
    printfn "Parzyste: %A" parzyste



// Tworzenie tablicy
    let tablica = [|1; 2; 3|]
    printfn "Tablica: %A" tablica
    let tablica1 = Array.create 5 1
    printfn "Tablica1: %A" tablica1

//  Długość tablicy
    printfn "Dlugosc tablicy: %A" tablica.Length

//  Zmiana elementu
    tablica.[2] <- 7
    printfn "Zmiana elementu tablicy1: %A" tablica1
    Array.set tablica1 2 7
    printfn "Zmiana elementu tablicy1: %A" tablica1

//  Pobranie elemetu
    printfn "pobranie elementu o numerze indeksu(2) tablicy: %A"
    tablica.[2]
    printfn "zmiana elementu o numerze indeksu(2) tablicy1: %A"
    (Array.get tablica1 2)

//  Utworzenie pustej tablicy
    let tablica2 = Array.empty
    printfn "pusta tablica2: %A" tablica2

//  Utworzenie tablicy z samych zer
    let tablica3: int array = Array.zeroCreate 5
    printfn "tablica3 samych zer: %A" tablica3

//  Kopiowanie tablicy
    let tablica4 = Array.copy tablica3
    printfn "tablica4, czyli kopia tablicy3: %A" tablica4
//  Wypełnianie tablicy nowymi zmiennymi
    Array.fill tablica3 1 3 5
    printfn "tablica3 z nowymi elementami: %A" tablica3
//  Utworzenie tablicy z użyciem części elementów z poprzedniej tablicy
    let tablica5 = Array.sub tablica3 1 2
    printfn "tablica5, czyli częśc tablicy3: %A" tablica5
//  Połączenie tablic
    let tablica6 = Array.append tablica3 tablica5
    printfn "tablica6, czyli połaczenie tablicy3 i tablicy5: %A" tablica6
//  Filtrowanie - parzyste
    printfn "parzyste o 1 do 20: %A" (Array.filter (fun x -> x % 2 = 0)
    [|1..20|])
//  Tablica odwrócona
    printfn "tablica odwrócona: %A" (Array.rev tablica5)
//  Tablica 2D
    let tablica7 = Array2D.init 2 3 (fun i j -> (i+1)*(j+1))
    printfn "tablica 2D : %A" tablica7
//  Zamiana elementu tablicy 2D
    tablica7.[0,1] <- 8
    printfn "tablica 2D po zamaianie: %A" tablica7

    Console.ReadKey() |> ignore
    0 // return an integer exit code
