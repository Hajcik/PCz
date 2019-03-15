using System;
using System.Collections.Generic;
namespace ConsoleApp1
{ // using K = System.Console ;
    class Osoba
    {
        protected string imie;
        protected string nazwisko;
        protected string dataUrodzenia;
        public string Imie
        { get { return imie; } set { imie = value; } }
        public string Nazwisko
        { get { return nazwisko; } set { nazwisko = value; } }
        public string DataUrodzenia
        { get { return dataUrodzenia; } set { dataUrodzenia = value; } }
        public Osoba()
        {
            imie = "nieznane";
            nazwisko = "nieznane";
            dataUrodzenia = "nieznana";
        }
        public Osoba(string imie_, string nazwisko_, string data_)
        {
            this.imie = imie_;
            this.nazwisko = nazwisko_;
            this.dataUrodzenia = data_;
        }
        public virtual void WypiszInfo()
        {
            Console.WriteLine("Imie: " + imie);
            Console.WriteLine("Nazwisko: " + nazwisko);
            Console.WriteLine("Data urodzenia: " + dataUrodzenia);
        }
    }
    class Student : Osoba
    {
        private int rok;
        private int grupa;
        private int nrIndeksu;
        private List<Ocena> oceny = new List<Ocena>();
        public int Rok
        { get { return rok; } set { rok = value; } }
        public int Grupa
        { get { return grupa; } set { grupa = value; } }
        public int NrIndeksu
        { get { return nrIndeksu; } set { nrIndeksu = value; } }
        public Student()
        {
            imie = "nieznane";
            nazwisko = "nieznane";
            dataUrodzenia = "nieznane";
            rok = 0;
            grupa = 0;
            nrIndeksu = 0;
        }
        public Student(string imie_, string nazwisko_, string dataUrodzenia_,
        int rok_, int grupa_, int nrIndeksu_)
        {
            this.imie = imie_;
            this.nazwisko = nazwisko_;
            this.dataUrodzenia = dataUrodzenia_;
            this.rok = rok_;
            this.grupa = grupa_;
            this.nrIndeksu = nrIndeksu_;
        }
        public void WypiszOceny()
        { }
        public override void WypiszInfo()
        {
            base.WypiszInfo();
            Console.WriteLine("Rok studiow: " + rok);
            Console.WriteLine("Grupa: " + grupa);
            Console.WriteLine("Nr indeksu: " + nrIndeksu);
            Console.WriteLine("Ocena z przedmiotu: " + oceny.Count); // oceny.Count
        }
        public Ocena DodajOcene(string nazwaPrzedmiotu, string data, double wartosc)
        {
            Ocena o = new Ocena(nazwaPrzedmiotu, data, wartosc);
            oceny.Add(o);
            return o;
        }
        public void UsunOcene(string nazwaPrzedmiotu, string data, double wartosc)
        {
            for (int i = 0; i < oceny.Count;)
            {
                Ocena o = oceny[i];
                if (o.NazwaPrzedmiotu == nazwaPrzedmiotu && o.Data == data && o.Wartosc == wartosc)
                { oceny.RemoveAt(i); }
                else { ++i; }
            }
        }
        public void UsunOceny(string nazwaPrzedmiotu)
        {
            for(int i=0; i < oceny.Count;)
            {
                Ocena o = oceny[i];
                if(o.NazwaPrzedmiotu == nazwaPrzedmiotu) { oceny.RemoveAt(i); }
                else { ++i; }
            }
        }
        public void UsunOceny()
        { oceny.Clear(); }
    }
    class Ocena : Student
    {
        private string nazwaPrzedmiotu;
        private string data;
        private double wartosc;
        public string NazwaPrzedmiotu
        { get { return nazwaPrzedmiotu; } set { nazwaPrzedmiotu = value; } }
        public string Data
        { get { return data; } set { data = value; } }
        public double Wartosc
        { get { return wartosc; } set { wartosc = value; } }
        public Ocena()
        {
            nazwaPrzedmiotu = "nieznany przedmiot";
            data = "nieznana data";
            wartosc = 0.0;
        }
        public Ocena(string nazwaPrzedmiotu_, string data_, double wartosc_)
        {
            this.nazwaPrzedmiotu = nazwaPrzedmiotu_;
            this.data = data_;
            this.wartosc = wartosc_;
        }
        public override void WypiszInfo()
        {
        //    base.WypiszInfo();
            Console.WriteLine("Nazwa przedmiotu: " + nazwaPrzedmiotu);
            Console.WriteLine("Data: " + data);
            Console.WriteLine("Wartosc: " + wartosc);
        }
    }

