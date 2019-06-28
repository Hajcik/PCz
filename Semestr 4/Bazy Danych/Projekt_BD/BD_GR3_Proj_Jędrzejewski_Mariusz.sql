set serveroutput on;


-- MUSIALEM WYKOMENTOWAC TRIGGER'Y BO NIE MOZNA OPEROWAC NA KODZIE
-- W NORMALNY SPOSÓB, CALY CZAS NATRAFIA NA UTWORZONE TABELE 
-- I NIC NIE MOGE ZROBIC, NAWET ZAZNACZAJAC KOD INDYWIDUALNIE
-- DO KOMPILOWANIA
-- NAWET WYLACZENIE ICH ZA POMOCA ALTER TRIGGER ... DISABLE;
-- NIC NIE POMAGA, NIE WIEM CO Z TYM ZROBIÆ





--WYZWALACZ / TRIGGER [1]
--Usuwa te skocznie ktore nie maja zarejestrowanego
--rekordzisty
--CREATE OR REPLACE TRIGGER usun_skocznie_BRAK_REK
--AFTER INSERT OR DELETE ON Skocznie
--FOR EACH ROW
--BEGIN
--    delete from Skocznie WHERE id_rekordzisty IS NULL;
--END;

--Po utworzeniu tabel prosze o wrzucenie insertów.
--Potem wykonanie ALTER'ów oraz UPDATE'ów.
--Potem utworzyæ perspektywy (VIEWS).

--WYZWALACZ / TRIGGER [2]
-- usuwa z listy skoczków
-- zawodników Francuskich
--CREATE OR REPLACE TRIGGER skoczkowie_DELETE_FRANCJA
--AFTER INSERT OR UPDATE ON Skoczkowie
--FOR EACH ROW
--BEGIN
--    DELETE FROM Skoczkowie WHERE narodowosc = 'FRANCJA';
--END;

--WYZWALACZ / TRIGGER [3] ktory usuwa z listy trenerów
-- tych trenerów, którzy maja wiêcej niz 30 lat.
--CREATE OR REPLACE TRIGGER trenerzy_max30
--AFTER INSERT OR UPDATE ON Trenerzy
--FOR EACH ROW
--BEGIN
--    DELETE FROM Trenerzy WHERE 
--        extract(YEAR from SYSDATE) - extract(YEAR from data_urodzenia) <= 30;
--END;

ALTER TRIGGER usun_skocznie_BRAK_REK DISABLE;
ALTER TRIGGER skoczkowie_delete_FRANCJA DISABLE;
ALTER TRIGGER trenerzy_max30 DISABLE;



create table Reprezentacje
(
    id_reprezentacji        NUMBER(3) CONSTRAINT id_reprezentacji_pk PRIMARY KEY,
    nazwa_kraju             VARCHAR(30) constraint rep_nazwa_kraju_unique UNIQUE
);

create table Skoczkowie
(
    id_skoczka              NUMBER(3) CONSTRAINT id_skoczka_pk PRIMARY KEY,
    imie                    VARCHAR(40) CONSTRAINT Skoczkowie_imie_notnull NOT NULL,
    nazwisko                VARCHAR(40) CONSTRAINT Skoczkowie_nazwisko_notnull NOT NULL,
    data_urodzenia          DATE CONSTRAINT Skoczkowie_du_check 
                            CHECK(data_urodzenia >= to_date('1960.01.01', 'YYYY.MM.DD')),
    narodowosc              VARCHAR(30),
    CONSTRAINT              Skoczkowie_Reprezentacje FOREIGN KEY (narodowosc) REFERENCES Reprezentacje (nazwa_kraju) 
);

create table Trenerzy
(
    id_trenera              NUMBER(3) CONSTRAINT id_trenera_pk PRIMARY KEY,
    imie                    VARCHAR(40) CONSTRAINT Trenerzy_imie_notnull NOT NULL,
    nazwisko                VARCHAR(40) CONSTRAINT Trenerzy_nazwisko_notnull NOT NULL,
    data_urodzenia          DATE CONSTRAINT Trenerzy_data_urodzenia_check 
                            CHECK(data_urodzenia >= to_date('1940.01.01', 'YYYY.MM.DD')),
    narodowosc              VARCHAR(30),
    CONSTRAINT              Trenerzy_Reprezentacje FOREIGN KEY (narodowosc) REFERENCES Reprezentacje (nazwa_kraju)
    --narodowosc w sensie reprezentacji która reprezentuje!!!
);

create table Skocznie
(
    id_skoczni             NUMBER(3) CONSTRAINT Skocznie_id_primarykey PRIMARY KEY,
    nazwa                   VARCHAR(50) CONSTRAINT Skocznie_nazwa_notnull NOT NULL,
    miejscowosc             VARCHAR(40) CONSTRAINT Skocznie_miejscowosc_notnull NOT NULL,
    panstwo                 VARCHAR(30) CONSTRAINT Skocznie_panstwo_notnull NOT NULL,
    punkt_konstrukcyjny     FLOAT(53),
    rekord_skoczni          FLOAT(53),
    id_rekordzisty          NUMBER(3),
    CONSTRAINT              rekord_skoczni_p FOREIGN KEY (id_rekordzisty) REFERENCES Skoczkowie (id_skoczka) 
);

create table Zawody_rodzaj -- typ zawodow
(
    id_rodzaj               NUMBER(2) CONSTRAINT id_rodzaj_primarykey PRIMARY KEY,
    nazwa                   VARCHAR(45) CONSTRAINT typ_nazwa_notnull NOT NULL
);

create table Zawody
(
    id_zawodow              NUMBER(2) CONSTRAINT zawody_id_primarykey PRIMARY KEY,
    nazwa                   VARCHAR(45) CONSTRAINT zawody_nazwa_notnull NOT NULL,
    data_rozpoczecia        DATE,
    data_zakonczenia        DATE,
    id_rodzaj               NUMBER(2) CONSTRAINT zawody_id_rodzaj_notnull NOT NULL,
    CONSTRAINT              zawody_id_rodzaj FOREIGN KEY (id_rodzaj) REFERENCES Zawody_rodzaj (id_rodzaj)
);

