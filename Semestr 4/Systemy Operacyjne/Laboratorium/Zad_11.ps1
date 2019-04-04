# Zadanie 11 
cd C:\Users\Student_PL\Desktop
New-Item -ItemType File -Path procesy.txt
Get-Process | Where-Object Name -Like "*svchost*" | Sort-Object -Property CPU -Descending >procesy.txt
