cd C:\Users\Student_PL\Desktop\mj\PSlab2
New-Item -ItemType File -Path miesiace.txt
"Styczeń" >> miesiace.txt
"Luty" >> miesiace.txt
"Marzec" >> miesiace.txt
"Kwiecień" >> miesiace.txt
"Maj" >> miesiace.txt
"Czerwiec" >> miesiace.txt
"Lipiec" >> miesiace.txt
"Sierpień" >> miesiace.txt
"Wrzesień" >> miesiace.txt
"Październik" >> miesiace.txt
"Listopad" >> miesiace.txt
"Grudzień" >> miesiace.txt
 [string]   $mies = Get-Content "miesiace.txt"
#[string[]] $mies = Get-Content "miesiace.txt"

$mies.IndexOf("Luty")
New-Item -ItemType File -Path MiesiacRokuPrzestepnego.txt
$mies.Substring($mies.IndexOf("Luty"), $mies.IndexOf("", 4)) >> MiesiacRokuPrzestepnego.txt

"" > "MiesiacRokuPrzestepnego.txt"

$dni = 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31

Function IloscDni{
[string[]] $mies = Get-Content "miesiace.txt"
# $mies = [string]::Join(" ", $dni)
for($i=0; $i -lt 11; $i++)
    {
       
    }
}
IloscDni
