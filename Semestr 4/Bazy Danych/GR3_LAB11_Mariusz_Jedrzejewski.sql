--D1

CREATE TABLE DRIVERS
( PESEL VARCHAR2(11) constraint drivers_pk PRIMARY KEY,
  NAZWISKO Varchar2(25) constraint drivers_naz_nn not null,
  IMIE Varchar2(15) constraint drivers_imie_nn not null,
  DATA_URODZENIA DATE constraint drivers_data_ur_ch check( (Extract(Year from data_urodzenia))<= 2020),
  MIEJSCOWOSC Varchar2(30)
);

--D2 
CREATE TABLE CARS
(  NUMER_REJESTRACYJNY Varchar2(8) constraint cars_pk PRIMARY KEY,
   WLASCICIEL VARCHAR2(11),
   MARKA Varchar2(20) constraint cars_marka_ch check(marka in ('AUDI', 'BMW', 'FORD', 'MERCEDES', 'OPEL', 'VW')),
   MODELL Varchar2(20) constraint cars_mod_nn not null, 
   KOLOR varchar2(20) constraint cars_kol_ch check(kolor in ('CZERWONY', 'ZIELONY', 'NIEBIESKI', 'CZARNY', 'BIA£Y', '¯Ó£TY')),
   ROK_PRODUKCJI Number(4) constraint cars_rok_ch check(rok_produkcji between 1980 and 2019),
   constraint cars_wla_fk FOREIGN KEY (wlasciciel) references drivers(pesel) ON DELETE SET NULL
);

--D3
insert into drivers values ('89010301212', 'WOLSKA', 'DOROTA', to_date('2000-03-19','YYYY-MM-DD'), 'CZESTOCHOWA');
insert into drivers values ('87010313219', 'NOWAK', 'ADAM', to_date('2001-10-09','YYYY-MM-DD'), 'OPOLE');
insert into drivers values ('85010313219', 'PIECH', 'ROMAN', to_date('1984-12-12','YYYY-MM-DD'), 'OPOLE');
insert into drivers values ('89110301244', 'KOWALSKI', 'ANDRZEJ', to_date('1992-04-12','YYYY-MM-DD'), 'CZESTOCHOWA');
insert into drivers values('88110301255', 'NOWAK', 'ANNA', to_date('1982-04-22','YYYY-MM-DD'), 'CZESTOCHOWA');
insert into drivers values ('87110301266', 'ZAJAC', 'EDWARD', to_date('1991-05-12','YYYY-MM-DD'), 'OPOLE');
insert into drivers values ('86110301277', 'MAJ', 'JOANNA', to_date('1992-02-02','YYYY-MM-DD'), 'OPOLE');
insert into drivers values ('85110301288', 'WOLSKI', 'PIOTR', to_date('1989-06-27','YYYY-MM-DD'), 'KATOWICE');
insert into drivers values ('84110301299', 'ADAMSKI', 'ROMAN', to_date('1982-09-18','YYYY-MM-DD'), 'KATOWICE');
insert into drivers values ('84110301211', 'POLAK', 'EWA', to_date('1978-03-19','YYYY-MM-DD'), 'CZESTOCHOWA');
insert into drivers values ('85123012323', 'BUDZIAK', 'ANGELIKA', to_date('1995-07-04','YYYY-MM-DD'), 'WARSZAWA');
insert into drivers values ('88100301222', 'ZALAS', 'TOMASZ', to_date('1998-04-06','YYYY-MM-DD'), 'WARSZAWA');
insert into drivers values ('89010301211', 'WITOS', 'JAN', to_date('1995-01-17','YYYY-MM-DD'), 'SZCZECIN');


--Realizacja Zad 1
Update Drivers set pesel=case when extract(year from DATA_URODZENIA) >=2001 
then to_char(data_urodzenia, 'yy') || to_char(extract(month from DATA_URODZENIA) + 20) ||
 to_char(data_urodzenia, 'dd') else
 to_char(data_urodzenia,'yymmdd') end || substr(pesel,7);