create table Skoki
(   -- id_skoki odpowiada za Zawody.id_zawodow
    id_skoki                NUMBER(2),
    id_skoczka_skok         NUMBER(3),
    skok_1                  FLOAT(53),
    wiatr_1                 FLOAT(53),
    skok_2                  FLOAT(53),
    wiatr_2                 FLOAT(53),
    punkty_razem            FLOAT(53),
    CONSTRAINT              id_zawody FOREIGN KEY (id_skoki) REFERENCES Zawody (id_zawodow),
    CONSTRAINT              id_skoczka FOREIGN KEY (id_skoczka_skok) REFERENCES Skoczkowie (id_skoczka)
);

-------------------------
--MODYFIKACJE TABEL (ALTER), AKTUALIZACJE TABEL (UPDATE), USUWANIE ZAWARTOSCI (DELETE)
--Dodanie roku powstania do tabeli Skocznie.
ALTER TABLE Skocznie ADD Rok_powstania NUMBER(4);
UPDATE Skocznie SET Rok_powstania = 1950 WHERE id_skoczni = 1;
UPDATE Skocznie SET Rok_powstania = 1925 WHERE id_skoczni = 24;
UPDATE Skocznie SET Rok_powstania = 2004 WHERE id_skoczni = 31;
UPDATE Skocznie SET Rok_powstania = 1990 WHERE id_skoczni = 34;
--Polecenie SQL [6]
--Pokaz te skocznie ktore maja w swoich informacjach rok powstania, i powstaly po roku 1940.
SELECT * from Skocznie WHERE Rok_powstania > 1940;

--Dodanie zajêtego miejsca przez skoczka w danych zawodach.
ALTER TABLE Skoki ADD Miejsce NUMBER(2);
UPDATE Skoki SET Miejsce = 1 WHERE id_skoki = 5 AND id_skoczka_skok = 140;
UPDATE Skoki SET Miejsce = 2 WHERE id_skoki = 5 AND id_skoczka_skok = 112;
UPDATE Skoki SET Miejsce = 3 WHERE id_skoki = 5 AND id_skoczka_skok = 174;
UPDATE Skoki SET Miejsce = 1 WHERE id_skoki = 20 AND id_skoczka_skok = 101;
UPDATE Skoki SET Miejsce = 2 WHERE id_skoki = 20 AND id_skoczka_skok = 121;
UPDATE Skoki SET Miejsce = 3 WHERE id_skoki = 20 AND id_skoczka_skok = 174;
UPDATE Skoki SET Miejsce = 5 WHERE id_skoki = 4 AND id_skoczka_skok = 113;
UPDATE Skoki SET Miejsce = 6 WHERE id_skoki = 30 AND id_skoczka_skok = 127;
UPDATE Skoki SET Miejsce = 1 WHERE id_skoki = 4 AND id_skoczka_skok = 101;

----------PERSPEKTYWY
--PERSPEKTYWA [1]
--Stworz perspektywe w ktorej zdefiniowane jest ile
--zawodow danego typu sie odbylo lub ma sie odbyc.
CREATE OR REPLACE VIEW Zawody_w_skokach AS
SELECT zawody_rodzaj.nazwa, count(*) as "ILOSC ZAWODOW TEGO TYPU" FROM zawody_rodzaj
INNER JOIN zawody ON zawody_rodzaj.id_rodzaj = zawody.id_rodzaj
GROUP BY zawody_rodzaj.nazwa;

--PERSPEKTYWA [2]
--Stworz perspektywe ktora pokaze skoczków posiadajacych w swoim dorobku
--rekordy skoczni, gdzie je ustanowili i ile on wynosi. 
--Jesli skoczek nie ma rekordu to nie jest tu wyswietlony.
CREATE OR REPLACE VIEW Rekordzisci_skoczni AS
SELECT id_skoczka, imie, nazwisko, narodowosc, rekord_skoczni, nazwa FROM Skoczkowie 
INNER JOIN skocznie ON skoczkowie.id_skoczka = skocznie.id_rekordzisty;

--PERSPEKTYWA [3]
--Stworz perspektywe ktora wyswietla kraje ktore posiadaja
--chociaz jednego zawodnika w reprezentacji narodowej oraz rezultat
--jest posortowany malejaco wzgledem ilosci skoczkow.
CREATE OR REPLACE VIEW Ilosc_skoczkow_reprezentacji AS
SELECT narodowosc, count(*) as "ILOSC SKOCZKOW W TYM KRAJU" FROM Skoczkowie
INNER JOIN Reprezentacje ON Skoczkowie.narodowosc = Reprezentacje.nazwa_kraju
GROUP BY Skoczkowie.narodowosc
ORDER BY 2 DESC;

--PERSPEKTYWA [4]
--Stwórz perspektywê która wyœwietli nazwy zawodów dot. skoków narciarskich w taki sposób,
--¿e wyniki skoczków przekracza³y lub wynosi³y 275 punktów, ale nie wynosi³y wiêcej lub nie by³y równe 300 punktów,
--te wyniki nie dawa³y zawodnikom podium (czyli miejsc 1, 2 lub 3), 
--a punkty za wiatr (zsumowane) odejmowa³y od wyniku (by³y ujemne) 
--lub by³y wiêksze lub równe 10 punktów na plusie

CREATE OR REPLACE VIEW  ZAWODY_Z_WARUNKAMI AS
SELECT nazwa ZAWODY, id_skoczka_skok "ID SKOCZKA", imie, nazwisko, wiatr_1+wiatr_2 WIATR_OGOLEM, punkty_razem WYNIK, Miejsce from Skoki s 
left join Zawody z on (z.id_zawodow = s.id_skoki)
left join Skoczkowie m on (m.id_skoczka = s.id_skoczka_skok)
where (s.punkty_razem between 275 and 300)
and (s.miejsce > 3) and 
(s.wiatr_1+s.wiatr_2 < 0 or s.wiatr_1+s.wiatr_2 > 10) and (s.wiatr_1+s.wiatr_2 < 0 or s.wiatr_1+s.wiatr_2 > 10);


