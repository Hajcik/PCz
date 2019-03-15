open System

[<EntryPoint>]
let main argv =
    let rec fib1 n =
        if n<=2 then 1
        else fib1(n-2) + fib1(n-1)
    
    let rec fib2 n =
        match n with
        | 1 | 2 -> 1
        | n -> fib2 (n-2) + fib2 (n-1)

    let rec suma1 lista =
        match lista with
        | head :: tail -> head + suma1 tail
        | [] -> 0

    let suma2 lista =
        let rec loop lista acc =
            match lista with
            | head :: tail -> loop tail (acc + head)
            | [] -> acc
        loop lista 0

    Console.WriteLine(fib1 3)
    Console.WriteLine(fib2 3)
        
    Console.ReadKey() |> ignore
    0 // return an integer exit code
