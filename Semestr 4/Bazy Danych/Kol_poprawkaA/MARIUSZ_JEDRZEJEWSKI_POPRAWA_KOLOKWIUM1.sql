--MARIUSZ JÊDRZEJEWSKI
--NR ALBUMU 128059
--GR LAB 3 POPRAWA
--KOLOKWIUM POPRAWKOWE A

--1.1
SELECT * FROM studenci
WHERE imiona LIKE '%na%' AND LENGTH(nazwisko) IN (5, 6, 8, 9);



--1.2
SELECT * FROM studenci WHERE kierunek='INFORMATYKA'
AND trim(to_char(data_urodzenia, 'day')) in ('wtorek');



--1.3
SELECT imiona, nazwisko, dod_funkcyjny, placa FROM pracownicy
WHERE 
dod_funkcyjny IS NULL AND (placa<3500)
OR 
dod_funkcyjny IS NULL AND (placa>5500)
ORDER BY placa;



--2.1
SELECT * FROM studenci
WHERE extract(MONTH FROM data_urodzenia) = extract(MONTH FROM sysdate)
AND extract(DAY FROM data_urodzenia) = extract(DAY FROM sysdate)
AND MOD(extract(YEAR FROM sysdate) - extract(YEAR FROM data_urodzenia), 2)!=0;



--2.2
SELECT TO_CHAR(sysdate - (interval '12-0' YEAR(2) TO MONTH), 'day') AS Dzien_12Y_Temu,
systimestamp + (interval '12-10' YEAR(2) TO MONTH) + (interval '0 15:00:00' DAY(1) TO second) AS Data_za_12Y_10M_15H
FROM dual;



--2.3
SELECT id_gatunku, nazwa FROM rejestry JOIN gatunki USING(id_gatunku)
GROUP BY id_gatunku, nazwa
HAVING MIN(dlugosc)>=40 AND MAX(dlugosc)<=60
ORDER BY id_gatunku;



--2.4
SELECT nr_akt, nazwisko, imiona,
CASE when data_zwol is NULL then 'stala'
     when data_zwol > sysdate AND data_zwol is NOT NULL then 'okresowa'
     when data_zwol < sysdate AND data_zwol is NOT NULL then 'zakoczona'
END as umowa,
data_zatr, data_zwol FROM pracownicy
ORDER BY umowa;



--3.2
SELECT nazwisko, imiona, COUNT(*) Liczba_studentow FROM studenci 
WHERE stopien=1 AND tryb='STACJONARNY'
GROUP BY nazwisko, imiona HAVING COUNT(*)>1
ORDER BY Liczba_studentow DESC, nazwisko, imiona;



--4.1
SELECT * FROM pojazdy JOIN kierowcy ON (id_kierowcy=wlasciciel) WHERE 
data_prod=
(
  SELECT MIN(data_prod) FROM pojazdy WHERE kolor='czerwony'
  AND data_prod > to_date('01.01.2001', 'DD.MM.YYYY')
);


--4.2
SELECT zad.kierunek, zad.stopien, zad.data_urodzenia, zad.nazwisko, zad.imiona FROM studenci zad 
JOIN(SELECT kierunek, stopien, MAX(data_urodzenia) AS Najmlodszy FROM studenci 
WHERE tryb='STACJONARNY' GROUP BY kierunek, stopien) label ON (zad.data_urodzenia = Najmlodszy) ORDER BY kierunek, stopien;
