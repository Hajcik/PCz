let inline Testuj sprawdzana =
  let mutable pierwsza = true
  let mutable dzielnik = 2
  while dzielnik < sprawdzana
      &&pierwsza do
        pierwsza <- not(sprawdzana % dzielnik = 0)
        dzielnik <- dzielnik + 1
        if pierwsza then printfn "\a"
        pierwsza
  let inline NtaLiczbaPierwsza n =
    let mutable sprawdzana = 1
    for i = 1 to n do
      sprawdzana <- sprawdzana + 1
      while not(Testuj sprawdzana) do
        sprawdzana <- sprawdzana + 1
       sprawdzana
     printf "%d" (NtaLiczbaPierwsza 10001)