-------------------------------------------
--USUNIÊCIE TABEL / PERSPEKTYW / WYZWALACZY
drop table Zawody CASCADE constraints;
drop table Zawody_rodzaj CASCADE constraints;
drop table Skocznie CASCADE constraints;
drop table Skoczkowie CASCADE constraints;
drop table Trenerzy CASCADE constraints;
drop table Reprezentacje CASCADE constraints;
drop table Skoki CASCADE constraints;

DROP VIEW Zawody_w_skokach;
DROP VIEW Rekordzisci_skoczni;
DROP VIEW Ilosc_skoczkow_reprezentacji;
DROP VIEW ZAWODY_Z_WARUNKAMI;

DROP TRIGGER usun_skocznie_BRAK_REK;
DROP TRIGGER skoczkowie_DELETE_FRANCJA;
DROP TRIGGER trenerzy_max30;
--------------------------------------------
select * from Skoczkowie;
select * from Trenerzy;
select * from Skocznie;
select * from Reprezentacje;
select * from Zawody_rodzaj;
select * from Zawody;
select * from Skoki;

--ZAPYTANIE SQL [1]
--Za pomoca odpowiedniego polecenia SELECT pogrupuj ilosc skoczków z ka¿dego pañstwa
--posortowane krajami alfabetycznie od Z do A.

SELECT narodowosc, COUNT(*) AS "Ilosc zawodnikow"
FROM Skoczkowie
GROUP BY narodowosc ORDER BY 1 desc;

--ZAPYTANIE SQL [2]
--Za pomoca polecenia SELECT pokaz rodzaje zawodów które 
--swoja nazwê koncza na liczbie naturalnej.
select nazwa from Zawody_rodzaj WHERE
   nazwa LIKE '%0' OR nazwa LIKE '%1' 
OR nazwa LIKE '%2' OR nazwa LIKE '%3' 
OR nazwa LIKE '%4' OR nazwa LIKE '%5' 
OR nazwa LIKE '%6' OR nazwa LIKE '%7' 
OR nazwa like '%8' OR nazwa LIKE '%9';

--ZAPYTANIE SQL [3]
--Za pomoca polecenia SELECT wyswietl kraje 
--posiadajace minimum 2 skocznie narciarskie,
--posortuj wynik od najwiekszej ilosci skoczni do najmniejszej.
SELECT panstwo, count(*) as "ILOSC SKOCZNI" FROM Skocznie 
INNER JOIN Reprezentacje ON skocznie.panstwo = reprezentacje.nazwa_kraju 
GROUP BY skocznie.panstwo
HAVING count(*)>=2
ORDER BY count(*) DESC;

--ZAPYTANIE SQL [4]
--Za pomoca polecenia SELECT wyswietl te skocznie
--majace ustalony rekord skoczni ale informacji na temat
--rekordzisty nie sa zarejestrowane w tej bazie danych
--oraz te skocznie ktore NIE maja rekordu skoczni.
SELECT * from Skocznie WHERE id_rekordzisty IS NULL;

--Samo id_rekordzisty zalatwia sprawe, bo skoro nie bylo rekordzisty skoczni,
--to nie ma takze rekordu_skoczni! ;)

--ZAPYTANIE SQL [5]
--Za pomoca polecenia SELECT wyswietl z naszej bazy danych
--informacje na temat NAJMLODSZEGO oraz na temat NAJSTARSZEGO
--skoczka narciarskiego.
SELECT zad.id_skoczka, zad.imie, zad.nazwisko, zad.data_urodzenia, zad.narodowosc FROM Skoczkowie
zad JOIN
(
    SELECT MAX(data_urodzenia) AS NAJMLODSZY, 
           MIN(data_urodzenia) AS NAJSTARSZY
           from Skoczkowie
) 
oznaczenie ON (zad.data_urodzenia = NAJMLODSZY OR zad.data_urodzenia = NAJSTARSZY);

--ZAPYTANIE SQL [6]
--Wyswietl skoczków ktorzy posiadaja chocia¿ jeden rekord skoczni,
--chocia¿ raz znaleŸli siê w czolowce zawodów (1-3) a ich wiek znajduje siê
--pomiêdzy 28 a 34 lata.
SELECT DISTINCT id_rekordzisty, imie, nazwisko, narodowosc, data_urodzenia, 
nazwa as "NAZWA SKOCZNI Z REKORDEM", rekord_skoczni, Miejsce as "MIEJSCE NA ZAWODACH" FROM Skoczkowie S 
LEFT JOIN Skocznie M ON (S.id_skoczka = M.id_rekordzisty) 
LEFT JOIN Skoki    T ON (T.id_skoczka_skok = S.id_skoczka) 
WHERE  T.Miejsce BETWEEN 1 AND 3
AND extract(YEAR from SYSDATE) - extract(YEAR from S.data_urodzenia) BETWEEN 28 AND 34;
--AND select S.id_skoczka from Skoki WHERE count(*) > 2;
--select * from Skoki where Miejsce BETWEEN 1 AND 2;

