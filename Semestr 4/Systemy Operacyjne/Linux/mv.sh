#!/bin/bash
echo "Chcesz zmienić nazwę pliku (1) czy go przenieść (2)?"
read -r wybor
case $wybor in
  "1")echo "ZMIANA NAZWY PLIKU: "
      echo "Wprowadz nazwę pliku: "
          read -r nazwa1
      echo "Wprowadzona nowa nazwa pliku: "
          read -r nazwa2
            touch "$nazwa1"
            touch "$nazwa2"
            cp "$nazwa1" "$nazwa2"
            rm "$nazwa1" ;;
   "2")echo "PRZENIESIENIU PLIKU: "
          read -r plik
       touch "$plik"
       echo "Wprowadz nazwę folderu gdzie chcesz przenieść plik: "
          read -r folder
       cp "$plik" "$folder"
       rm "$plik" ;;
   *)echo "WPROWADZONO ZŁĄ WARTOŚĆ!"
esac
