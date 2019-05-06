set serveroutput on;
-- 0 (nieobecny)/ 1 (obecny) ,  nr_indeksu  
--execute obecnosc(0,128063 );
-- pukty (+/-) , nr_indeksu; -> (null, null) wszyscy obecni
execute aktywnosc(1, 12);
-- nr_grupy
execute los(3);

--select * from BD2019 where gr_dziekan=1;
--select * from Plos3;

-- zad 1
create table Produkty (
  id_produktu number(3) constraint id_produktu_un unique,
  nazwa VARCHAR(20) constraint nazwa_n not null,
  stan number(6,2) default 0,
  cena number(6,2) default 0
);
--zad 2

create table Kasjerzy (
  id_kasjera number(4) constraint id_kasjera_g primary key,
  nazwisko varchar(20),
  data_zatrudnienia date constraint   data_zatrudnienia_n not null,
  placa number(7,2)  
);
--zad 3
create table Transakcje (
  id_transakcji number(6) CONSTRAINT id_transakcji_pk primary key,
  id_produktu number(3),
  id_sprzedawcy number(4),   
  miara number(6,2) default 1,
  czas_trasakcji timestamp,
  
  CONSTRAINT id_produktu_p foreign key (id_produktu) references Produkty (id_produktu),
  CONSTRAINT id_sprzedawcy_p foreign key (id_sprzedawcy) references Kasjerzy (id_kasjera)
);


--zad 4
Alter Table Kasjerzy modify (placa default 2500);
alter table TRansakcje modify(czas_trasakcji default systimestamp);
alter table Kasjerzy add constraint kasjrzey_id_kas_ch check(id_kasjera>=100);
alter table transakcje rename column czas_trasakcji TO czas_transakcji;

--d
alter table Transakcje Drop constraint id_produktu_p;
alter table Produkty Drop constraint id_produktu_un;
alter table Produkty Add constraint id_produktu_pk primary key(id_produktu);
alter table Transakcje add
CONSTRAINT id_produktu_p foreign key (id_produktu) references Produkty (id_produktu) on delete set null;
--e
alter table Transakcje Drop constraint id_sprzedawcy_p;
alter table Transakcje add 
CONSTRAINT id_sprzedawcy_p foreign key (id_sprzedawcy) references Kasjerzy (id_kasjera) on delete cascade;

-- f
alter table Kasjerzy rename column placa TO pensja;

--g
ALTER TABLE Kasjerzy ADD (data_urodzenia date constraint data_urodzenia_ch check(data_urodzenia >= 
to_date ('01.01.1960', 'DD.MM.YYYY')), data_zwolnienia date default null);

--h
ALTER TABLE Kasjerzy add constraint data_zwolnienia_ch
check(nvl(data_zwolnienia,data_urodzenia +1) > data_urodzenia and nvl(data_zwolnienia, data_zatrudnienia+1) > data_zatrudnienia);


INSERT INTO Produkty VALUES(1, 'cukier', 100, 2.95);
INSERT INTO Produkty VALUES(2, 'chleb', 50, 3.7);
INSERT INTO Produkty VALUES(3, 'jogurt', 20, 1.15);
INSERT INTO Produkty VALUES(4, 'schab', 6.5, 15.2);
INSERT INTO Produkty VALUES(5, 'piwo', 200, 3.1);
INSERT INTO Produkty VALUES(6, 'cukierki', 10, 23);
INSERT INTO Produkty VALUES(7, 'kurczak', 10, 12.35);
INSERT INTO Produkty VALUES(8, 'banan', 6.5, 5.20);
INSERT INTO Produkty VALUES(9, 'mydlo', 40, 2.5);
INSERT INTO Produkty VALUES(10, 'pomidory', 8.5, 8.5);
INSERT INTO Produkty VALUES(11, 'olej', 20, 6.95);
INSERT INTO Produkty VALUES(12, 'kisiel', 150, 1.15);
INSERT INTO Produkty VALUES(13, 'ciastka', 25, 4.80);
INSERT INTO Produkty VALUES(14, 'plyn do naczyn', 15, 8.20);
INSERT INTO Produkty VALUES(15, 'pieprz', 30, 3.15);


INSERT INTO Kasjerzy (id_kasjera, nazwisko, data_zatrudnienia, data_urodzenia) VALUES
(100, 'Kowalski', To_date('01-01-2010', 'DD-MM-YYYY'), To_date('11-03-1990', 'DD-MM-YYYY'));
INSERT INTO Kasjerzy (id_kasjera, nazwisko, data_zatrudnienia, data_urodzenia) VALUES
(101, 'Nowak', To_date('01-03-2012', 'DD-MM-YYYY'), To_date('21-10-1992', 'DD-MM-YYYY'));
INSERT INTO Kasjerzy (id_kasjera, nazwisko, data_zatrudnienia, data_urodzenia) VALUES
(102, 'Polak', To_date('01-10-2013', 'DD-MM-YYYY'), To_date('18-09-1983', 'DD-MM-YYYY'));
INSERT INTO Kasjerzy (id_kasjera, nazwisko, data_zatrudnienia, data_urodzenia) VALUES
(103, 'Zalas', To_date('01-01-2019', 'DD-MM-YYYY'), To_date('14-12-1985', 'DD-MM-YYYY'));
INSERT INTO Kasjerzy (id_kasjera, nazwisko, data_zatrudnienia, data_urodzenia) VALUES
(104, 'Pogonowska', To_date('01-11-2018', 'DD-MM-YYYY'), To_date('28-03-1993', 'DD-MM-YYYY'));

INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (1, 1, 100, 2);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (2, 1, 101, 1);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (3, 2, 100, 1);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (4, 3, 102, 5);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (5, 4, 100, 1.35);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (6, 5, 101, 4);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (7, 6, 100, 0.45);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (8, 7, 102, 1.84);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (9, 4, 101, 1.05);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (10, 6, 102, 1.55);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (11, 6, 102, 0.8);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (12, 7, 102, 2.5);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (13, 7, 103, 1.95);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (14, 11, 100, 2);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (15, 11, 104, 1);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (16, 12, 102, 8);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (17, 12, 103, 4);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (18, 12, 104, 5);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (19, 12, 103, 11);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (20, 13, 104, 2);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (21, 14, 102, 1);
INSERT INTO Transakcje (id_transakcji, id_produktu, id_sprzedawcy, miara) VALUES (22, 14, 101, 2);


select * from transakcje;
select * from produkty;
select * from kasjerzy;

-- zad 5
alter table transakcje add (rachunek number(8,2));
commit;

update produkty set stan=stan-(
  select sum(miara) from transakcje
   where rachunek is null
    and  id_produktu=produkty.id_produktu
 )
 where exists(
  select * from transakcje
   where rachunek is null
    and  id_produktu=produkty.id_produktu)
;
select*from produkty;
update transakcje set rachunek=(
  select cena from produkty
   where id_produktu=transakcje.id_produktu
 )
 *miara
 where rachunek is null;
 select*from transakcje;