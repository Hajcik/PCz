--zad2
select extract(year from czas) rok, gatunki.nazwa Gatunek, dlugosc, nazwisko, lowiska.nazwa from Rejestry 
join Wedkarze using(id_wedkarza) 
join Gatunki using (id_gatunku) 
join lowiska using (id_lowiska)
where (extract(year from czas), id_gatunku, dlugosc) in 
(
  select extract(year from czas) , id_gatunku , max(dlugosc)
  from Rejestry
  group by extract(year from czas), id_gatunku
);

--zad 3
select * from rejestry
where extract(month from czas)=5 and extract(day from czas) in (6,7) and
waga = 
(
select max(waga) from rejestry where extract(month from czas) = 5
and extract(day from czas) in (6,7)
);

--zad 7
select id_kierowcy, nazwisko, imie, adres, count(nr_rejestr),
(select count(nr_rejestr) from Pojazdy where typ like 'samochod osobowy' and wlasciciel = id_kierowcy) as SAM,
(select count(nr_rejestr) from Pojazdy where typ like 'motocykl' and wlasciciel = id_kierowcy) as MOT
from kierowcy join pojazdy on(wlasciciel = id_kierowcy)
where typ like 'samochod osobowy' or typ like 'motocykl'
group by id_kierowcy, nazwisko, imie, adres
having count(nr_rejestr) = 
(
  select max(count(wlasciciel)) from pojazdy
  where typ like 'samochod osobowy' or typ like 'motocykl'
  group by wlasciciel
);

--zad 13
select * from 
(
select id_gatunku, id_wedkarza, id_lowiska, dlugosc, 
extract(year from czas)rok
from rejestry
)t1 join
(
select id_gatunku, extract(year from czas)rok, avg(dlugosc)srednia
from rejestry where dlugosc is not null
group by id_gatunku, extract(year from czas)
)t2 on (t1.id_gatunku = t2.id_gatunku and t1.rok = t2.rok and
        dlugosc>srednia);

--zad 16
select decode(grouping_id(tryb, stopien, kierunek, rok), 0, 'TSK', 1, 'TS', 3, 'T', 7, 'w danym trybie', 15, 'ogolem')komentarz,
tryb, stopien, kierunek, rok, count(*) from Studenci
group by rollup (tryb, stopien, kierunek, rok);


