function Minimum
{
  read -r zmienna1
  read -r zmienna2
if [ $zmienna1 -lt $zmienna2 ]; then
        let wynik=$zmienna1
  else
        let wynik=$zmienna2
fi
return $wynik
}
Minimum
echo "Minimum: $?"