---------------------------------
--INSERTY                      --
---------------------------------
--REPREZENTACJE
INSERT INTO Reprezentacje VALUES(101, 'ARGENTYNA');
INSERT INTO Reprezentacje VALUES(102, 'AUSTRALIA');
INSERT INTO Reprezentacje VALUES(103, 'AUSTRIA');
INSERT INTO Reprezentacje VALUES(104, 'BIALORUS');
INSERT INTO Reprezentacje VALUES(105, 'BOSNIA I HERCEGOWINA');
INSERT INTO Reprezentacje VALUES(106, 'BULGARIA');
INSERT INTO Reprezentacje VALUES(107, 'CHINY');
INSERT INTO Reprezentacje VALUES(108, 'CHORWACJA');
INSERT INTO Reprezentacje VALUES(109, 'CZARNOGORA');
INSERT INTO Reprezentacje VALUES(110, 'CZECHY');
INSERT INTO Reprezentacje VALUES(111, 'DANIA');
INSERT INTO Reprezentacje VALUES(112, 'ESTONIA');
INSERT INTO Reprezentacje VALUES(113, 'FINLANDIA');
INSERT INTO Reprezentacje VALUES(114, 'FRANCJA');
INSERT INTO Reprezentacje VALUES(115, 'GRUZJA');
INSERT INTO Reprezentacje VALUES(116, 'HISZPANIA');
INSERT INTO Reprezentacje VALUES(117, 'HOLANDIA');
INSERT INTO Reprezentacje VALUES(118, 'ISLANDIA');
INSERT INTO Reprezentacje VALUES(119, 'JAPONIA');
INSERT INTO Reprezentacje VALUES(120, 'KANADA');
INSERT INTO Reprezentacje VALUES(121, 'KAZACHSTAN');
INSERT INTO Reprezentacje VALUES(122, 'KOREA POLUDNIOWA');
INSERT INTO Reprezentacje VALUES(123, 'LIECHTENSTEIN');
INSERT INTO Reprezentacje VALUES(124, 'LITWA');
INSERT INTO Reprezentacje VALUES(125, 'LOTWA');
INSERT INTO Reprezentacje VALUES(126, 'MACEDONIA POLNOCNA');
INSERT INTO Reprezentacje VALUES(127, 'NIEMCY');
INSERT INTO Reprezentacje VALUES(128, 'NORWEGIA');
INSERT INTO Reprezentacje VALUES(129, 'NOWA ZELANDIA');
INSERT INTO Reprezentacje VALUES(130, 'POLSKA');
INSERT INTO Reprezentacje VALUES(131, 'ROSJA');
INSERT INTO Reprezentacje VALUES(132, 'RUMUNIA');
INSERT INTO Reprezentacje VALUES(133, 'SERBIA');
INSERT INTO Reprezentacje VALUES(134, 'SLOWACJA');
INSERT INTO Reprezentacje VALUES(135, 'SLOWENIA');
INSERT INTO Reprezentacje VALUES(136, 'STANY ZJEDNOCZONE');
INSERT INTO Reprezentacje VALUES(137, 'SZWAJCARIA');
INSERT INTO Reprezentacje VALUES(138, 'SZWECJA');
INSERT INTO Reprezentacje VALUES(139, 'TURCJA');
INSERT INTO Reprezentacje VALUES(140, 'UKRAINA');
INSERT INTO Reprezentacje VALUES(141, 'WEGRY');
INSERT INTO Reprezentacje VALUES(142, 'WLOCHY');

--POLSKA 
INSERT INTO Trenerzy VALUES(10, 'MICHAL', 'DOLEZAL', '1978.03.11', 'POLSKA'); --Ten Trenerzy jest Czechem, chodzi o jaki kraj reprezentuje
INSERT INTO Skoczkowie VALUES(101, 'KAMIL', 'STOCH', '1987.05.25', 'POLSKA');
INSERT INTO Skoczkowie VALUES(102, 'ADAM', 'MALYSZ', '1977.12.03', 'POLSKA');
INSERT INTO Skoczkowie VALUES(103, 'STEFAN', 'HULA', '1986.09.29', 'POLSKA');
INSERT INTO Skoczkowie VALUES(104, 'MACIEJ', 'KOT', '1991.06.09', 'POLSKA');
INSERT INTO Skoczkowie VALUES(105, 'DAWID', 'KUBACKI', '1990.03.12', 'POLSKA');
INSERT INTO Skoczkowie VALUES(106, 'JAKUB', 'WOLNY', '1995.05.15', 'POLSKA');
INSERT INTO Skoczkowie VALUES(107, 'PIOTR', 'ZYLA', '1987.01.16', 'POLSKA');
INSERT INTO Skoczkowie VALUES(108, 'KLEMENS', 'MURANKA', '1994.08.31', 'POLSKA');
INSERT INTO Skoczkowie VALUES(109, 'JAKUB', 'KOT', '1990.01.19', 'POLSKA');

--NIEMCY
INSERT INTO Trenerzy VALUES(12, 'STEFAN', 'HORNGACHER', '1969.09.20', 'NIEMCY');
INSERT INTO Skoczkowie VALUES(110, 'ANDREAS', 'WELLINGER', '1995.08.28', 'NIEMCY');
INSERT INTO Skoczkowie VALUES(111, 'SEVERIN', 'FREUND', '1988.05.11', 'NIEMCY');
INSERT INTO Skoczkowie VALUES(112, 'MARKUS', 'EISENBICHLER', '1991.04.03', 'NIEMCY');
INSERT INTO Skoczkowie VALUES(113, 'RICHARD', 'FREITAG', '1991.08.14', 'NIEMCY');
INSERT INTO Skoczkowie VALUES(114, 'KARL', 'GEIGER', '1993.02.11', 'NIEMCY');
INSERT INTO Skoczkowie VALUES(115, 'STEPHAN', 'LEYHE', '1992.01.05', 'NIEMCY');
INSERT INTO Skoczkowie VALUES(116, 'DAVID', 'SIEGEL', '1996.08.28', 'NIEMCY');
INSERT INTO Skoczkowie VALUES(117, 'CONSTANTIN', 'SCHMID', '1999.11.27', 'NIEMCY');

