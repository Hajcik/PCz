select --zad 28 lista 3
extract(year from czas) rok,
id gatunku,
waga,
min(waga)keep(dense_rank first order by waga)over(partition by id_gatunku, extract(year from czas))"Min waga gatunku",
max(waga)keep(dense_rank first order by waga)over(partition by id_gatunku, extract(year from czas))"Max waga gatunku"
from rejestry
where id_gatunku is not null
order by 1;
--zad 1 lista 4
select * from pojazdy join kierowcy on(wlasciciel = id_kierowcy) where extract(year from data_prod) = 2018;

--zad 3 lista 4
select * from pracownicy;
select * from stanowiska;
select * from pracownicy join stanowiska using (stanowisko) where placa not between placa_min and placa_max;

--zad 5 lista 4
select trunc(czas), nazwisko, nvl(gatunku.nazwa, 'Brak polowu')
from rejestry join wedkarze using (id_wedkarza) left join gatunki using (id_gatunku)
join lowiska using (id_lowiska)
where czas >= sysdate - interval '1' year;

--zad 9 lista 4
select p.id_dzialu, p.nr_akt, p.nazwisko, p.placa, p1.id_dzialu, p1.nr_akt, p1.nazwisko, p1.placa from pracownicy p cross join pracownicy p1
where p.id_dzialu=20 and p1.id_dzialu=30;

--zad 12 lista 4
select tryb, kierunek, count(kierunek) from studenci
group by kierunek, tryb
having count(kierunek)>=100;

--zad 15 lista 4
select extract(year from czas), to char(czas, 'day'),
count(*), count(id_gatunku)
from rejestry where mod(extract(day from czas), 2) = 0
group by extract(year from czas), to char(czas, 'day') order by 3 desc, 4 desc;

--zad 22 lista 4
select id_lowiska, nazwa, count(*)"Liczba polowow", count(id_gatunku)"Liczba ryb",
count(distinct id_wedkarza)"liczba wedkarzy" from rejestry natural join lowiska l
where czas between timestamp '2016-03-11 15:15:00' and timestamp '2016-03-11 15:15:00' + interval'2'year + interval'21 21:21:21' day(2)
to second group by id_lowiska, nazwa having count(*)>4 and count(*)-count(id_gatunku)>=2;