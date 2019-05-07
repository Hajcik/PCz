using System;
using System.Collections.Generic;
namespace ConsoleApp5
{
    class Zoo
    {
        List<Klatka> klatki_zoo = new List<Klatka>();
        List<Opiekun> opiekunowie = new List<Opiekun>();
        public void DodajKlatke(Klatka klatka, Opiekun opiekun)
        {
            klatki_zoo.Add(klatka);
            opiekun.DodajKlatke(klatka);
        }
        public void PowiekszKlatke(Klatka klatka, int pojemnosc)
        {
            klatka.Pojemnosc = pojemnosc;
        }
        public void NowyOpiekun(Opiekun opiekun)
        {
            opiekunowie.Add(opiekun);
        }
        public void UmiescZwierze(Zwierze zwierze, Klatka klatka)
        {
            klatka.DodajZwierze(zwierze);
        }
        public void WypiszInfoKlatek()
        {
            if(klatki_zoo.Count != 0)
            {
                for(int i = 0; i<klatki_zoo.Count; i++)
                {
                    klatki_zoo[i].WypiszInfo();
                }
            }
            else
            {
                Console.WriteLine("Brak klatek");
            }
        }
    }

    class Opiekun
    {
        List<Klatka> klatki_op = new List<Klatka>();
        private string imie;
        private string nazwisko;
        public string Imie { get { return imie; } set { imie = value; } }
        public string Nazwisko { get { return nazwisko; } set { nazwisko = value; } }
        public Opiekun() { imie = ""; nazwisko = ""; }
        public Opiekun(string im, string naz) { this.imie = im; this.nazwisko = naz; }
        public void PosprzatajKlatki()
        {
            for (int i = 0; i < klatki_op.Count; i++)
            {
                klatki_op[i].PosprzatajKlatke();
            }
        }
        public void DodajKlatke(Klatka klatka)
        {
            klatki_op.Add(klatka);
        }
        public void WypiszInfo()
        {
            Console.WriteLine("Nazwisko: " + Nazwisko + "Przydzielone klatki: ");
            for (int i = 0; i < klatki_op.Count; i++)
            {
                Console.WriteLine("ID: " + klatki_op[i].ID_Klatki);
            }
        }
    }
    class Klatka
    {
        List<Zwierze> zwierzeta = new List<Zwierze>();
        private int pojemnosc;
        private int id_klatki;
        public int Pojemnosc { get { return pojemnosc; } set { pojemnosc = value; } }
        public int ID_Klatki { get { return id_klatki; } set { id_klatki = value; } }
        public Klatka() { pojemnosc = 0; id_klatki = 0; }
        public Klatka(int poj, int id) { this.pojemnosc = poj; this.id_klatki = id; }
        public void PosprzatajKlatke()
        {
            Console.WriteLine("Posprzatana zostala klatka o numerze ID: " + id_klatki);
        }
        public bool DodajZwierze(Zwierze zwierze)
        {
            if(zwierzeta.Count < pojemnosc)
            {
                zwierzeta.Add(zwierze);
                return true;
            }
            else
            {
                Console.WriteLine("Pelna klatka");
                return false;
            }
        }
        public void WypiszInfo()
        {
            Console.WriteLine("ID klatki: " + ID_Klatki + " Pojemnosc: " + Pojemnosc);
            for(int i = 0; i<zwierzeta.Count; i++)
            {
                zwierzeta[i].WypiszInfo();
            }
        }
    }
    abstract class Zwierze
    {
        private string gatunek;
        private string pozywienie;
        private string pochodzenie;
        public string Gatunek { get { return gatunek; } set { gatunek = value; } }
        public string Pozywienie { get { return pozywienie; } set { pozywienie = value; } }
        public string Pochodzenie { get { return pochodzenie; } set { pochodzenie = value; } }
        public Zwierze()
        { gatunek = ""; pozywienie = ""; pochodzenie = ""; }
        public Zwierze(string gat, string poz, string poc)
        { this.gatunek = gat; this.pozywienie = poz; this.pochodzenie = poc; }
        public abstract void WypiszInfo();
    }

