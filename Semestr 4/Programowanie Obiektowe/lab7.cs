using System;
using System.Collections.Generic;
namespace ConsoleApp5
{
    class Zoo
    {
        List<Klatka> klatki_zoo = new List<Klatka>();
        List<Opiekun> opiekunowie = new List<Opiekun>();
        public void NowaKlatka(Klatka klatka)
        {
            klatki_zoo.Add(klatka);
        }
        public void PowiekszKlatke()
        {

        }
        public void NowyOpiekun(Opiekun opiekun)
        {
            opiekunowie.Add(opiekun);
        }
        public void NoweZwierze()
        {
             
        }
        public void WypiszInfo()
        {

        }
    }

    class Opiekun
    {
        List<Klatka> klatki_op = new List<Klatka>();
        private string imie;
        private string nazwisko;
        public string Imie { get { return imie; } set { imie = value; } }
        public string Nazwisko { get { return nazwisko; } set { nazwisko = value; } }
        public void PosprzatajKlatki()
        {
            for(int i = 0; i<klatki_op.Count; i++)
            {
                klatki_op[i].PosprzatajKlatke();
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
            Console.WriteLine()
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
        {   gatunek = ""; pozywienie = ""; pochodzenie = "";    }
        public Zwierze(string gat, string poz, string poc)
        {   this.gatunek = gat; this.pozywienie = poz; this.pochodzenie = poc;   }
    }

    class Ssak : Zwierze
    {
        private string srodowisko;
        public string Srodowisko { get { return srodowisko; } set { srodowisko = value; } }
        public Ssak() :base() { srodowisko = ""; }
        public Ssak(string gat, string poz, string poc, string srod) :base(gat, poz, poc) { this.srodowisko = srod; }
    }

    class Ptak : Zwierze
    {
        private float rozpietosc;
        private float wytrzymalosc;
        private string zdolnosc;
        public float Rozpietosc { get { return rozpietosc; } set { rozpietosc = value; } }
        public float Wytrzymalosc { get { return wytrzymalosc; } set { wytrzymalosc = value; } }
        public string Zdolnosc { get { return zdolnosc; } set { zdolnosc = value; } }
        public Ptak() :base() { rozpietosc = 0.0f; wytrzymalosc = 0.0f; }
        public Ptak(string gat, string poz, string poc, float roz, float wyt, string zd) :base(gat, poz, poc)
        {   this.rozpietosc = roz; this.wytrzymalosc = wyt; this.zdolnosc = zd; }
        public void MaxDlugoscLotu()
        {   Console.WriteLine("Ten ptak " + Gatunek + "moze leciec najwiecej " + rozpietosc*wytrzymalosc + "[j]"); }
    }
    class Gad : Zwierze
    {
        private bool jadowitosc;
        public bool Jadowitosc { get { return jadowitosc; } set { jadowitosc = value; } }
        public Gad() :base() { jadowitosc = false; }
        public Gad(string gat, string poz, string poc, bool jad) :base (gat, poz, poc)
        { this.jadowitosc = jad; }

        public bool CzyGadJadowity()
        {
            if (jadowitosc == true)
            { return true; }
            else return false;
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