--NORWEGIA
INSERT INTO Trenerzy VALUES(13, 'ALEXANDER', 'STOCKL', '1973.12.11', 'NORWEGIA'); --Ten Trenerzy jest Austriakiem
INSERT INTO Skoczkowie VALUES(120, 'ANDERS', 'FANNEMEL', '1991.05.13', 'NORWEGIA');
INSERT INTO Skoczkowie VALUES(121, 'JOHANN ANDRE', 'FORFANG', '1995.07.04', 'NORWEGIA');
INSERT INTO Skoczkowie VALUES(122, 'HALVOR EGNER', 'GRANERUD', '1996.05.29', 'NORWEGIA');
INSERT INTO Skoczkowie VALUES(123, 'ROBERT', 'JOHANSSON', '1990.03.23', 'NORWEGIA');
INSERT INTO Skoczkowie VALUES(124, 'MARIUS', 'LINDVIK', '1998.06.27', 'NORWEGIA');
INSERT INTO Skoczkowie VALUES(125, 'THOMAS AASEN', 'MARKENG', '2000.06.18', 'NORWEGIA');
INSERT INTO Skoczkowie VALUES(126, 'ROBIN', 'PEDERSEN', '1996.08.31', 'NORWEGIA');
INSERT INTO Skoczkowie VALUES(127, 'DANIEL-ANDRE', 'TANDE', '1994.01.21', 'NORWEGIA');

--FINLANDIA
INSERT INTO Trenerzy VALUES(15, 'LAURI', 'HAKOLA', '1979.12.13', 'FINLANDIA');
INSERT INTO Skoczkowie VALUES(130, 'JANNE', 'AHONEN', '1997.05.11', 'FINLANDIA');
INSERT INTO Skoczkowie VALUES(131, 'ANTTI', 'AALTO', '1995.04.02', 'FINLANDIA');
INSERT INTO Skoczkowie VALUES(132, 'MICO', 'AHONEN', '2001.11.27', 'FINLANDIA');
INSERT INTO Skoczkowie VALUES(133, 'ANDREAS', 'ALAMOMMO', '1998.12.23', 'FINLANDIA');
INSERT INTO Skoczkowie VALUES(134, 'JARKKO', 'MAATTA', '1994.12.28', 'FINLANDIA');
INSERT INTO Skoczkowie VALUES(135, 'EETU', 'NOUSIAINEN', '1997.04.29', 'FINLANDIA');

--JAPONIA
INSERT INTO Trenerzy VALUES(16, 'HIDEHARU', 'MIYAHIRA', '1973.12.21', 'JAPONIA');
INSERT INTO Skoczkowie VALUES(140, 'RYOYU', 'KOBAYASHI', '1996.11.08', 'JAPONIA');
INSERT INTO Skoczkowie VALUES(141, 'JUNSHIRO', 'KOBAYASHI', '1991.06.11', 'JAPONIA');
INSERT INTO Skoczkowie VALUES(142, 'YUKIYA', 'SATO', '1995.06.19', 'JAPONIA');
INSERT INTO Skoczkowie VALUES(143, 'NORIAKI', 'KASAI', '1972.06.06', 'JAPONIA');
INSERT INTO Skoczkowie VALUES(144, 'DAIKI', 'ITO', '1985.12.27', 'JAPONIA');
INSERT INTO Skoczkowie VALUES(145, 'YUMU', 'HARADA', '1990.09.15', 'JAPONIA');
INSERT INTO Skoczkowie VALUES(146, 'TAKU', 'TAKEUCHI', '1987.05.20', 'JAPONIA');
INSERT INTO Skoczkowie VALUES(147, 'KENSHIRO', 'ITO', '1990.01.08', 'JAPONIA');
INSERT INTO Skoczkowie VALUES(148, 'NAOKI', 'NAKAMURA', '1996.09.19', 'JAPONIA');

--CZECHY
INSERT INTO Trenerzy VALUES(17, 'DAVID', 'JIROUTEK', '1973.03.02', 'CZECHY');
INSERT INTO Skoczkowie VALUES(150, 'ROMAN', 'KOUDELKA', '1989.07.09', 'CZECHY');
INSERT INTO Skoczkowie VALUES(151, 'CESTMIR', 'KOZISEK', '1991.11.09', 'CZECHY');
INSERT INTO Skoczkowie VALUES(152, 'VIKTOR', 'POLASEK', '1997.07.18', 'CZECHY');
INSERT INTO Skoczkowie VALUES(153, 'FILIP', 'SAKALA', '1996.05.21', 'CZECHY');
INSERT INTO Skoczkowie VALUES(154, 'VOJTECH', 'STURSA', '1995.08.03', 'CZECHY');
INSERT INTO Skoczkowie VALUES(155, 'TOMAS', 'VANCURA', '1996.09.10', 'CZECHY');

--S£OWENIA
INSERT INTO Trenerzy VALUES(19, 'GORAN', 'JANUS', '1970.03.27', 'SLOWENIA');
INSERT INTO Skoczkowie VALUES(160, 'PETER', 'PREVC', '1992.09.20', 'SLOWENIA');
INSERT INTO Skoczkowie VALUES(161, 'JERNEJ', 'DAMJAN', '1983.05.28', 'SLOWENIA');
INSERT INTO Skoczkowie VALUES(162, 'ANZE', 'LANISEK', '1996.04.20', 'SLOWENIA');
INSERT INTO Skoczkowie VALUES(163, 'DOMEN', 'PREVC', '1999.06.04', 'SLOWENIA');
INSERT INTO Skoczkowie VALUES(164, 'ANZE', 'SEMENIC', '1993.08.01', 'SLOWENIA');
INSERT INTO Skoczkowie VALUES(165, 'TIMI', 'ZAJC', '2000.04.26', 'SLOWENIA');

