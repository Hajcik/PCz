echo "1) Dodawanie"
echo "2) Odejmowanie"
echo "3) Mnożenie"
echo "4) Dzielenie"

let dodawanie=$1+$2
let odejmowanie=$1-$2
let mnozenie=$1*$2
if [ $2 == 0 ] ; then
    echo "Nie można dzielić przez 0"
  else
  let dzielenie = $1/$2
fi

echo "Podane liczby na których będą prowadzone działania: $1 oraz $2"
echo "Wybierz operację (1 - 4)"
  read operacja
  case $operacja in
    "1")echo "Dodawanie:    $dodawanie"
    "2")echo "Odejmowanie:  $odejmowanie"
    "3")echo "Mnożenie:     $mnozenie"
    "4")echo "Dzielenie:    $dzielenie"
    *)echo  "Wybrano nieprawidłową liczbę"
  esac
