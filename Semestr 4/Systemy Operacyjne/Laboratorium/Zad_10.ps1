$liczba_1 = Read-Host -Prompt 'Podaj liczbe 1'
$liczba_2 = Read-Host -Prompt 'Podaj liczbe 2'
$element
Write-Host -NoNewline "Liczby miedzy podanymi: "
foreach($element in $liczba_1..$liczba_2)
{
Write-Host -NoNewLine "${element} "
}
