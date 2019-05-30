--zad1.1
select Count(*) as "Liczba studentek" from Studenci
where imiona like '%a' and tryb like 'STACJONARNY' 
and rok=3 and stopien=1 and kierunek like 'INFORMATYKA';
--zad1.2
--select Count(*) as "Liczba Nowakowskich" from Studenci
--where nazwisko like 
--zad1.3
--zad1.4
select concat(nazwisko, concat(' ', imiona)) as "Personalia studenta"
from studenci where stopien=3 and rok=4 order by nazwisko;
--zad1.6
select substr(nazwisko, 1, 1)||'.'||substr(imiona, 1, 1)||'.' as "Inicjaly",
nazwisko, imiona, length(concat(nazwisko,imiona)) as "Liczba liter" from
studenci where length(concat(nazwisko,imiona)) in (9,11,13);
--zad1.8
select Ltrim(nazwisko,'Ko') as "Nazwisko bez Ko",
Rtrim(imiona,'sz') as "Imiona bez sz", nazwisko||' '||imiona
as "Personalia" from Studenci
where nazwisko like 'Ko%' and imiona like '%sz';
--zad1.11
select Rpad(lpad(nazwisko, length(nazwisko)+3, '*'),
length(nazwisko)+7, '+') from Studenci;


--zad2.1
select * from pojazdy where nr_rejestr between 'SC0%' and 'SC9%'
and pojemnosc between 1000 and 2000;
select nr_rejestr from pojazdy where nr_rejestr 
like 'SC%' and substr(nr_rejestr,3,1)
in ('1','2','3','4','5','6','7','8','9','0') and pojemnosc
between 1000 and 2000;
--zad2.4
select marka, model, typ, pojemnosc, 
decode(pojemnosc,1000,'maly pojazd',2000,'sredni pojazd',3000,'duzy pojazd')
as komentarz from pojazdy where typ not like 'samochod ciezarowy'
and pojemnosc in(1000,2000,3000);

--zad3.1
select 'od '||Trunc(Min(czas))||' do '||Trunc(Max(czas))||
' odnotowano '||Count(czas)||' polowow w tym udanych '||
Count(id_gatunku)||' na wodach '|| count(distinct(substr(id_lowiska,1,1)))|| 'zarzadcow.'
from rejestry;
--zad3.3
select Count(*)"Liczba ryb", 
Count(distinct id_wedkarza)"Liczba lowcow",
Count(distinct id_lowiska)"Liczba lowisk",
sum(waga)"Laczna waga",
round(avg(waga),3)"Srednia waga",
round(avg(dlugosc))"Srednia dlugosc" from rejestry where id_gatunku=1;
--zad3.2
select * from rejestry where id_gatunku in(1,3,9,10)
and id_lowiska like 'C%' and dlugosc between 40 and 60 and mod(waga,0.1)>0;
