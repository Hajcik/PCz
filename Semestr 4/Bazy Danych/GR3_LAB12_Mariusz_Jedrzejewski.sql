SET serveroutput ON;
--zad 1
CREATE TABLE REJESTR_ZDARZEN
  (
    Nazwa_tabeli   VARCHAR(25),
    Data           DATE,
    Liczba_wierszy NUMBER(5),
    Komunikat      VARCHAR(200)
  );
CREATE TABLE Dzialy2 AS SELECT * FROM DataSource.Dzialy;
CREATE TABLE Stanowiska2 AS SELECT * FROM DataSource.stanowiska;
CREATE TABLE Pracownicy2 AS SELECT * FROM DataSource.pracownicy;

ALTER TABLE Pracownicy2 ADD CONSTRAINT pracownicy2_pk PRIMARY KEY(nr_akt);
ALTER TABLE Pracownicy2 ADD CONSTRAINT pracownicy2_przelozony_f FOREIGN KEY(przelozony) REFERENCES Pracownicy2(nr_akt);

--zad 2
DECLARE
x number(2);
BEGIN
for x in 1..10 loop 
if mod(x,2)=0 then
  DBMS_OUTPUT.PUT_LINE('Liczba ' || x || ' jest podzielna przez 2');
elsif mod(x,3)=0 then
  DBMS_OUTPUT.PUT_LINE('Liczba ' || x || ' jest podzielna przez 3');
elsif mod(x,5)=0 then
  DBMS_OUTPUT.PUT_LINE('Liczba ' || x || ' jest podzielna przez 5');
else
  DBMS_OUTPUT.PUT_LINE('Liczba ' || x || ' nie jest podzielna przez 2,3,5');
end if;
end loop;
END;

-- zad 3a
SAVEPOINT P3a;
DECLARE
  new_id_dzialu dzialy2.id_dzialu%type;
  liczba_wierszy NUMBER;
  new_nazwa      VARCHAR(30);
BEGIN
  SELECT MAX(id_dzialu)+10 INTO new_id_dzialu FROM dzialy2;
  INSERT INTO dzialy2 VALUES
    ( new_id_dzialu, 'Kadry', 'ul. Wolnosci 23 42-200 Czestochowa' )
  RETURNING nazwa INTO new_nazwa;
  liczba_wierszy:=sql%rowcount;
  INSERT INTO rejestr_zdarzen VALUES
    ( 'dzialy2', sysdate, liczba_wierszy, 'Dodano nowy dzial ' ||new_nazwa ||' o numerze ' ||new_id_dzialu );
END;

--zad 3b

declare
new_nr_akt pracownicy2.nr_akt%type;
new_przelozony pracownicy2.nr_akt%type;
new_placa pracownicy2.placa%type;
new_id_dzialu dzialy2.id_dzialu%type;
liczba_wierszy number;
begin
select max(nr_akt) + 100 into new_nr_akt from pracownicy2 where data_zwol is null or data_zwol >= sysdate;
select nr_akt into new_przelozony from pracownicy2 where stanowisko like 'Prezes' 
and (data_zwol is null or data_zwol >= sysdate);
select (placa_min+placa_max)/2 into new_placa from stanowiska2 where stanowisko like 'Dyrektor';
select id_dzialu into new_id_dzialu from dzialy2 where nazwa like 'Kadry';
insert into pracownicy2 values (new_nr_akt,'Adamski','Adam','Dyrektor',new_przelozony,
to_date('01-06-1980','DD-MM-YYYY'),sysdate,null,new_placa,1000,0,null,new_id_dzialu);
liczba_wierszy:=sql%rowcount;
insert into rejestr_zdarzen values('Pracownicy2', sysdate,liczba_wierszy,'Dodano nowego pracownika Adamski Adam');
end;

-- zad 4b/c
savepoint P4bc;

declare
liczba_wierszy number;

begin
update pracownicy2 pr set placa=placa*1.2 where nr_akt in(
select nr_akt from pracownicy2 where id_dzialu = 20 and (data_zwol is null or data_zwol>=sysdate) minus
select przelozony from pracownicy2 where  (data_zwol is null or data_zwol>=sysdate))and placa*1.2 between 
(select placa_min from stanowiska where stanowisko = pr.stanowisko ) and 
(select placa_max from stanowiska where stanowisko = pr.stanowisko );
liczba_wierszy:= sql%rowcount;
insert into rejestr_zdarzen values ('pracownicy2',sysdate,liczba_wierszy,'Zwiekszono place '|| liczba_wierszy||' pracownikom');
end;



select * from dzialy2;
select * from pracownicy2;
select * from rejestr_zdarzen;








select * from dzialy2;
select * from pracownicy2;
select * from rejestr_zdarzen;