set serveroutput ON;
CREATE TABLE MENU
  (
    id_menu     VARCHAR2(10 BYTE) CONSTRAINT id_menu_PK PRIMARY KEY,
    nazwa       VARCHAR2(25 BYTE) CONSTRAINT nazwa_NN NOT NULL,
    waga_porcji NUMBER(5, 3) CONSTRAINT waga_porcji_CH CHECK(waga_porcji < 5 ),
    cena        NUMBER(6, 2) DEFAULT 10
  );

CREATE TABLE KLIENCI
  (
    id_klienta NUMBER(5),
    nazwisko   VARCHAR2(25 BYTE) CONSTRAINT klienci_nazwisko_NN NOT NULL,
    imie       VARCHAR2(25 BYTE) CONSTRAINT klienci_imie_NN NOT NULL,
    data_ur    DATE CONSTRAINT data_ur_CH CHECK(data_ur > to_date('01.01.1901', 'DD.MM.YYYY')),
    CONSTRAINT klienci_PK PRIMARY KEY (nazwisko, imie)
  );
  
CREATE TABLE ZAMOWIENIA
  (
    id_zamowienia   NUMBER(5) CONSTRAINT id_zamowienia_PK PRIMARY KEY,
    id_klienta      NUMBER(5),
    data_zamowienia DATE DEFAULT sysdate NOT NULL,
    zupa            VARCHAR2(10 BYTE) CONSTRAINT zupa_NN NOT NULL,
    LP_Zupa         NUMBER(2) DEFAULT 1,
    drugie_danie    VARCHAR2(10 BYTE),
    LP_DD           NUMBER(2) DEFAULT 0,
    przystawka      VARCHAR2(10 BYTE),
    LP_Deser        NUMBER(2) DEFAULT 99,
    rachunek        NUMBER(7, 2) DEFAULT 0,
    CONSTRAINT zupa_FK FOREIGN KEY (zupa) REFERENCES menu (id_menu) ON DELETE CASCADE,
    CONSTRAINT drugie_danie_FK FOREIGN KEY (drugie_danie) REFERENCES menu (id_menu) ON DELETE CASCADE,
    CONSTRAINT przystawka_FK FOREIGN KEY (przystawka) REFERENCES menu (id_menu)  ON DELETE CASCADE
  );

--Zad 4
ALTER TABLE KLIENCI DROP CONSTRAINT klienci_PK;
ALTER TABLE KLIENCI ADD CONSTRAINT id_klienta_PK PRIMARY KEY (id_klienta);
--Zad 5
ALTER TABLE MENU ADD Liczba_Wydanych_Porcji NUMBER(5) default 0; 
--Zad 6
ALTER TABLE ZAMOWIENIA RENAME COLUMN przystawka TO deser;
--Zad 7
ALTER TABLE ZAMOWIENIA MODIFY LP_Deser DEFAULT 0;
--Zad 8
ALTER TABLE ZAMOWIENIA ADD CONSTRAINT LP_Zupa_CH CHECK (1  <=LP_Zupa AND 20<=LP_Zupa);
ALTER TABLE ZAMOWIENIA ADD CONSTRAINT LP_DD_CH CHECK ((0   <=LP_DD AND LP_DD<=20) OR LP_DD IS NULL);
ALTER TABLE ZAMOWIENIA ADD CONSTRAINT LP_Deser_CH CHECK ((0<=LP_DESER AND LP_DESER<=50) OR LP_DD IS NULL);
--Zad 9
ALTER TABLE ZAMOWIENIA ADD CONSTRAINT zupa_CHECK CHECK (zupa='ZU%');
ALTER TABLE ZAMOWIENIA ADD CONSTRAINT drugie_danie_CHECK (drugie_danie='DD%' OR drugie_dane IS NULL);
ALTER TABLE ZAMOWIENIA ADD CONSTRAINT deser_CHECK (deser='DE%' or drugie_danie IS NULL);
--Zad 11
CREATE INDEX indeks_naz_imie ON KLIENCI (nazwisko, imie);
--Zad 12
CREATE SEQUENCE seq_id_zamowienia
  minvalue 0
  maxvalue 4000
  start with 1000
  cycle
  increment by 50;
