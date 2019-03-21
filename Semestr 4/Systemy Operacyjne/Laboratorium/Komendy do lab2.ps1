[string] $mies = Get-Content "miesiace.txt" # tekst
[string[]] $mies = Get-Content "miesiace.txt" # tablica
$m = $mies.Remove(od , do)
$m = "A" + 6 + $mies
$m = $mies.Replace(co , na co)
$m = $mies.Split(" ")
$m = [string]::Join(" ", $tab)
$dni = (Get-Culture).Calendar.GetDaysInMonth(rok, miesiac)

Function Licz($p1, $p2, ...) {

}
Licz 7 2 