select pesel, data_urodzenia, case when extract(year from DATA_URODZENIA) >=2001 
then to_char(data_urodzenia, 'yy') || to_char(extract(month from DATA_URODZENIA) + 20) ||
 to_char(data_urodzenia, 'dd') else
 to_char(data_urodzenia,'yymmdd') end || substr(pesel,7)
from drivers;
--- Wyjscie awaryjne
--select 'UPDATE Drivers Set pesel='''||Pesel||''' Where nazwisko='''||nazwisko||''' and data_urodzenia=to_date('''||to_char(data_urodzenia, 'yyyy/mm/dd')||''',''yyyy/mm/dd'') and imie='''||imie||''' and miejscowosc='''||miejscowosc||''';' from drivers;

/*
UPDATE Drivers Set pesel='00231901212' Where nazwisko='WOLSKA' and data_urodzenia=to_date('2000/03/19','yyyy/mm/dd') and imie='DOROTA' and miejscowosc='CZESTOCHOWA';
UPDATE Drivers Set pesel='01300913219' Where nazwisko='NOWAK' and data_urodzenia=to_date('2001/10/09','yyyy/mm/dd') and imie='ADAM' and miejscowosc='OPOLE';
UPDATE Drivers Set pesel='84121213219' Where nazwisko='PIECH' and data_urodzenia=to_date('1984/12/12','yyyy/mm/dd') and imie='ROMAN' and miejscowosc='OPOLE';
UPDATE Drivers Set pesel='92041201244' Where nazwisko='KOWALSKI' and data_urodzenia=to_date('1992/04/12','yyyy/mm/dd') and imie='ANDRZEJ' and miejscowosc='CZESTOCHOWA';
UPDATE Drivers Set pesel='82042201255' Where nazwisko='NOWAK' and data_urodzenia=to_date('1982/04/22','yyyy/mm/dd') and imie='ANNA' and miejscowosc='CZESTOCHOWA';
UPDATE Drivers Set pesel='91051201266' Where nazwisko='ZAJAC' and data_urodzenia=to_date('1991/05/12','yyyy/mm/dd') and imie='EDWARD' and miejscowosc='OPOLE';
UPDATE Drivers Set pesel='92020201277' Where nazwisko='MAJ' and data_urodzenia=to_date('1992/02/02','yyyy/mm/dd') and imie='JOANNA' and miejscowosc='OPOLE';
UPDATE Drivers Set pesel='89062701288' Where nazwisko='WOLSKI' and data_urodzenia=to_date('1989/06/27','yyyy/mm/dd') and imie='PIOTR' and miejscowosc='KATOWICE';
UPDATE Drivers Set pesel='82091801299' Where nazwisko='ADAMSKI' and data_urodzenia=to_date('1982/09/18','yyyy/mm/dd') and imie='ROMAN' and miejscowosc='KATOWICE';
UPDATE Drivers Set pesel='78031901211' Where nazwisko='POLAK' and data_urodzenia=to_date('1978/03/19','yyyy/mm/dd') and imie='EWA' and miejscowosc='CZESTOCHOWA';
UPDATE Drivers Set pesel='95070412323' Where nazwisko='BUDZIAK' and data_urodzenia=to_date('1995/07/04','yyyy/mm/dd') and imie='ANGELIKA' and miejscowosc='WARSZAWA';
UPDATE Drivers Set pesel='98040601222' Where nazwisko='ZALAS' and data_urodzenia=to_date('1998/04/06','yyyy/mm/dd') and imie='TOMASZ' and miejscowosc='WARSZAWA';
UPDATE Drivers Set pesel='95011701211' Where nazwisko='WITOS' and data_urodzenia=to_date('1995/01/17','yyyy/mm/dd') and imie='JAN' and miejscowosc='SZCZECIN';
*/
select * from drivers;

--D4
insert into cars values ('SC12311', '92041201244', 'AUDI', 'A4', 'CZARNY', 2006 );
insert into cars values ('SC32326', '92041201244', 'FORD', 'MONDEO', 'ZIELONY', 2010 );
insert into cars values ('SC32312', '82042201255', 'AUDI', 'A8', 'CZERWONY', 2011 );
insert into cars values ('O165112', '91051201266', 'AUDI', 'A4', 'CZARNY', 2004 );
insert into cars values ('O200022', '92020201277', 'OPEL', 'ASTRA', 'NIEBIESKI', 1996 );
insert into cars values ('K012311', '89062701288', 'MERCEDES', '190', 'BIA£Y', 1992 );
insert into cars values ('K212111', '82091801299', 'FORD', 'FIESTA', 'ZIELONY', 2009 );
insert into cars values ('SC98123', '78031901211', 'FORD', 'MONDEO', 'BIA£Y', 2012 );
insert into cars values ('WB23414', '95070412323', 'AUDI', 'A4', 'BIA£Y', 2016 );
insert into cars values ('WE90012', '98040601222', 'FORD', 'FOCUS', 'ZIELONY', 2012 );
insert into cars values ('ZS03452', '95011701211', 'AUDI', 'A3', 'CZARNY', 2013 );
insert into cars values ('SCZ3422', '00031901212', 'OPEL', 'ASTRA', 'CZARNY', 2018 );
insert into cars values ('SK02226', '84121213219', 'OPEL', 'ASTRA', 'CZERWONY', 2019 );
insert into cars values ('SK02227', '84121213219', 'OPEL', 'ASTRA', 'ZIELONY', 2019 );

select * from cars;


--D5
CREATE TABLE WYKROCZENIA
(  ID_WYKROCZENIA NUMBER(5) constraint wykroczenia_pk PRIMARY KEY,
   DATA_ZDARZENIA DATE,
   ID_SAMOCHODU Varchar2(8),
   Vz NUMBER(3) constraint wykroczenia_VZ_NN not null,
   Vdop NUMBER(3) constraint wykroczenia_Vdop_NN not null,
   MANDAT NUMBER(6,2) default 0,
   constraint wykroczenia_sam_fk FOREIGN KEY (id_samochodu) REFERENCES cars(numer_rejestracyjny)
);


-- Realizacja  zad 2 - 3
alter table wykroczenia
 add constraint constraint_wykroczenia_check1
  check(vz>vdop and vz>20);
  
create sequence seq_id_wyk
 start with 10000
 minvalue 10000
 maxvalue 99999
 increment by 123
 cycle;
  
  --D6 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-10, 'SC12311', 102, 70, 0 );  
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-20, 'SC12311', 82, 70, 0 );  
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-50, 'SC32326', 112, 60, 0 ); 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-150, 'SC32326', 85, 50, 0 ); 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-84, 'SC32326', 122, 50, 0 ); 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-73, 'K012311', 135, 130, 0 ); 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate, 'O165112', 78, 60, 0 ); 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-189, 'O165112', 146, 110, 0 ); 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-253, 'K012311', 189, 130, 0 ); 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-311, 'O200022', 101, 50, 0 ); 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-178, 'K212111', 104, 70, 0 ); 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate, 'O165112', 98, 90, 0 ); 
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-3, 'WB23414', 92, 50, 0 );  
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-121, 'WE90012', 135, 50, 0 );  
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-250, 'WE90012', 185, 130, 0 );
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-21, 'SCZ3422', 109, 50, 0 );  
insert into wykroczenia values (seq_id_wyk.nextval, sysdate-50, 'SK02227', 175, 140, 0 );

select * from wykroczenia;

--Realizacja  zad 4 - 5 
-- zad 4 
update Wykroczenia set
mandat=case when Vdop=50 and Vz-Vdop>=51 then 5000
  else 0 end +trunc((Vz-Vdop)/10)*200 where Vz-Vdop>=10 and mandat=0;

select Vz, Vdop, case when Vdop=50 and Vz-Vdop>=51 then 5000 
  else 0 end + trunc((Vz-Vdop)/10)*200 from Wykroczenia;

-- Wyjscie awaryjne po zadaniu 4
/*
Update Wykroczenia Set mandat=600 Where id_wykroczenia=10000;
Update Wykroczenia Set mandat=200 Where id_wykroczenia=10123;
Update Wykroczenia Set mandat=1000 Where id_wykroczenia=10246;
Update Wykroczenia Set mandat=600 Where id_wykroczenia=10369;
Update Wykroczenia Set mandat=6400 Where id_wykroczenia=10492;
Update Wykroczenia Set mandat=0 Where id_wykroczenia=10615;
Update Wykroczenia Set mandat=200 Where id_wykroczenia=10738;
Update Wykroczenia Set mandat=600 Where id_wykroczenia=10861;
Update Wykroczenia Set mandat=1000 Where id_wykroczenia=10984;
Update Wykroczenia Set mandat=6000 Where id_wykroczenia=11107;
Update Wykroczenia Set mandat=600 Where id_wykroczenia=11230;
Update Wykroczenia Set mandat=0 Where id_wykroczenia=11353;
Update Wykroczenia Set mandat=800 Where id_wykroczenia=11476;
Update Wykroczenia Set mandat=6600 Where id_wykroczenia=11599;
Update Wykroczenia Set mandat=1000 Where id_wykroczenia=11722;
Update Wykroczenia Set mandat=6000 Where id_wykroczenia=11845;
Update Wykroczenia Set mandat=600 Where id_wykroczenia=11968;
*/

--zad 5
create or replace view Rejestr_Mandatow as 
select nazwisko, imie, marka, modell, data_zdarzenia, mandat 
  from drivers join cars on (wlasciciel=pesel) join wykroczenia on (numer_rejestracyjny=id_samochodu)
  where mandat>0;

--D7

insert into Wykroczenia values (seq_id_wyk.nextval, sysdate-3, 'O200022', 71, 50, 0 ); 
insert into Wykroczenia values (seq_id_wyk.nextval, sysdate-19, 'O165112', 151, 90, 0 ); 
insert into Wykroczenia values (seq_id_wyk.nextval, sysdate-453, 'K012311', 137, 50, 0 ); 

SELECT * FROM Rejestr_Mandatow;
SELECT * FROM Wykroczenia;

--zad 6
create or replace view Bilans_Roczny_Kar as
select extract(year from DATA_ZDARZENIA) rok, nazwisko, imie, sum(mandat) KWOTA,
count(id_wykroczenia) Liczba_wykroczen from drivers
join cars on (wlasciciel=pesel) join wykroczenia on (numer_rejestracyjny=id_samochodu)
  where mandat>0 group by extract(year from DATA_ZDARZENIA), nazwisko, imie
  order by 1 desc, 4 desc;
-- wyjscie awaryjne
/*
Update Wykroczenia Set mandat=400 Where id_wykroczenia=12091;
Update Wykroczenia Set mandat=1200 Where id_wykroczenia=12214;
Update Wykroczenia Set mandat=6600 Where id_wykroczenia=12337;
*/

--zad 10
select pesel,nazwisko,imie,miejscowosc from drivers minus
select pesel,nazwisko,imie,miejscowosc from drivers
join cars on (wlasciciel=pesel) join wykroczenia on (numer_rejestracyjny=id_samochodu)
  where mandat>0 and data_zdarzenia>=sysdate-interval'1'year;

savepoint S1;

select * from wykroczenia;

delete from wykroczenia where mandat<=400;
select * from wykroczenia;

savepoint S2;

delete from wykroczenia where mandat<=1000;
select * from wykroczenia;

rollback to savepoint S1;
select * from wykroczenia;
-- zad 14
drop view BRK;
drop view Rejestr_Mandatow;
drop view Bilans_Roczny_Kar;
drop view Bilans_Mandatow_Sam;
drop view Lista_Piratow_Drogowych;
drop view Lista_Wzorowych_Kierowcow;
drop table cars cascade constraint; 
drop table drivers cascade constraint; 
drop table wykroczenia cascade constraint; 
drop sequence seq_id_wyk;