    class Ssak : Zwierze
    {
        private string srodowisko;
        public string Srodowisko { get { return srodowisko; } set { srodowisko = value; } }
        public Ssak() : base() { srodowisko = ""; }
        public Ssak(string gat, string poz, string poc, string srod) : base(gat, poz, poc) { this.srodowisko = srod; }
        public override void WypiszInfo()
        {
            Console.WriteLine("Gatunek: " + Gatunek + " " + " Pozywienie: " + Pozywienie +
               " Pochodzenie: " + Pochodzenie + " Srodowisko: " + Srodowisko);
        }
    }

    class Ptak : Zwierze
    {
        private float rozpietosc;
        private float wytrzymalosc;
        private string zdolnosc;
        public float Rozpietosc { get { return rozpietosc; } set { rozpietosc = value; } }
        public float Wytrzymalosc { get { return wytrzymalosc; } set { wytrzymalosc = value; } }
        public string Zdolnosc { get { return zdolnosc; } set { zdolnosc = value; } }
        public Ptak() : base() { rozpietosc = 0.0f; wytrzymalosc = 0.0f; zdolnosc = "none"; }
        public Ptak(string gat, string poz, string poc, float roz, float wyt, string zd) : base(gat, poz, poc)
        { this.rozpietosc = roz; this.wytrzymalosc = wyt; this.zdolnosc = zd; }
        public double MaxDlugoscLotu(double rozpietosc, double wytrzymalosc)
        { 
            return rozpietosc* wytrzymalosc;
        }
        public override void WypiszInfo()
        {
            Console.WriteLine("Gatunek: " + Gatunek + " " + " Pozywienie: " + Pozywienie + " Pochodzenie: " + Pochodzenie
                + " Rozpietosc: " + Rozpietosc + " Wytrzymalosc: " + Wytrzymalosc);
            Console.WriteLine("Dlugosc lotu: " + MaxDlugoscLotu(rozpietosc, wytrzymalosc));
        }
    }
    class Gad : Zwierze
    {
        private bool jadowitosc;
        public bool Jadowitosc { get { return jadowitosc; } set { jadowitosc = value; } }
        public Gad() : base() { jadowitosc = false; }
        public Gad(string gat, string poz, string poc, bool jad) : base(gat, poz, poc)
        { this.jadowitosc = jad; }

        public bool CzyGadJadowity()
        {
            if (jadowitosc == true)
            { return true; }
            else return false;
        }
        public override void WypiszInfo()
        {
            Console.WriteLine("Gatunek: " + Gatunek + " " + " Pozywienie: " + Pozywienie +
                " Pochodzenie: " + Pochodzenie + " Jadowity: " + Jadowitosc);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {

            Opiekun Artur = new Opiekun("ARTUR","MIRKOWSKI");
            Opiekun Krystian = new Opiekun("KRYSTIAN", "ZABOLAŁO");
            Zwierze orzel = new Ptak("PTAK", "ROBAKI", "POLSKA",  10.2f, 2.3f, "SZYBKI CHWYT");
            Zwierze waz = new Gad("GAD", "KRÓLIK", "AMERYKA", true);
            Zwierze koala = new Ssak("SSAK", "EUKALIPTUS", "AFRYKA", "DRZEWO");
            Klatka klatka1 = new Klatka(5, 1);
            Klatka klatka2 = new Klatka(1, 2);
            Zoo zoo = new Zoo();
            zoo.WypiszInfoKlatek();
            zoo.NowyOpiekun(Artur);
            zoo.NowyOpiekun(Krystian);
            zoo.DodajKlatke(klatka1, Artur);
            zoo.DodajKlatke(klatka2, Krystian);
            zoo.UmiescZwierze(orzel, klatka1);
            zoo.UmiescZwierze(waz, klatka2);
            zoo.UmiescZwierze(koala, klatka1);
            zoo.WypiszInfoKlatek();
            Console.WriteLine();
            zoo.PowiekszKlatke(klatka2, 2);
            zoo.WypiszInfoKlatek();
            Krystian.PosprzatajKlatki();
            Artur.PosprzatajKlatki();


            Console.ReadKey();
            Console.WriteLine("Hello World!");
        }
    }
}
