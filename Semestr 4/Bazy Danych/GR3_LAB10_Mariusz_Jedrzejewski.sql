create table Najlzejsze_Ryby_Wedkarzy
(
id_wedkarza number(5),
nazwisko varchar2(30 Byte),
id_gatunku number(2),
nazwa varchar2(30 Byte),
waga number(5,2)
);

create table Najciezsze_Ryby_Wedkarzy
(
id_wedkarza number(5),
nazwisko varchar2(30 Byte),
id_gatunku number(2),
nazwa varchar2(30 Byte),
waga number(5,2)
);

insert all 
into Najlzejsze_Ryby_Wedkarzy values(id_wedkarza,nazwisko,id_gatunku,nazwa,Min_Waga)
into Najciezsze_Ryby_Wedkarzy values(id_wedkarza,nazwisko,id_gatunku,nazwa,Max_Waga)
select id_wedkarza, id_gatunku , nazwa, nazwisko, 
nvl((select min(waga)  from dataSource.rejestry where id_wedkarza=ws.ID_WEDKARZA and
id_gatunku=ga.id_gatunku
),0) as Min_Waga, 
nvl((select max(waga)  from dataSource.rejestry where id_wedkarza=ws.ID_WEDKARZA and
id_gatunku=ga.id_gatunku
),0) as Max_Waga
from dataSource.gatunki ga cross join dataSource.wedkarze ws;

select * from Najciezsze_Ryby_Wedkarzy ;
drop table Najciezsze_Ryby_Wedkarzy;
drop table Najlzejsze_Ryby_Wedkarzy;

--Zad 3

CREATE TABLE Zak
(  id_studenta NUMBER(6) CONSTRAINT zak_pk PRIMARY KEY ,
   nazwisko VARCHAR2(20) CONSTRAINT zak_naz_nn NOT NULL,
   imie VARCHAR2(15) CONSTRAINT zak_imie_nn NOT NULL,
   pseudonim VARCHAR2(30) CONSTRAINT zak_pseudo_nn NOT NULL,
   kierunek VARCHAR2(20) DEFAULT 'INFORMATYKA',
   stopien Number CONSTRAINT zak_stop_ch Check(stopien in (1,2,3)),
   semestr Number CONSTRAINT zak_sem_ch Check(semestr between 1 and 8)
);

-- *******************************
-- Zad 3: stworzenie sekwencji
create sequence Zak_id_seq
  minvalue 10000
  maxvalue 99999
  start with 99985
  cycle
  increment by 10;

insert into zak values(Zak_id_seq.nextval, 'KOWALSKI', 'ROMAN', 'KOWAL',  'INFORMATYKA', 1, 2);
insert into zak values(Zak_id_seq.nextval, 'NOWAK', 'ANNA', 'NOWA', 'INFORMATYKA',  1, 3);
insert into zak values(Zak_id_seq.nextval, 'PIECH', 'EWA', 'PEWA',  'MECHANIKA', 1, 2);
insert into zak values(Zak_id_seq.nextval, 'POLAK', 'IZABELA', 'IZA',  'MECHANIKA', 2, 4);

select * from zak;
--Zad 4
alter sequence Zak_id_seq increment by 5;

insert into zak values(Zak_id_seq.nextval, 'WAWRZYNIEC', 'DAMIAN','WAWRZYN',  'INFORMATYKA',  2, 3);
insert into zak values(Zak_id_seq.nextval, 'KOSSAK', 'KATARZYNA', 'KOSA', 'INFORMATYKA',  1, 2);

select * from zak;
select Zak_id_seq.currval from dual;
select Zak_id_seq.nextval from dual;
drop sequence Zak_id_seq;
--Zad 5

create index Kierunek_index on Zak(kierunek);
create index Stopien_index on Zak(stopien, semestr);
create unique index PSeudonim_index on Zak(pseudonim);

insert into zak values((select max(id_studenta) from zak)+1, 'WAWRZYNIEC', 'JAN','WAWRZYN2',  'MATEMATYKA',  1, 2);
insert into zak values((select max(id_studenta) from zak)+1, 'WAWRZYNIEC', 'ADAM','WAWRZYN2',  'MATEMATYKA',  1, 2);
-- problem sprawia tutaj ten sam pseudonim! a wiec:

drop index Pseudonim_index;
insert into zak values((select max(id_studenta) from zak)+1, 'WAWRZYNIEC', 'ADAM','WAWRZYN2',  'MATEMATYKA',  1, 2);

drop index Kierunek_index;
drop index Stopien_index;
drop table Zak;

--Zad 6
create table StudenciBis as select * from dataSource.studenci;
create or REPLACE view Studentki as select * from StudenciBis
  where imiona like '%a' order by nazwisko, imiona;

select * from studentki;

create or REPLACE view Zacy as select * from StudenciBis
  where imiona not like '%a' order by nazwisko, imiona with read only;

select * from zacy;

insert into Zacy values(123456, 'Testowski', 'Test', to_date('01-01-1995', 'dd-mm-yyyy'), 'adres', 'kierunek', 'tryb', 1, 1, 'specjalnosc', 1, 4);
insert into Studentki values(123456, 'Testowski', 'Test', to_date('01-01-1995', 'dd-mm-yyyy'), 'adres', 'kierunek', 'tryb', 1, 1, 'specjalnosc', 1, 4);
insert into Studentki values(123456, 'Testowski', 'Testa', to_date('01-01-1995', 'dd-mm-yyyy'), 'adres', 'kierunek', 'tryb', 1, 1, 'specjalnosc', 1, 4);

-- studentki to perspektywa, widok, nawet jak wprowadzamy to 
-- i tak jest wstawione do StudenciBis
select * from studentki where nazwisko like 'Test%';
select * from zacy where nazwisko like 'Test%';
select * from studencibis where nazwisko like 'Test%';

-- zad 8
create table PracownicyBis as select * from dataSource.pracownicy;
create or replace view Lista_Plac as
select nr_akt, nazwisko, id_dzialu, stanowisko, 
  placa+nvl(dod_funkcyjny, 0)+dod_staz*placa*0.01-nvl(koszt_ubezpieczenia,0) pensja
  from PracownicyBis where (data_zwol is null or data_zwol >= sysdate) 
  and nr_akt>=1000 with CHECK option;

INSERT INTO Lista_Plac VALUES(1222, 'TESTOWSKI', 10, 'INFORMATYK', 5000);

drop view Lista_Plac;

SELECT * FROM Lista_plac; 
select * from pracownicybis;