    class Pilkarz : Osoba
        {
            private string pozycja;
            private string klub;
            private int liczbaGoli = 0;
            public string Pozycja
            { get { return pozycja; } set { pozycja = value; } }
            public string Klub
            { get { return klub; } set { klub = value; } }
            public int LiczbaGoli
            { get { return liczbaGoli; } set { liczbaGoli = value; } }
            public Pilkarz()
            {
                imie = "nieznane";
                nazwisko = "nieznane";
                dataUrodzenia = "nieznane";
                pozycja = "nieznana";
                klub = "nieznany";

            }
            public Pilkarz(string imie_, string nazwisko_, string dataUrodzenia_,
            string pozycja_, string klub_)
            {
                this.imie = imie_;
                this.nazwisko = nazwisko_;
                this.dataUrodzenia = dataUrodzenia_;
                this.pozycja = pozycja_;
                this.klub = klub_;
            }
            public override void WypiszInfo()
            {
                base.WypiszInfo();
                Console.WriteLine("Pozycja: " + pozycja);
                Console.WriteLine("Klub: " + klub);
                Console.WriteLine("Liczba goli: " + liczbaGoli);
            }
            public void StrzelGola()
            {
                liczbaGoli++;
            }
        }
        class Program
        {
            static void Main(string[] args)
            {
                Osoba o1 = new Osoba("Adam", "Miś", "20.03.1980");
                Osoba o2 = new Student("Michał", "Kot", "13.04.1990", 2, 1, 12345);
                Osoba o3 = new Pilkarz("Mateusz", "Żbik", "10.08.1986", "Obrońca", "FC Czestochowa");
                o1.WypiszInfo();
                Console.WriteLine();
                o2.WypiszInfo();
                Console.WriteLine();
                o3.WypiszInfo();
                Console.WriteLine();
                Student s = new Student("Krzysztof", "Jeż", "22.12.1990", 2, 5, 54321);
                Pilkarz p = new Pilkarz("Piotr", "Kos", "14.09.1984", "Napastnik", "FC Politechnika");
                s.WypiszInfo();
                Console.WriteLine();
                p.WypiszInfo();
                Console.WriteLine();
                ((Pilkarz)o3).StrzelGola();
                p.StrzelGola();
                p.StrzelGola();
                o3.WypiszInfo();
                Console.WriteLine();
                p.WypiszInfo();
                Console.WriteLine("////////////////////////////////");
  //            
            ((Student)o2).DodajOcene("PO", "20.02.2011", 5.0);
            ((Student)o2).DodajOcene("Bazy danych", "13.02.2011", 4.0);

            o2.WypiszInfo();
            s.DodajOcene("Bazy danych", "01.05.2011", 5.0);
            s.DodajOcene("AWWW", "11.05.2011", 5.0);
            s.DodajOcene("AWWW", "02.04.2011", 4.5);
            Console.WriteLine();
            s.WypiszInfo();
            s.UsunOcene("AWWW", "02.04.2011", 4.5);
            s.WypiszInfo();
            Console.WriteLine();
            s.DodajOcene("AWWW", "02.04.2011", 4.5);
            s.UsunOceny("AWWW");
            s.WypiszInfo();
            Console.WriteLine();
            s.DodajOcene("AWWW", "02.04.2011", 4.5);
            s.UsunOceny();
            s.WypiszInfo();
            Console.ReadKey();
            }
        }
    }
