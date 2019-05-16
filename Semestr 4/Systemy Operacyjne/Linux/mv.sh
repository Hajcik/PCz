echo "Chcesz zmienić nazwę pliku (1) czy go przenieść (2)?"
read wybor
case $wybor in
  "1")echo "ZMIANA NAZWY PLIKU: "
      echo "Wprowadz nazwę pliku: "
          read nazwa1
      echo "Wprowadzona nowa nazwa pliku: "
          read nazwa2
            touch $nazwa1
            touch $nazwa2
            cp $nazwa1 $nazwa2
            rm $nazwa1 ;;
   "2")echo "PRZENIESIENIU PLIKU: "
          read plik
       touch $plik
       echo "Wprowadz nazwę folderu gdzie chcesz przenieść plik: "
          read folder
       cp $plik $folder
       rm $plik ;;
   *)echo "WPROWADZONO ZŁĄ WARTOŚĆ!"
esac
