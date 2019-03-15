using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
namespace lab3po
{
    interface IZarzadzaniePozycjami
    {
        Pozycja ZnajdzPozycjePoTytule(string a);
        Pozycja ZnajdzPozycjePoID(int b);
        void WypiszWszystkiePozycje();
    }
    class Biblioteka : IZarzadzaniePozycjami
    {
        private List<Bibliotekarz> bibliotekarze = new List<Bibliotekarz>();
        private List<Katalog> katalogi = new List<Katalog>();
        private List<Pozycja> pozycja = new List<Pozycja>();
        public Pozycja ZnajdzPozycjePoTytule(string pozycja)
        {
            for(int i=0; i<katalogi.Count; i++)
            {
                return katalogi[i].ZnajdzPozycjePoTytule(pozycja);
            }
            return null;
        }
        public Pozycja ZnajdzPozycjePoID(int ID)
        {
            Console.WriteLine("\nSzukana ksiazka po numerze identyfikacyjnym jest: ");
            for (int i = 0; i < pozycja.Count; i++)
            {
                if (ID == pozycja[i].Id) { return pozycja[i]; }
            }
            return null;
        }
        public void WypiszWszystkiePozycje() { }
        private string adres; public string Adres { get { return adres; } set { adres = value; } }
        public Biblioteka() { adres = "NIEZNANY"; }
        public Biblioteka(string AD) { this.adres = AD; }
        public void DodajBibliotekarza(Bibliotekarz bib) { bibliotekarze.Add(bib); }
        public void WypiszBibliotekarzy()
        { bibliotekarze.Sort();
            Console.WriteLine("Bibliotekarze: ");
            for (int i = 0; i < bibliotekarze.Count; i++)
            {
                Console.WriteLine("Imie i nazwisko: "
                    + bibliotekarze[i].Imie + " " + bibliotekarze[i].Nazwisko +
                    "\nData zatrudnienia: " + bibliotekarze[i].DataZatrudnienia
                    + "\nWynagrodzenie: " + bibliotekarze[i].Wynagrodzenie);
            }
        }
        public void DodajKatalog(Katalog kat) { katalogi.Add(kat); }
        public void DodajPozycje(Pozycja p, string dzialTematyczny)
        {
            for(int i=0; i<katalogi.Count; i++)
            {
                if (katalogi[i].DzialTematyczny == dzialTematyczny)
                {
                    katalogi[i].DodajPozycje(p);
                }
            }
        }
    }
    class Bibliotekarz : Osoba
    {
        private string dataZatrudnienia;
        private double wynagrodzenie;
        public string DataZatrudnienia { get { return dataZatrudnienia; } set { dataZatrudnienia = value; } }
        public double Wynagrodzenie { get { return wynagrodzenie; } set { wynagrodzenie = value; } }
        public Bibliotekarz() :base() { dataZatrudnienia = "nieznana data"; wynagrodzenie = 0.0; }
        public Bibliotekarz(string im, string naz, string dat, double wyn) : base(im, naz)
        { this.dataZatrudnienia = dat; this.wynagrodzenie = wyn; }
    }
    class Autor : Osoba
    {
        private string narodowosc;
        public string Narodowosc { get { return narodowosc; } set { narodowosc = value; } }
        public Autor() : base() { narodowosc = "nieznana"; }
        public Autor(string im, string naz, string nar) : base(im, naz) { this.narodowosc = nar; }
    }
    class Osoba
    {
        protected string imie;
        protected string nazwisko;
        public string Imie { get { return imie; } set { imie = value; } }
        public string Nazwisko { get { return nazwisko; } set { nazwisko = value; } }
        public Osoba() { imie = "nieznane imie"; nazwisko = "nieznane nazwisko"; }
        public Osoba(string im, string naz) { this.imie = im; this.nazwisko = naz; }
    }
    class Katalog : IZarzadzaniePozycjami
    {
        public void ZnajdzPozycjePoTytule(string pozycja)
        {
        }
        public Pozycja ZnajdzPozycjePoID(int ID)
        {
            Console.WriteLine("\nSzukana ksiazka po numerze identyfikacyjnym jest: ");
            for (int i = 0; i < pozycja.Count; i++)
            {
                if (ID == pozycja[i].Id) { return pozycja[i]; }
            }
            return null;
        }
        public void WypiszWszystkiePozycje()
        {
            //  pozycja.Sort();                                           
            //  pozycja.ForEach(Console.WriteLine);
            pozycja.Sort();
            for (int i = 0; i < pozycja.Count; i++)
            {
                Console.WriteLine(
                      "Pozycja numer: " + (i + 1)
                    + "\nID: " + pozycja[i].Id
                    + "\nTytul pozycji: " + pozycja[i].Tytul
                    + "\nWydawnictwo: " + pozycja[i].Wydawnictwo
                    + "\nRok wydania: " + pozycja[i].RokWydania + "\n****************");
            }
        }
        private string dzialTematyczny;
        public string DzialTematyczny { get { return dzialTematyczny; } set { dzialTematyczny = value; } }
        public Katalog() { dzialTematyczny = "nieznany"; }
        public Katalog(string dzT) { this.dzialTematyczny = dzT; }
        private List<Pozycja> pozycja = new List<Pozycja>();
        public void DodajPozycje(Pozycja p)
        {
            pozycja.Add(p);
        }
    }
    abstract class Pozycja
    {
        protected string tytul;
        protected int id;
        protected string wydawnictwo;
        protected int rokWydania;
        public string Tytul { get { return tytul; } set { tytul = value; } }
        public int Id { get { return id; } set { id = value; } }
        public string Wydawnictwo { get { return wydawnictwo; } set { wydawnictwo = value; } }
        public int RokWydania { get { return rokWydania; } set { rokWydania = value; } }
        public Pozycja() { tytul = "nieznany"; id = 0; wydawnictwo = "nieznane"; rokWydania = 0; }
        public Pozycja(string tyt, int id_, string wyd, int rok)
        {
            this.tytul = tyt;
            this.id = id_;
            this.wydawnictwo = wyd;
            this.rokWydania = rok;
        }
        public abstract void WypiszInfo();
    }
    class Ksiazka : Pozycja
    {
        private int liczbaStron;
        public int LiczbaStron { get { return liczbaStron; } set { liczbaStron = value; } }
        private List<Autor> autorzy = new List<Autor>();
        public Ksiazka() : base() { }
        public Ksiazka(string tytul, int id, string wydawnictwo, int rokWydania, int liczbaStron_)
        {
            base.tytul = tytul; base.id = id; base.wydawnictwo = wydawnictwo;
            base.rokWydania = rokWydania; this.liczbaStron = liczbaStron_;
        }
        public override void WypiszInfo()
        {
            Console.WriteLine("Tytul ksiazki: " + tytul);
            Console.WriteLine("ID Ksiazki: " + id);
            Console.WriteLine("Wydawnictwo: " + wydawnictwo);
            Console.WriteLine("Rok wydania: " + rokWydania);
            Console.WriteLine("Liczba stron: " + liczbaStron);
            Console.WriteLine();
            //  throw new NotImplementedException();
        }
        public void DodajAutora(Autor aut)
        {
            autorzy.Add(aut);
        }
    }
    class Czasopismo : Pozycja
    {
        private int numer; public int Numer { get { return numer; } set { numer = value; } }
        public Czasopismo() : base() { }
        public Czasopismo(string tytul, int id, string wydawnictwo, int rokWydania, int numer_)
        {
            base.tytul = tytul; base.id = id; base.wydawnictwo = wydawnictwo;
            base.rokWydania = rokWydania; this.numer = numer_;
        }
        public override void WypiszInfo()
        {
            Console.WriteLine("Tytul czasopisma: " + tytul);
            Console.WriteLine("ID Ksiazki: " + id);
            Console.WriteLine("Wydawnictwo: " + wydawnictwo);
            Console.WriteLine("Rok wydania: " + rokWydania);
            Console.WriteLine("Numer: " + numer);
            Console.WriteLine();
            //   throw new NotImplementedException();
        }
    }
   
