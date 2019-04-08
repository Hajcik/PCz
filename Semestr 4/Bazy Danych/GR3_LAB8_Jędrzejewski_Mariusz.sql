-- zad 1
Create table Zawodnicy( 
  id_zawodnika number(4) constraint Zawodnicy_PK primary key,
  nazwisko varchar(30) constraint Zawodnicy_Nazw_NN not null,
  imie varchar(30) constraint Zawodnicy_Imie_NN not null,
  data_ur Date constraint Zawodnicy_DataUr_CH 
    check(data_ur > to_date('01.01.1961', 'DD.MM.YYYY')),
  wzrost number(3) constraint Zawodnicy_Wzr_CH check(wzrost > 120),
  waga number(4, 1) constraint Zawodnicy_Waga_CH check(waga > 30),
  pozycja varchar(15) constraint Zawodnicy_Poz_CH 
    check(pozycja in ('bramkarz', 'obronca', 'pomocnik', 'napastnik')),
  klub varchar(50) default 'Wolny Zawodnik',
  liczba_minut number(4) default 0,
  placa number(8, 2));

Insert into Zawodnicy values(
  1001, 'Nowak', 'Piotr', to_date('10.01.1990', 'DD.MM.YYYY'), 
  192, 81.5, 'bramkarz', 'Warta Czestochowa', 360, 4000); 
  
Insert into Zawodnicy values(
  1007, 'Oleksy', 'Robert', to_date('12.08.1996', 'DD.MM.YYYY'), 
  185, 85, 'obronca', null, null, null); 
  
Insert into Zawodnicy(
  id_zawodnika, nazwisko, imie, data_ur, wzrost, waga, pozycja) values(
    1015, 'Zachara', 'Mateusz', to_date('09.09.2000', 'DD.MM.YYYY'), 181, 73, 'napastnik'); 
    
--INSERT INTO Zawodnicy VALUES (1001, 'Nowak', 'Piotr', To_date('10-01-1990', 'DD-MM-YYYY'), 192, 81.5, 'bramkarz', --'Warta Czestochowa', 360, 4000);
INSERT INTO Zawodnicy VALUES (1002, 'Kowalski', 'Adam', To_date('15-04-1992', 'DD-MM-YYYY'), 194, 83, 'bramkarz', 'Odra Wroclaw', 270, 3500);
INSERT INTO Zawodnicy VALUES (1003, 'Polak', 'Dariusz', To_date('11-06-1998', 'DD-MM-YYYY'), 189, 79.5, 'bramkarz', 'Wisla Warszawa', 450, 5000);

INSERT INTO Zawodnicy VALUES (1004, 'Malinowski', 'Adrian', To_date('21-11-1987', 'DD-MM-YYYY'), 190, 85, 'obronca', 'Warta Czestochowa', 300, 3000);
INSERT INTO Zawodnicy VALUES (1005, 'Czech', 'Piotr', To_date('04-12-1989', 'DD-MM-YYYY'), 187, 83, 'obronca', 'Odra Wroclaw', 200, 2600);
INSERT INTO Zawodnicy VALUES (1006, 'Podolski', 'Krystian', To_date('26-02-1997', 'DD-MM-YYYY'), 186, 89, 'obronca', 'Wisla Warszawa', 350, 3500);
--INSERT INTO Zawodnicy (id_zawodnika, nazwisko, imie, data_ur, wzrost, waga, pozycja) VALUES
--(1007, 'Oleksy', 'Robert', To_date('12-08-1996', 'DD-MM-YYYY'), 185, 85, 'obronca');

INSERT INTO Zawodnicy VALUES (1008, 'Grzyb', 'Krzysztof', To_date('17-09-1995', 'DD-MM-YYYY'), 173, 75, 'pomocnik', 'Warta Czestochowa', 400, 3200);
INSERT INTO Zawodnicy VALUES (1009, 'Kwasek', 'Artur', To_date('30-10-1991', 'DD-MM-YYYY'), 180, 75, 'pomocnik', 'Odra Wroclaw', 370, 3300);
INSERT INTO Zawodnicy VALUES (1010, 'Kukla', 'Kamil', To_date('01-02-1993', 'DD-MM-YYYY'), 179, 75, 'pomocnik', 'Wisla Warszawa', 250, 3000);
INSERT INTO Zawodnicy (id_zawodnika, nazwisko, imie, data_ur, wzrost, waga, pozycja) VALUES
(1011, 'Drozd', 'Adam', To_date('19-03-1995', 'DD-MM-YYYY'), 182, 77, 'pomocnik');

