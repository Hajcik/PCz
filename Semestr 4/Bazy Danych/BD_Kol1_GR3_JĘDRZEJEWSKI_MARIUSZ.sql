-- Bazy danych Kolokwium 1
-- data: 15-04-2019
-- nazwisko imie: JÊDRZEJEWSKI MARIUSZ
-- numer indeksu: 128059



--******   CZESC I *************************
-- pozostaw wplasciwa odpowiedz TAK lub NIE;
-- pozostawienie TAK/NIE lub usuniecie obu opcji oznacza brak odpowiedzi (0 pkt.)
--A1: NIE
--A2: TAK/NIE
--A3: NIE
--A4: NIE

--B1: TAK/NIE
--B2: TAK/NIE
--B3: TAK/NIE
--B4: TAK/NIE

--C1: TAK/NIE
--C2: TAK/NIE
--C3: TAK/NIE
--C4: TAK/NIE

--D1
SELECT *
FROM Transakcje
RIGHT JOIN Produkty USING (ID_produktu);
--D2
SELECT * FROM ...;
--******  CZESC II  **********************
-- Maksymalnie 10 zadañ

--wybor 1
--ZAD 5.2
SELECT TRUNC(czas) AS "Czas polowu",
  id_lowiska       AS "Numer Lowiska",
  lowiska.nazwa    AS "Nazwa Lowiska",
  id_gatunku       AS "Numer gatunku (ID)",
  dlugosc          AS "Dlugosc ryb"
FROM rejestry
JOIN lowiska USING (id_lowiska)
JOIN gatunki USING (id_gatunku)
WHERE id_okregu LIKE 'PZW Czestochowa'
AND (id_gatunku,id_lowiska,dlugosc) IN
  (
  SELECT id_gatunku,
    id_lowiska,
    MAX (dlugosc)
  FROM Rejestry
  JOIN lowiska USING (id_lowiska)
  WHERE id_okregu LIKE 'PZW Czestochowa'
  GROUP BY id_gatunku,
    id_lowiska
  HAVING COUNT(id_gatunku)>5
  )
ORDER BY 1;

--wybor 2
--ZAD 1.1
SELECT *
FROM Studenci
WHERE imiona LIKE '%a'
AND stopien LIKE '2';

--wybor 3
--ZAD 4.1
SELECT typ,
  kolor,
  data_prod,
  nazwisko,
  imie,
  data_urodzenia
FROM Pojazdy
JOIN Kierowcy
ON( wlasciciel = id_kierowcy)
WHERE typ LIKE 'samochod osobowy'
AND kolor LIKE 'zielony'
AND data_prod =
  (SELECT MIN(data_prod)
  FROM Pojazdy
  WHERE typ LIKE 'samochod osobowy'
  AND kolor LIKE 'zielony'
  );
  
--wybor 4
--ZAD 2.6
SELECT nazwisko,
  dod_funkcyjny,
  dod_staz
FROM PRACOWNICY
WHERE dod_funkcyjny IS NULL
AND dod_staz        IS NOT NULL;

--wybor 5
--ZAD 5.1
SELECT id_wedkarza,
  nazwisko,
  COUNT (id_gatunku) AS Ilosc
FROM Rejestry
JOIN wedkarze USING (id_wedkarza)
GROUP BY id_wedkarza,
  nazwisko;
  
--wybor 6
--ZAD 2.1
SELECT MIN(data_urodzenia)                  AS "Najstarszy student",
  MAX(data_urodzenia)                       AS "Najmlodszy student",
  MAX(data_urodzenia) - MIN(data_urodzenia) AS "Ilosc dni pomiedzy urodzinami"
FROM Studenci
WHERE imiona NOT LIKE '%a'
AND rok = 1;

--wybor 7
--ZAD 3.5
SELECT *
FROM Studenci
WHERE LENGTH(nazwisko) IN (8)
ORDER BY nazwisko; -- having count(nazwisko)=3 OR 5;
--wybor 8

--ZAD 3.1
SELECT marka,
  COUNT(marka),
  COUNT(DISTINCT modell)
FROM Pojazdy
WHERE extract (YEAR FROM data_prod) > 2001
GROUP BY marka
ORDER BY 2 DESC;
--wybor 9
--ZAD ?.?


--wybor 10
--ZAD ?.?