    class Program
    {
        static void Main(string[] args)
        {
            Katalog katalog = new Katalog("Wszystko");
            Pozycja pozycja1 = new Ksiazka("Pan Tadeusz", 5, "Helion", 1958, 430);
            Pozycja pozycja2 = new Czasopismo("Przyjaciolka", 4, "HEYAH", 2018, 5);
            Pozycja pozycja3 = new Ksiazka("Lalka", 16, "Lol", 1967, 500);
            Autor autor1 = new Autor("Henryk", "Sienkiewicz", "Polska");
            Autor autor2 = new Autor("Harlan", "Coben", "USA");
            katalog.DodajPozycje(pozycja1);
            katalog.DodajPozycje(pozycja2);
            pozycja1.WypiszInfo();
            pozycja2.WypiszInfo();
            pozycja3.WypiszInfo();
            Console.WriteLine("*******************************");
            katalog.WypiszWszystkiePozycje();
            Ksiazka ksiazka1 = new Ksiazka("Zbrodnia i kara", 90, "Ruska", 1957, 345);
            Czasopismo czasopismo1 = new Czasopismo("CD-Action", 123, "Polskie", 2019, 90);
            ksiazka1.DodajAutora(autor2);
            ksiazka1.WypiszInfo();
            czasopismo1.WypiszInfo();
            Console.WriteLine();
            Pozycja szukamy = katalog.ZnajdzPozycje(5);
            szukamy.WypiszInfo();
            Console.ReadKey();
        }
    }
}