INSERT INTO Zawodnicy VALUES (1012, 'Jankowski', 'Marek', To_date('23-09-1999', 'DD-MM-YYYY'), 185, 80, 'napastnik', 'Warta Czestochowa', 60, 2000);
INSERT INTO Zawodnicy VALUES (1013, 'Knysak', 'Fabian', To_date('10-10-1994', 'DD-MM-YYYY'), 175, 73, 'napastnik', 'Odra Wroclaw', 250, 4000);
INSERT INTO Zawodnicy VALUES (1014, 'Tyrek', 'Tomasz', To_date('31-01-1998', 'DD-MM-YYYY'), 179, 74, 'napastnik', 'Wisla Warszawa', 200, 6000);
--INSERT INTO Zawodnicy VALUES (1015, 'Zachara', 'Mateusz', To_date('09-09-2000', 'DD-MM-YYYY'), 181, 73, 'napastnik', NULL, NULL, NULL);

INSERT INTO Zawodnicy VALUES (1016, 'Jaskola', 'Milosz', To_date('13-09-1997', 'DD-MM-YYYY'), 187, 81, 'napastnik', 'Warta Czestochowa', 160, 2300);
INSERT INTO Zawodnicy VALUES (1017, 'Knus', 'Franciszek', To_date('10-03-1984', 'DD-MM-YYYY'), 177, 71, 'napastnik', 'Odra Wroclaw', NULL, 3700);
INSERT INTO Zawodnicy VALUES (1018, 'Toborek', 'Tomasz', To_date('31-03-1997', 'DD-MM-YYYY'), 183, 72, 'napastnik', 'Wisla Warszawa', 230, 6200);
INSERT INTO Zawodnicy VALUES (1019, 'Zasepa', 'Michal', To_date('19-09-2001', 'DD-MM-YYYY'), 180, 76, 'napastnik', NULL, NULL, NULL);

INSERT INTO Zawodnicy VALUES (1020, 'Borel', 'Jan', To_date('11-02-2002', 'DD-MM-YYYY'), 179, 75, 'pomocnik', 'Warta Czestochowa', NULL, NULL);
INSERT INTO Zawodnicy VALUES (1021, 'Czok', 'Damian', To_date('28-08-1995', 'DD-MM-YYYY'), 190, 82, 'obronca', 'Odra Wroclaw', NULL, NULL);

commit;

rollback;

select * from Zawodnicy;

-- zad 2
delete from Zawodnicy where data_ur > sysdate - interval '21' year;
delete from Zawodnicy;
SELECT * FROM Zawodnicy;
ROLLBACK;
SELECT * FROM Zawodnicy;
DROP TABLE Zawodnicy CASCADE CONSTRAINTS;
ROLLBACK;

-- zad 3
update zawodnicy set klub = 'wolny zawodnik' where klub is null;
update zawodnicy set liczba_minut = 0 where liczba_minut is null;
update zawdonicy set placa = 0 where placa is null;
select * from Zawodnicy;

-- zad 4
update Zawodnicy set liczba_minut = liczba_minut + (case liczba_minut when 0 then 45 else 90 end)
where (klub='Warta Czestochowa' or klub='Odra Wroclaw');

-- zad 5
update Zawodnicy zew set placa=placa+ (case
  when placa= (select Max(placa) from zawodnicy where klub=zew.klub) then placa*0.25
  when placa= (select Min(placa) from zawodnicy where klub=zew.klub) then -placa*0.25
  else 0 end)
  where (klub not like 'wolny zawodnik');

-- zad 7
update Zawodnicy set placa=placa+2000, klub='Warta Czestochowa' where id_zawodnika=
  (select Max(id_zawodnika) from Zawodnicy where klub='Odra Wroclaw' and data_ur=
    (select Min(data_ur) from Zawodnicy where klub='Odra Wroclaw'));
  