--AUSTRIA
INSERT INTO Trenerzy VALUES(18, 'ANDREAS', 'FELDER', '1962.03.06', 'AUSTRIA');
INSERT INTO Skoczkowie VALUES(170, 'MICHAEL', 'HAYBOCK', '1991.03.05', 'AUSTRIA');
INSERT INTO Skoczkowie VALUES(171, 'CLEMENS', 'AIGNER', '1993.02.02', 'AUSTRIA');
INSERT INTO Skoczkowie VALUES(172, 'PHILIPP', 'ASCHENWALD', '1995.11.12', 'AUSTRIA');
INSERT INTO Skoczkowie VALUES(173, 'DANIEL', 'HUBER', '1993.01.02', 'AUSTRIA');
INSERT INTO Skoczkowie VALUES(174, 'STEFAN', 'KRAFT', '1993.05.13', 'AUSTRIA');
INSERT INTO Skoczkowie VALUES(175, 'MANUEL', 'FETNER', '1985.06.17', 'AUSTRIA');
INSERT INTO Skoczkowie VALUES(176, 'GREGOR', 'SCHLIERENZAUER', '1990.01.07', 'AUSTRIA');
INSERT INTO Skoczkowie VALUES(177, 'THOMAS', 'MORGENSTERN', '1986.10.30', 'AUSTRIA');
--FRANCJA
INSERT INTO Skoczkowie VALUES(180, 'MATHIS', 'CONTAMINE', '2001.09.14', 'FRANCJA');
INSERT INTO Skoczkowie VALUES(181, 'JONATHAN', 'LEAROYD', '2000.11.03', 'FRANCJA');

--KANADA
INSERT INTO Skoczkowie VALUES(190, 'MACKENZIE', 'BOYD-CLOWES', '1991.07.13', 'KANADA');
INSERT INTO Skoczkowie VALUES(191, 'DUSTY', 'KOREK', '1995.04.19', 'KANADA');
INSERT INTO Skoczkowie VALUES(192, 'JOSHUA', 'MAURER', '1996.09.20', 'KANADA');
INSERT INTO Skoczkowie VALUES(193, 'MATTHEW', 'SOUKUP', '1997.08.31', 'KANADA');

--KAZACHSTAN
INSERT INTO Skoczkowie VALUES(200, 'NIKITA', 'DIEWIATKIN', '1999.04.03', 'KAZACHSTAN');
INSERT INTO Skoczkowie VALUES(201, 'ALEKSIEJ', 'KOROLOW', '1987.06.20', 'KAZACHSTAN');
INSERT INTO Skoczkowie VALUES(202, 'GLEB', 'SAFONOW', '2001.09.11', 'KAZACHSTAN');
INSERT INTO Skoczkowie VALUES(203, 'SIERGIEJ', 'TKACZENKO', '1999.06.08', 'KAZACHSTAN');

--ROSJA
INSERT INTO Trenerzy VALUES(21, 'JEWGIENIJ', 'PLECHOW', '1982.12.15', 'ROSJA');
INSERT INTO Skoczkowie VALUES(210, 'ILMIR', 'CHAZIETDINOW', '1991.10.28', 'ROSJA');
INSERT INTO Skoczkowie VALUES(211, 'JEWGIENIJ', 'KLIMOW', '1994.02.03', 'ROSJA');
INSERT INTO Skoczkowie VALUES(212, 'DIENIS', 'KORNILOW', '1986.08.17', 'ROSJA');
INSERT INTO Skoczkowie VALUES(213, 'MICHAIL', 'MAKSIMOCZKIN', '1993.08.29', 'ROSJA');
INSERT INTO Skoczkowie VALUES(214, 'ROMAN', 'TROFIMOW', '1989.11.19', 'ROSJA');

--S£OWACJA
INSERT INTO Trenerzy VALUES(22, 'JAN', 'TANCZOS', '1955.11.20', 'SLOWACJA');

--STANY ZJEDNOCZONE
INSERT INTO Skoczkowie VALUES(220, 'KEVIN', 'BICKNER', '1996.09.23', 'STANY ZJEDNOCZONE');
INSERT INTO Skoczkowie VALUES(221, 'CASEY', 'LARSON', '1998.12.16', 'STANY ZJEDNOCZONE');
INSERT INTO Skoczkowie VALUES(222, 'PATRICK', 'GASIENICA', '1998.11.28', 'STANY ZJEDNOCZONE');

--SZWAJCARIA
INSERT INTO Trenerzy VALUES(23, 'RONNY', 'HORNSCHUH', '1975.02.02', 'SZWAJCARIA');
INSERT INTO Skoczkowie VALUES(230, 'SIMON', 'AMMANN', '1981.06.25', 'SZWAJCARIA');
INSERT INTO Skoczkowie VALUES(231, 'KILLIAN', 'PEIER', '1995.03.28', 'SZWAJCARIA');
INSERT INTO Skoczkowie VALUES(232, 'GREGOR', 'DESCHWANDEN', '1991.02.27', 'SZWAJCARIA');
INSERT INTO Skoczkowie VALUES(233, 'TOBIAS', 'BIRCHLER', '1997.07.29', 'SZWAJCARIA');

--UKRAINA
INSERT INTO Trenerzy VALUES(24, 'MYKOLA', 'KOZLOW', '1982.04.17', 'UKRAINA');
INSERT INTO Skoczkowie VALUES(240, 'WITALIJ', 'KALINICZENKO', '1993.08.09', 'UKRAINA');
INSERT INTO Skoczkowie VALUES(241, 'JEWHEN', 'MARUSIAK', '2000.03.16', 'UKRAINA');
INSERT INTO Skoczkowie VALUES(242, 'ANDRIJ', 'WASKUL', '1999.04.01', 'UKRAINA');

--W£OCHY
INSERT INTO Trenerzy VALUES(25, 'ANDREA', 'MORASSI', '1988.08.30', 'WLOCHY');
INSERT INTO Skoczkowie VALUES(250, 'ALEX', 'INSAM', '1997.12.19', 'WLOCHY');
INSERT INTO Skoczkowie VALUES(251, 'FEDERICO', 'CECON', '1994.06.11', 'WLOCHY');
INSERT INTO Skoczkowie VALUES(252, 'DANIELE', 'VARESCO', '1995.07.25', 'WLOCHY');

