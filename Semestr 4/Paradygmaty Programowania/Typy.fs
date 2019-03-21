open System
type Punkt = { x: float; y: float; z: float }
type Osoba = {  // definicja z polem zmiennym
    Nazwisko: string
    Imie: string
    mutable Wiek: int}

[<EntryPoint>]
let main argv=
    let p1 = {x = 1.0; y = 1.0; z = -1.0 }
    let p2 = {Punkt.x = 1.0; Punkt.y = 1.0; Punkt.z = -1.0}
    printfn "p1: %A" p1
    printfn "p2: %A" p2
    let p3 = { p2 with y = 1.0; z = -1.0 }
    printfn "p3: %A" p3
    let Osoba1 = { Nazwisko = "Kowalski"; Imie = "Jan"; Wiek = 16 }
    printfn "Osoba1: %A" Osoba1
// aktualizacja pola Osoba1
    Osoba1.Wiek <- Osoba1.Wiek + 8
    printfn "Osoba1 po aktualizacji: %A" Osoba1
    
    0 // return an integer exit code
