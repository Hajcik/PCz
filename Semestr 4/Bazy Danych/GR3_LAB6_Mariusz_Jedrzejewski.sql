--zad 1
select czas, dlugosc, 'Ponizej sredniej' from rejestry
where id_gatunku = 10 and dlugosc < 58
union select czas, dlugosc, 'Rowna sredniej' from rejestry
where id_gatunku = 10 and dlugosc = 58
union select czas, dlugosc, 'Powyzej sredniej' from rejestry
where id_gatunku = 10 and dlugosc > 58;
--zad 3
select tab.id_gatunku, tab.nazwa, count(rs.id_gatunku) from rejestry rs
right join ( 
select id_gatunku, nazwa from gatunki
minus
select id_gatunku, nazwa from gatunki left join rejestry using(id_gatunku)
group by id_gatunku, nazwa
having count(id_gatunku)>5) tab on (rs.id_gatunku = tab.id_gatunku)
group by tab.id_gatunku, tab.nazwa;
--zad 8
select ROK, round(avg(suma),2) "Srednia waga", 'Srednia waga' from 
(
select extract(year from czas) ROK, id_wedkarza, sum(waga) suma from rejestry
group by extract(year from czas), id_wedkarza
) group by rok
union
select ROK, max(suma) max_waga, 'Max waga' from 
(
select extract(year from czas) ROK, id_wedkarza, sum(waga) suma from rejestry
group by extract(year from czas), id_wedkarza
) group by rok;
-- zad 12
select re.id_wedkarza, nazwisko,
case
(
select count(czas) from rejestry join lowiska using (id_lowiska)
where id_wedkarza = re.id_wedkarza and id_okregu = 'PZW Czestochowa'
)
when 0 then 'NIE'
else 'TAK'
end "Inne",
( select count(czas) from rejestry join lowiska using (id_lowiska)
  where id_wedkarza = re.id_wedkarza and id_okregu = 'PZW Czestochowa'
) as "Polowow CZ",

case
(
select count(czas) from rejestry join lowiska using (id_lowiska)
where id_wedkarza = re.id_wedkarza and (id_okregu is null or id_okregu not like 'PZW%')
)
when 0 then 'NIE'
else 'TAK'
end "Inne",
( select count(czas) from rejestry join lowiska using (id_lowiska)
  where id_wedkarza = re.id_wedkarza and (id_okregu is null or id_okregu not like 'PZW%')
) as "Polowow inne"

from rejestry re join wedkarze we on (re.id_wedkarza = we.id_wedkarza) join lowiska using (id_lowiska)
group by re.id_wedkarza, nazwisko;
--zad 14
select * from gatunki;
select g1.nazwa, g1.wymiar,
case 
when g1.wymiar < g2.wymiar then 'mniejszy'
when g1.wymiar > g2.wymiar then 'wiekszy'
else 'rowny'
end Komentarz,
g2.nazwa, g2.wymiar, abs(g1.wymiar - g2.wymiar) Roznica from gatunki g1 cross join gatunki g2
where g1.dpo is not null and g2.dpo is not null and abs(g1.wymiar - g2.wymiar) <= 10;

