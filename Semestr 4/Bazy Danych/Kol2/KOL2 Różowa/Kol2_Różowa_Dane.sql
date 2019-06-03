
-- po zadaniu 13 Dane 

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
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_003', 'Ry¿', 0.1, 2.75);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_004', 'Kotlet schabowy', 0.15, 7.25);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_005', 'Udo kurczaka', 0.15, 4.15);
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('DD_006', 'Pieczone ¿eberka', 0.1, 5.9);
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
INSERT INTO MENU (id_menu, nazwa, waga_porcji, cena) VALUES('NA_005', 'Woda z cytryn¹', 0.3, 3.5);


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

/*
SELECT * FROM Zamowienia;
SELECT * FROM Klienci;
SELECT * FROM Menu;
*/

-- zad 15
--wyjscie awaryjne
/*
update zamowienia set rachunek=23.5 where id_zamowienia=1000;
update zamowienia set rachunek=14.45 where id_zamowienia=1050;
update zamowienia set rachunek=30 where id_zamowienia=1100;
update zamowienia set rachunek=23.55 where id_zamowienia=1150;
update zamowienia set rachunek=10 where id_zamowienia=1200;
update zamowienia set rachunek=36.75 where id_zamowienia=1250;
update zamowienia set rachunek=40 where id_zamowienia=1300;
update zamowienia set rachunek=26.5 where id_zamowienia=1350;
update zamowienia set rachunek=74.3 where id_zamowienia=1400;
update zamowienia set rachunek=37.4 where id_zamowienia=1450;
update zamowienia set rachunek=38.8 where id_zamowienia=1500;
update zamowienia set rachunek=49.8 where id_zamowienia=1550;
update zamowienia set rachunek=28 where id_zamowienia=1600;
update zamowienia set rachunek=36.9 where id_zamowienia=1650;
update zamowienia set rachunek=59.2 where id_zamowienia=1700;
update zamowienia set rachunek=18.15 where id_zamowienia=1750;
update zamowienia set rachunek=16.7 where id_zamowienia=1800;
update zamowienia set rachunek=43.9 where id_zamowienia=1850;
update zamowienia set rachunek=23 where id_zamowienia=1900;
update zamowienia set rachunek=35.1 where id_zamowienia=1950;
update zamowienia set rachunek=21.6 where id_zamowienia=2000;
update zamowienia set rachunek=10 where id_zamowienia=2050;
update zamowienia set rachunek=41.8 where id_zamowienia=2100;
update zamowienia set rachunek=11.5 where id_zamowienia=2150;
update zamowienia set rachunek=50.1 where id_zamowienia=2200;
update zamowienia set rachunek=29.8 where id_zamowienia=2250;
update zamowienia set rachunek=13.5 where id_zamowienia=2300;
update zamowienia set rachunek=10 where id_zamowienia=2350;
update zamowienia set rachunek=57.9 where id_zamowienia=2400;
update zamowienia set rachunek=11.5 where id_zamowienia=2450;
update zamowienia set rachunek=25.95 where id_zamowienia=2500;
update zamowienia set rachunek=17.3 where id_zamowienia=2550;
update zamowienia set rachunek=26.25 where id_zamowienia=2600;
update zamowienia set rachunek=41.8 where id_zamowienia=2650;
update zamowienia set rachunek=21.45 where id_zamowienia=2700;
update zamowienia set rachunek=10 where id_zamowienia=2750;
update zamowienia set rachunek=49.1 where id_zamowienia=2800;
update zamowienia set rachunek=12.7 where id_zamowienia=2850;
update zamowienia set rachunek=15 where id_zamowienia=2900;
update zamowienia set rachunek=19.6 where id_zamowienia=2950;
update zamowienia set rachunek=47.7 where id_zamowienia=3000;
update zamowienia set rachunek=43 where id_zamowienia=3050;
update zamowienia set rachunek=41.7 where id_zamowienia=3100;
update zamowienia set rachunek=58.7 where id_zamowienia=3150;
update zamowienia set rachunek=43.65 where id_zamowienia=3200;
update zamowienia set rachunek=86.7 where id_zamowienia=3250;
update zamowienia set rachunek=55.8 where id_zamowienia=3300;
update zamowienia set rachunek=12.7 where id_zamowienia=3350;
update zamowienia set rachunek=15 where id_zamowienia=3400;
update zamowienia set rachunek=22.9 where id_zamowienia=3450;
update zamowienia set rachunek=60.1 where id_zamowienia=3500;
update zamowienia set rachunek=36.85 where id_zamowienia=3550;
update zamowienia set rachunek=66.35 where id_zamowienia=3600;
*/

-- zad 16
-- wyjscie awaryjne

/*
update menu set liczba_wydanych_porcji=26 where id_menu='ZU_001';
update menu set liczba_wydanych_porcji=33 where id_menu='ZU_002';
update menu set liczba_wydanych_porcji=44 where id_menu='ZU_003';
update menu set liczba_wydanych_porcji=17 where id_menu='ZU_004';
update menu set liczba_wydanych_porcji=8 where id_menu='ZU_005';
update menu set liczba_wydanych_porcji=0 where id_menu='ZU_006';
update menu set liczba_wydanych_porcji=8 where id_menu='DD_001';
update menu set liczba_wydanych_porcji=5 where id_menu='DD_002';
update menu set liczba_wydanych_porcji=4 where id_menu='DD_003';
update menu set liczba_wydanych_porcji=7 where id_menu='DD_004';
update menu set liczba_wydanych_porcji=14 where id_menu='DD_005';
update menu set liczba_wydanych_porcji=13 where id_menu='DD_006';
update menu set liczba_wydanych_porcji=18 where id_menu='DD_007';
update menu set liczba_wydanych_porcji=9 where id_menu='DD_008';
update menu set liczba_wydanych_porcji=9 where id_menu='DD_009';
update menu set liczba_wydanych_porcji=20 where id_menu='DD_010';
update menu set liczba_wydanych_porcji=0 where id_menu='DD_011';
update menu set liczba_wydanych_porcji=34 where id_menu='DE_001';
update menu set liczba_wydanych_porcji=9 where id_menu='DE_002';
update menu set liczba_wydanych_porcji=28 where id_menu='DE_003';
update menu set liczba_wydanych_porcji=17 where id_menu='DE_004';
update menu set liczba_wydanych_porcji=4 where id_menu='DE_005';
*/
