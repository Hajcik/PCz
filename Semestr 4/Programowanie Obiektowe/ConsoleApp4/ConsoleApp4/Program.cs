using System;
using System.Collections.Generic;
using System.Linq;

namespace ConsoleApp4
{
    interface IInfo
    {
        void WypiszInfo();
    }
    class Osoba : IInfo
    {
        protected string imie;
        protected string nazwisko;
        protected string dataUrodzenia;
        public string Imie { get { return imie; } set { imie = value; } }
        public string Nazwisko { get { return nazwisko; } set { nazwisko = value; } }
        public string DataUrodzenia { get { return dataUrodzenia; } set { dataUrodzenia = value; } }
        public Osoba() { imie = ""; nazwisko = ""; dataUrodzenia = ""; }
        public Osoba(string im, string naz, string dat)
        {
            this.imie = im;
            this.nazwisko = naz;
            this.dataUrodzenia = dat;
        }
        public virtual void WypiszInfo()
        {
            Console.WriteLine("Osoba: " + imie + " " + nazwisko + " " + dataUrodzenia + " ");
        }
    }

    class Wykladowca : Osoba, IInfo
    {
        private string tytulNaukowy;
        private string stanowisko;
        public string TytulNaukowy { get { return tytulNaukowy; } set { tytulNaukowy = value; } }
        public string Stanowisko { get { return stanowisko; } set { stanowisko = value; } }
        public Wykladowca() : base() { tytulNaukowy = ""; stanowisko = ""; }
        public Wykladowca(string im, string naz, string dat, string tyt, string st) : base(im, naz, dat)
        {
            this.tytulNaukowy = tyt;
            this.stanowisko = st;
        }
        public override void WypiszInfo()
        {
            Console.WriteLine("Wykladowca: " + imie + " "
                + nazwisko + " "
                + dataUrodzenia + " "
                + tytulNaukowy + " "
                + stanowisko);
        }
    }
    class Student : Osoba, IInfo
    {
        private string kierunek;
        private string specjalnosc;
        private int rok;
        private int grupa;
        private int nrIndeksu;
        public string Kierunek { get { return kierunek; } set { kierunek = value; } }
        public string Specjalnosc { get { return specjalnosc; } set { specjalnosc = value; } }
        public int Rok { get { return rok; } set { rok = value; } }
        public int Grupa { get { return grupa; } set { grupa = value; } }
        public int NrIndeksu { get { return nrIndeksu; } set { nrIndeksu = value; } }
        public Student() : base() { }
        public Student(string im, string naz, string dat, string kie, string spec, int r, int gr, int index) : base(im, naz, dat)
        {
            this.kierunek = kie;
            this.specjalnosc = spec;
            this.rok = r;
            this.grupa = gr;
            this.nrIndeksu = index;
        }
        public override void WypiszInfo()
        {
            Console.WriteLine("Student: " + imie + " " + nazwisko + " " + dataUrodzenia + " "
                + kierunek + " " + specjalnosc + " " + rok + " " + grupa + " " + nrIndeksu);
        }
        public void InfoOceny()
        {

        }
    }
    class Wydzial
    {
        public void DodajJednostke(string nazwa, string adres)
        {

        }
        public void DodajPrzedmiot(Przedmiot p)
        {

        }
        public void DodajStudenta(Student s)
        {

        }
        public void DodajWykladowce(Wykladowca w)
        {

        }
    }
    class Jednostka : IInfo
    {
        private string nazwa;
        private string adres;
        public string Nazwa { get { return nazwa; } set { nazwa = value; } }
        public string Adres { get { return adres; } set { adres = value; } }
        public Jednostka() { nazwa = ""; adres = ""; }
        public Jednostka(string naz, string ad) { this.nazwa = naz; this.adres = ad; }
        public void DodajWykladowce(Wykladowca wyk)
        {

        }
        public bool UsunWykladowce(Wykladowca wyk) // po referencji
        {
            return true;
        }
        public bool UsunWykladowce(string imie, string nazwisko) // po imieniu i nazwisku
        {
            return true;
        }
        public void InfoWykladowca()
        {

        }
        public void WypiszInfo()
        {

        }
    }
    public class Przedmiot : IInfo
    {
        private string nazwa;
        private string kierunek;
        private string specjalnosc;
        private int semestr;
        private int ileGodzin;
        public string Nazwa { get { return nazwa; } set { nazwa = value; } }
        public string Kierunek { get { return kierunek; } set { kierunek = value; } }
        public string Specjalnosc { get { return specjalnosc; } set { specjalnosc = value; } }
        public int Semestr { get { return semestr; } set { semestr = value; } }
        public int IleGodzin { get { return semestr; } set { semestr = value; } }
        public Przedmiot() { nazwa = ""; kierunek = ""; specjalnosc = ""; semestr = 0; ileGodzin = 0; }
        public Przedmiot(string naz, string kie, string spec, int sem, int h)
        {
            this.nazwa = naz;
            this.kierunek = kie;
            this.specjalnosc = spec;
            this.semestr = sem;
            this.ileGodzin = h;
        }

        public void WypiszInfo()
        {
            Console.WriteLine("Przedmiot: " + nazwa + " " + kierunek + " " + specjalnosc
                + " " + semestr + " " + ileGodzin);
        }
    }
    public class OcenaKoncowa : IInfo
    {
        private double wartosc;
        private string data;
        private Przedmiot przedmiot;
        public double Wartosc { get { return wartosc; } set { wartosc = value; } }
        public string Data { get { return data; } set { data = value; } }
        public Przedmiot _Przedmiot { get { return przedmiot; } set { przedmiot = value; } }
        public OcenaKoncowa() { }
        public OcenaKoncowa(double oc, string dat, Przedmiot p)
        {
            this.wartosc = oc;
            this.data = dat;
            this.przedmiot = p;
        }
        public void WypiszInfo()
        {
            Console.WriteLine("Ocena koncowa: " + przedmiot + " " + wartosc + " " + data);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
        }
    }
}