--ESTONIA
INSERT INTO Trenerzy VALUES(20, 'JAAN', 'JURIS', '1977.06.23', 'ESTONIA');
INSERT INTO Skoczkowie VALUES(260, 'MARTTI', 'NOMME', '1993.08.07', 'ESTONIA');
INSERT INTO Skoczkowie VALUES(261, 'TAAVI', 'PAPPEL', '1999.11.27', 'ESTONIA');
INSERT INTO Skoczkowie VALUES(262, 'KEVIN', 'MALTSEV', '2000.07.04', 'ESTONIA');
INSERT INTO Skoczkowie VALUES(263, 'ARTTI', 'AIGRO', '1999.08.29', 'ESTONIA');




------------------------
--SKOCZNIE
INSERT INTO Skocznie VALUES(1, 'KULM K200', 'TAUPLITZ', 'AUSTRIA', 200, 244.0, 160);
INSERT INTO Skocznie VALUES(2, 'BERGISEL K120', 'INNSBRUCK', 'AUSTRIA', 120, 138, 170);
INSERT INTO Skocznie VALUES(3, 'SEPP BRADL-SKISTADION K125', 'BISCHOFSHOFEN', 'AUSTRIA', 125, 145, 105);
INSERT INTO Skocznie VALUES(4, 'IGMAN K112', 'SARAJEWO', 'BOSNIA I HERCEGHOWINA', 112, 116, NULL);
INSERT INTO Skocznie VALUES(5, 'DRAGON HILL K125', 'YABULI', 'CHINY', 125, 138.5, NULL);
INSERT INTO Skocznie VALUES(6, 'JAPLENSKY VRH K70', 'DELNICE', 'CHORWACJA', 70, 72.5, NULL);
INSERT INTO Skocznie VALUES(7, 'CERTAK K185', 'HARRACHOV', 'CZECHY', 185, 214.5, 177);
INSERT INTO Skocznie VALUES(8, 'JESTED A K120', 'LIBEREC', 'CZECHY', 120, 139, 177);
INSERT INTO Skocznie VALUES(9, 'TEHVANDI K90', 'OTEPAA', 'ESTONIA', 90, 100, 174);
INSERT INTO Skocznie VALUES(10, 'MUSTAMAE K50', 'TALLINN', 'ESTONIA', 50, 59, NULL);
INSERT INTO Skocznie VALUES(11, 'SALPAUSSELKA K116', 'LAHTI', 'FINLANDIA', 116, 138, 121);
INSERT INTO Skocznie VALUES(12, 'TREMPLIN DU PRAZ K125', 'COURCHEVEL', 'FRANCJA', 125, 137, 101);
INSERT INTO Skocznie VALUES(13, 'LA COTE FEUILLEE K106', 'CHAUX-NEUVE', 'FRANCJA', 106, 120.5, NULL);
INSERT INTO Skocznie VALUES(14, 'SAKARTWELO K115', 'BAKURIANI', 'GRUZJA', 115, 115.5, NULL);
INSERT INTO Skocznie VALUES(15, 'OKURAYAMA K123', 'SAPPORO', 'JAPONIA', 123, 148.5, 101);
INSERT INTO Skocznie VALUES(16, 'MIYANOMORI K90', 'SAPPORO', 'JAPONIA', 90, 102, 102);
INSERT INTO Skocznie VALUES(17, 'HEINI-KLOPFER-SKIFLUGSCHANZE K200', 'OBERSTDORF', 'NIEMCY', 200, 238.5, 127);
INSERT INTO Skocznie VALUES(18, 'MUHLENKOPFSCHANZE K130', 'WILLINGEN', 'NIEMCY', 130, 152, 130);
INSERT INTO Skocznie VALUES(19, 'MIDTSTUBAKKEN K95', 'OSLO', 'NORWEGIA', 95, 110, 176);
INSERT INTO Skocznie VALUES(20, 'VIKERSUNDBAKKEN K200', 'VIKERSUND', 'NORWEGIA', 200, 253.5, 174);
INSERT INTO Skocznie VALUES(21, 'SNIEZYNKA K125', 'CZAJKOWSKIJ', 'ROSJA', 125, 147, NULL);
INSERT INTO Skocznie VALUES(22, 'LETALNICA K200', 'PLANICA', 'SLOWENIA', 200, 252, 140);
INSERT INTO Skocznie VALUES(23, 'BAUHENK K100', 'KRANJ', 'SLOWENIA', 100, 109, 160);
INSERT INTO Skocznie VALUES(24, 'SUICIDE HILL K90', 'ISHPEMING', 'STANY ZJEDNOCZONE', 90, 102, NULL);
INSERT INTO Skocznie VALUES(25, 'GROSS-TITLIS-SCHANZE K125', 'ENGELBERG', 'SZWAJCARIA', 125, 144, 140);
INSERT INTO Skocznie VALUES(26, 'LUGNET K120', 'FALUN', 'SZWECJA', 120, 135.5, 111);
INSERT INTO Skocznie VALUES(27, 'PARADISKULLEN K90', 'ORNSKOLDSVIK', 'SZWECJA', 90, 102, NULL);
INSERT INTO Skocznie VALUES(28, 'TRAMPOLINO DAL BEN K120', 'PREDAZZO', 'WLOCHY', 120, 136, 102);
INSERT INTO Skocznie VALUES(29, 'KRUCZA SKALA W LUBAWCE K85', 'LUBAWKA', 'POLSKA', 85, 96, 109);
INSERT INTO Skocznie VALUES(30, 'WIELKA KROKIEW IM. STANISLAWA MARUSARZA K125', 'ZAKOPANE', 'POLSKA', 125, 143.5, 105);
INSERT INTO Skocznie VALUES(31, 'ARAIYAMA K55', 'SAPPORO', 'JAPONIA', 55, 58.5, NULL);
INSERT INTO Skocznie VALUES(32, 'BOYODAI K80', 'OTARU', 'JAPONIA', 80, NULL, NULL);
INSERT INTO Skocznie VALUES(33, 'HANNIBALBAKKEN K80', 'KONGSBERG', 'NORWEGIA', 80, 88.5, NULL);
INSERT INTO Skocznie VALUES(34, 'GRANASEN K124', 'TRONDHEIM', 'NORWEGIA', 124, 148.5, 112);
-------------------------
--RODZAJE ZAWODOW
INSERT INTO Zawody_rodzaj VALUES(1, 'TURNIEJ CZTERECH SKOCZNI');
INSERT INTO Zawody_rodzaj VALUES(2, 'MISTRZOSTWA SWIATA');
INSERT INTO Zawody_rodzaj VALUES(3, 'MISTRZOSTWA SWIATA W LOTACH');
INSERT INTO Zawody_rodzaj VALUES(4, 'PUCHAR SWIATA W LOTACH');
INSERT INTO Zawody_rodzaj VALUES(5, 'RAW AIR');
INSERT INTO Zawody_rodzaj VALUES(6, 'PLANICA7');
INSERT INTO Zawody_rodzaj VALUES(7, 'WILLINGEN5');

