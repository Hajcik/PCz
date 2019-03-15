select Name, Attributes
cd C:\Users\Student_PL\Desktop\mj
mkdir Dom
cd Dom
mkdir Okno, Drzwi
cd Drzwi
New-Item -ItemType File -Name Klamka.txt
$test = "mosiezna"
Add-Content Klamka.txt $test

New-Item -ItemType File -Name Zamek.txt
# $zamek.attributes="Hidden"
$zamek = "wpuszczany"
Write-Output $zamek | add-content Zamek.txt
attrib +h Klamka.txt
attrib +r Zamek.txt
Copy-Item Klamka.txt C:\Users\Student_PL\Desktop\mj\Dom\Okno
cd C:\Users\Student_PL\Desktop\mj\Dom\Okno
Rename-Item Klamka.txt "Klamka okienna.txt"
attrib -h "Klamka okienna.txt"
Get-Content "Klamka okienna.txt" 
$zamek_okno = "Plastikowa"
Add-Content "Klamka okienna.txt" $zamek_okno 

"Plastikowa" > "Klamka okienna.txt"

cd C:\Users\Student_PL\Desktop\mj
Function UtworzKatalogi
{
For($i=0; $i -lt 10; $i++) {mkdir Folder$i;}
}
UtworzKatalogi
cd C:\Users\Student_PL\Desktop\mj