--Zad 13
ALTER SEQUENCE seq_id_zamowienia maxvalue 99999;
--Zad 14
DELETE FROM MENU WHERE id_menu = '%NA';
  
--Zad 17
CREATE VIEW Zeszloroczne_Stat_Miesieczne WITH READ ONLY AS
select miesiac
  
--Zad 22
drop table MENU;
drop table KLIENCI;
drop table ZAMOWIENIA;
drop sequence seq_id_zamowienia;
drop index indeks_naz_imie;
drop view Zeszloroczne_Stat_Miesieczne;

--------------------------------------------

INSERT INTO KLIENCI VALUES(1, 'Nowak', 'Piotr', To_Date('1981-03-21', 'YYYY-MM-DD'));
INSERT INTO KLIENCI VALUES(2, 'Olczak', 'Anna', To_Date('1967-11-24', 'YYYY-MM-DD'));
INSERT INTO KLIENCI VALUES(3, 'Wach', 'Olga', To_Date('1991-04-01', 'YYYY-MM-DD'));
INSERT INTO KLIENCI VALUES(4, 'Dyzak', 'Paulina', To_Date('1998-12-11', 'YYYY-MM-DD'));
INSERT INTO KLIENCI VALUES(5, 'Haczyk', 'Dariusz', To_Date('1956-01-28', 'YYYY-MM-DD'));
INSERT INTO KLIENCI VALUES(6, 'Zalas', 'Adam', To_Date('1977-07-18', 'YYYY-MM-DD'));
INSERT INTO KLIENCI VALUES(7, 'Traczkiewicz', 'Andrzej', To_Date('1988-09-12', 'YYYY-MM-DD'));
INSERT INTO KLIENCI VALUES(8, 'Antczak', 'Piotr', To_Date('1968-10-05', 'YYYY-MM-DD'));
INSERT INTO KLIENCI VALUES(9, 'Borowski', 'Tomasz', To_Date('1976-03-08', 'YYYY-MM-DD'));
INSERT INTO KLIENCI VALUES(10, 'Kaleta', 'Anna', To_Date('1984-08-31', 'YYYY-MM-DD'));

INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('ZU_001', 'Zupa Cebulowa', 0.3, 3.5);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('ZU_002', 'Zupa Ogórkowa', 0.3, 4.2);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('ZU_003', 'Rosól', 0.1, 4.5);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('ZU_004', 'Pieczarkowa', 0.1, 2.9);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('ZU_005', 'Pomidorowa', 0.1, 2.8);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('ZU_006', 'Warzywna', 0.1, 2.5);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_001', 'Ziemniaki', 0.1, 1.5);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_002', 'Frytki', 0.1, 4.2);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_003', 'Ryż', 0.1, 2.75);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_004', 'Kotlet schabowy', 0.15, 7.25);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_005', 'Udo kurczaka', 0.15, 4.15);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_006', 'Pieczone żeberka', 0.1, 5.9);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_007', 'Ryba Sandacz', 0.12, 12.90);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_008', 'Ryba Dorsz', 0.1, 15.2);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_009', 'Stek', 0.15, 9.55);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_010', 'Pierogi', 0.2, 3.5);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_011', 'Pyzy', 0.2, 3.95);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DE_001', 'Lody', 0.15, 5.5);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DE_002', 'Sernik', 0.1, 5.75);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DE_003', 'Kremowka', 0.15, 6.2);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DE_004', 'Paczek', 0.2, 2.85);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DE_005', 'Jablecznik', 0.2, 6.25);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('NA_001', 'Herbata', 0.25, 7.5);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('NA_002', 'Kawa', 0.2, 10.0);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('NA_003', 'Piwo', 0.5, 7.5);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('NA_004', 'Sok owocowy', 0.3, 6.2);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('NA_005', 'Woda z cytryną', 0.3, 3.5);


INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 1, To_Date('2017-10-10', 'YYYY-MM-DD'), 'ZU_001', 2, 'DD_003', 2, 'DE_001', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 1, To_Date('2017-10-17', 'YYYY-MM-DD'), 'ZU_002', 1, 'DD_001', 3, 'DE_002', 3,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 1, To_Date('2017-11-10', 'YYYY-MM-DD'), 'ZU_003', 3, NULL, NULL, 'DE_001', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 1, To_Date('2017-11-18', 'YYYY-MM-DD'), 'ZU_001', 2, 'DD_005', 1, 'DE_003', 1,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 1, To_Date('2017-12-16', 'YYYY-MM-DD'), 'ZU_004', 2, NULL, NULL, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 1, To_Date('2017-12-17', 'YYYY-MM-DD'), 'ZU_001', 3, 'DD_006', 3, 'DE_004', 4,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 1, To_Date('2018-01-06', 'YYYY-MM-DD'), 'ZU_003', 4, NULL, NULL, 'DE_001', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 1, To_Date('2018-03-18', 'YYYY-MM-DD'), 'ZU_004', 2, 'DD_005', 2, 'DE_003', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 1, To_Date('2018-03-26', 'YYYY-MM-DD'), 'ZU_002', 5, 'DD_007', 2, 'DE_001', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 1, To_Date('2018-04-15', 'YYYY-MM-DD'), 'ZU_001', 2, 'DD_008', 2, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 2, To_Date('2017-10-15', 'YYYY-MM-DD'), 'ZU_002', 2, 'DD_008', 2, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 2, To_Date('2017-11-15', 'YYYY-MM-DD'), 'ZU_002', 3, 'DD_009', 3, 'DE_004', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 2, To_Date('2018-01-15', 'YYYY-MM-DD'), 'ZU_001', 4, 'DD_010', 4, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 2, To_Date('2018-02-15', 'YYYY-MM-DD'), 'ZU_002', 2, 'DD_010', 5, 'DE_001', 1,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 2, To_Date('2018-03-15', 'YYYY-MM-DD'), 'ZU_003', 2, 'DD_007', 3, 'DE_002', 3,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 3, To_Date('2017-10-05', 'YYYY-MM-DD'), 'ZU_001', 1, 'DD_006', 2, 'DE_004', 1,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 3, To_Date('2017-10-16', 'YYYY-MM-DD'), 'ZU_002', 2, 'DD_005', 2, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 3, To_Date('2017-11-25', 'YYYY-MM-DD'), 'ZU_003', 3, 'DD_006', 2, 'DE_003', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 3, To_Date('2017-12-19', 'YYYY-MM-DD'), 'ZU_004', 4, NULL, NULL, 'DE_004', 3,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 4, To_Date('2017-11-25', 'YYYY-MM-DD'), 'ZU_003', 3, 'DD_001', 2, 'DE_003', 3,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 4, To_Date('2017-11-27', 'YYYY-MM-DD'), 'ZU_001', 1, 'DD_002', 3, 'DE_001', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 4, To_Date('2017-11-30', 'YYYY-MM-DD'), 'ZU_002', 2, NULL, NULL, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 4, To_Date('2018-01-25', 'YYYY-MM-DD'), 'ZU_003', 3, 'DD_006', 2, 'DE_001', 5,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 4, To_Date('2018-02-27', 'YYYY-MM-DD'), 'ZU_004', 2, NULL, NULL, 'DE_004', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 4, To_Date('2018-03-30', 'YYYY-MM-DD'), 'ZU_003', 1, 'DD_008', 3, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 5, To_Date('2017-10-25', 'YYYY-MM-DD'), 'ZU_003', 2, 'DD_002', 2, 'DE_003', 3,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 5, To_Date('2017-11-27', 'YYYY-MM-DD'), 'ZU_001', 1, 'DD_001', 3, 'DE_001', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 5, To_Date('2017-12-30', 'YYYY-MM-DD'), 'ZU_002', 1, NULL, NULL, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 5, To_Date('2018-02-25', 'YYYY-MM-DD'), 'ZU_003', 3, 'DD_007', 2, 'DE_003', 5,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 5, To_Date('2018-03-27', 'YYYY-MM-DD'), 'ZU_004', 2, NULL, NULL, 'DE_004', 1,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 5, To_Date('2018-03-30', 'YYYY-MM-DD'), 'ZU_003', 3, 'DD_005', 3, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 5, To_Date('2018-04-03', 'YYYY-MM-DD'), 'ZU_004', 2, NULL, NULL, 'DE_002', 1,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 5, To_Date('2018-04-30', 'YYYY-MM-DD'), 'ZU_003', 1, 'DD_004', 3, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2017-10-05', 'YYYY-MM-DD'), 'ZU_004', 3, 'DD_004', 2, 'DE_003', 3,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2017-10-27', 'YYYY-MM-DD'), 'ZU_001', 1, 'DD_005', 3, 'DE_001', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2018-01-17', 'YYYY-MM-DD'), 'ZU_003', 2, NULL, NULL, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2018-01-20', 'YYYY-MM-DD'), 'ZU_003', 3, 'DD_009', 2, 'DE_001', 5,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2018-02-12', 'YYYY-MM-DD'), 'ZU_001', 2, NULL, NULL, 'DE_004', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2018-03-13', 'YYYY-MM-DD'), 'ZU_003', 1, 'DD_010', 3, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2018-03-18', 'YYYY-MM-DD'), 'ZU_002', 3, 'DD_010', 2, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 7, To_Date('2018-02-12', 'YYYY-MM-DD'), 'ZU_003', 2, 'DD_007', 3, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 7, To_Date('2018-03-16', 'YYYY-MM-DD'), 'ZU_002', 3, 'DD_008', 2, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 8, To_Date('2017-10-09', 'YYYY-MM-DD'), 'ZU_002', 3, 'DD_010', 3, 'DE_003', 3,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 8, To_Date('2017-12-17', 'YYYY-MM-DD'), 'ZU_003', 2, 'DD_007', 3, 'DE_001', 4,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 10, To_Date('2018-04-19', 'YYYY-MM-DD'), 'ZU_002', 3, 'DD_005', 3, 'DE_003', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 5, To_Date('2018-03-19', 'YYYY-MM-DD'), 'ZU_001', 5, 'DD_009', 4, 'DE_003', 3,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2019-02-15', 'YYYY-MM-DD'), 'ZU_003', 3, 'DD_007', 2, 'DE_001', 5,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2019-02-16', 'YYYY-MM-DD'), 'ZU_001', 2, NULL, NULL, 'DE_004', 2,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2019-03-13', 'YYYY-MM-DD'), 'ZU_003', 1, 'DD_010', 3, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 6, To_Date('2019-03-29', 'YYYY-MM-DD'), 'ZU_005', 3, 'DD_004', 2, NULL, NULL,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 7, To_Date('2019-04-12', 'YYYY-MM-DD'), 'ZU_003', 2, 'DD_007', 3,  'DE_003', 1,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 7, To_Date('2019-04-17', 'YYYY-MM-DD'), 'ZU_002', 3, 'DD_003', 2, 'DE_005',  4,  0);
INSERT INTO ZAMOWIENIA VALUES(seq_id_zamowienia.nextval, 5, To_Date('2018-09-11', 'YYYY-MM-DD'), 'ZU_005', 5, 'DD_006', 4, 'DE_002', 2,  0);


SELECT * FROM Zamowienia;
SELECT * FROM Klienci;
SELECT * FROM Menu;