-------------------------
--ZAWODY
INSERT INTO Zawody VALUES(1, '63. TURNIEJ CZTERECH SKOCZNI', '2014.12.27', '2015.01.06', 1);
INSERT INTO Zawody VALUES(2, '64. TURNIEJ CZTERECH SKOCZNI', '2015.12.28', '2016.01.06', 1);
INSERT INTO Zawody VALUES(3, '65. TURNIEJ CZTERECH SKOCZNI', '2016.12.29', '2017.01.06', 1);
INSERT INTO Zawody VALUES(4, '66. TURNIEJ CZTERECH SKOCZNI', '2017.12.29', '2018.01.06', 1);
INSERT INTO Zawody VALUES(5, '67. TURNIEJ CZTERECH SKOCZNI', '2015.12.28', '2016.01.06', 1);

INSERT INTO Zawody VALUES(10, 'MISTRZOSTWA SWIATA 2011', '2011.02.25', '2011.03.05', 3);
INSERT INTO Zawody VALUES(11, 'MISTRZOSTWA SWIATA 2013', '2013.02.21', '2011.03.02', 3);
INSERT INTO Zawody VALUES(12, 'MISTRZOSTWA SWIATA 2015', '2015.02.19', '2011.03.28', 3);
INSERT INTO Zawody VALUES(13, 'MISTRZOSTWA SWIATA 2017', '2017.02.23', '2011.03.04', 3);

INSERT INTO Zawody VALUES(20, 'PLANICA 7 (2018)', '2018.03.22', '2018.03.25', 6);
INSERT INTO Zawody VALUES(21, 'PLANICA 7 (2019)', '2019.03.21', '2019.03.24', 6);

INSERT INTO Zawody VALUES(30, 'WILLINGEN FIVE 2018', '2018.02.02', '2018.02.04', 7);
INSERT INTO Zawody VALUES(31, 'WILLINGEN FIVE 2019', '2019.02.15', '2019.02.17', 7);

INSERT INTO Zawody VALUES(40, 'PUCHAR SWIATA 2016/2017', '2016.11.25', '2017.03.26', 4);
INSERT INTO Zawody VALUES(41, 'PUCHAR SWIATA 2017/2018', '2017.11.18', '2018.03.25', 4);
INSERT INTO Zawody VALUES(42, 'PUCHAR SWIATA 2018/2019', '2018.11.17', '2019.03.24', 4);
INSERT INTO Zawody VALUES(43, 'PUCHAR SWIATA 2019/2020', '2019.11.23', '2020.03.15', 4);

INSERT INTO Zawody VALUES(51, 'RAW AIR 2017', '2017.03.10', '2017.03.19', 5);

select * from skoki;
--------------
--SKOKI 
--66 TURNIEJ CZTERECH SKOCZNI
INSERT INTO Skoki VALUES(4, 101, 126.0, 6.3, 137.0, 1.0, 279.7);
INSERT INTO Skoki VALUES(4, 113, 128.5, 4.4, 127.0, 13.2, 275.0);
INSERT INTO Skoki VALUES(4, 105, 126.5, 5.5, 129.0, 7.2, 270.1);


--67 TURNIEJ CZTERECH SKOCZNI
INSERT INTO Skoki VALUES(5, 140, 138.5, 0.01, 126.5, -0.72, 282.3);
INSERT INTO Skoki VALUES(5, 112, 133.0, -0.54, 129.0, -0.51, 281.9); 
INSERT INTO Skoki VALUES(5, 174, 131.0, 0.05, 134.5, -0.20, 280.5);
INSERT INTO Skoki VALUES(5, 105, 128.5, -0.23, 133.5, 0.35, 269.8);

--WILLINGEN FIVE 2018
INSERT INTO Skoki VALUES(30, 127, 148.0, 1.65, 146.5, 1.15, 261.3);
INSERT INTO Skoki VALUES(30, 113, 149.5, 1.41, 141.5, 0.80, 260.5);
INSERT INTO Skoki VALUES(30, 105, 145.0, 1.33, 139.5, 0.53, 254.8);

--PLANICA 7 (2018) 
INSERT INTO Skoki VALUES(20, 101, 245.0, -0.1, 234.0, 7.7, 455.9);
INSERT INTO Skoki VALUES(20, 121, 242.0, -1.9, 234.5, 10.3, 452.2);
INSERT INTO Skoki VALUES(20, 174, 238.0, -0.6, 234.5, 2.1, 443.0);
INSERT INTO Skoki VALUES(20, 123, 245.0, 0.0, 227.5, 6.3, 438.8);


select * from Skoki;

select id_zawodow, nazwa FROM Zawody Z LEFT JOIN Skoki S ON Z.id_zawodow = S.id_skoki order by id_zawodow;


--WYWZWALACZ / TRIGGER [2]
--Nie pozwala wprowadzaæ skoczków którzy maja wiecej
--niz 30 lat do rekordów w tabelach

--CREATE OR REPLACE TRIGGER OGRANICZ_WIEK 
--AFTER INSERT ON Skoczkowie
--FOR EACH ROW
--BEGIN
 --   DELETE FROM Skoczkowie WHERE extract(year from sysdate) - extract(year from data_urodzenia) <= 30;
--END;



