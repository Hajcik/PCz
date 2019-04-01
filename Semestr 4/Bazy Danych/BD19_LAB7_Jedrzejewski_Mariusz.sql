--zad 1
select * from wedkarze
where id_wedkarza = any (
select id_wedkarza from rejestry join gatunki using(id_gatunku)
where nazwa like 'SANDACZ');

--zad 3
select stanowisko, placa_min, placa_max, staz_min, dod_funkcyjny
from stanowiska s_zew
where placa_min <= all
(select placa from pracownicy where stanowisko = s_zew.stanowisko
and (data_zwol is null or data_zwol >= sysdate))and
placa_max>=all
(select placa from pracownicy where stanowisko = s_zew.stanowisko
and (data_zwol is null or data_zwol >= sysdate));

--zad 6
select id_okregu, GA.nazwa from lowiska LO cross join gatunki GA
where id_okregu like 'PZW%'
and Exists
(
select * from lowiska join rejestry using(id_lowiska)
join gatunki using(id_gatunku)
where id_okregu like 'PZW%' and gatunki.nazwa = GA.nazwa and id_okregu = LO.id_okregu
);

--zad 7
select distinct id_okregu, GA.nazwa from lowiska LO cross join gatunki GA
where id_okregu like 'PZW%'
and Exists
(
select gatunki.nazwa, id_okregu, extract(year from czas),
count(distinct id_wedkarza) from lowiska join rejestry using (id_lowiska)
join gatunki using(id_gatunku)
where id_okregu like 'PZW%' and gatunki.nazwa = GA.nazwa and id_okregu = LO.id_okregu
group by gatunki.nazwa, id_okregu, extract(year from czas) having count(*) >= 3
);

--zad 14
select nazwa, count(*), listagg(nazwisko, ',') within group(order by nazwisko)
from rejestry join gatunki using(id_gatunku) join wedkarze using(id_wedkarza)
group by nazwa;

--zad 15
select nazwa, sum(liczba), listagg(nazwisko||' '||litera||'('||liczba||')', ',') within group(order by liczba desc)
select nazwa, id_wedkarza, nazwisko, substr(imie, 1, 1)||'.' litera, count(*) liczba
from rejestry join gatunki using(id_gatunku) join wedkarze using(id_wedkarza)
group by nazwa, id_wedkarza, nazwisko, substr(imie, 1, 1)||'.';


