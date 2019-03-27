using System;
using System.Collections.Generic;
using System.Threading.Tasks;
using System.Linq;
namespace ConsoleApp2
{
    class Osoba
    {
        private string imie;
        private string nazwisko;
        private List<Osoba> lista_osob = new List<Osoba>();
        public string Imie
        {
            get { return imie; }
            set { imie = value; }
        }
        public string Nazwisko
        {
            get { return nazwisko; }
            set { nazwisko = value; }
        }
    public Osoba() { imie = "default"; nazwisko = "default"; }
    public Osoba(string im, string naz) { this.imie = im; this.nazwisko = naz; }
    public void WypiszInfo()
        { Console.WriteLine("Imie: " + imie + "\nNazwisko: " + nazwisko); }
    }

    class Element
    {
        private Osoba wartosc;
        private Element nastepnyElement;
        public Osoba Wartosc
        {
            get { return wartosc; }
            set { wartosc = value; }
        }
        public Element NastepnyElement
        {
            get { return nastepnyElement; }
            set { nastepnyElement = value; }
        }
        public Element(Osoba w)
        {
            this.wartosc = w;
            this.nastepnyElement = null;
        }
    }
    class Lista
    {
        private Element pierwszyElement;
        private int liczbaElementow;
        public Element PierwszyElement
        {
            get { return pierwszyElement; }
            set { pierwszyElement = value; }
        }
        public int LiczbaElementow
        {
            get { return liczbaElementow; }
            set { liczbaElementow = value; }
        }
        public Lista()
        {
            pierwszyElement = null;
            liczbaElementow = 0;
        }
        public Lista(Element p, int l)
        {
            this.pierwszyElement = p;
            this.liczbaElementow = l;
        }
        public void Dodaj(Osoba wartosc)
        {
            if(pierwszyElement == null)
            {
                Element e = new Element(wartosc);
                pierwszyElement = e;
                liczbaElementow++;
            }
            else
            {
                Element e = pierwszyElement;
                while(e.NastepnyElement != null)
                {
                    e = e.NastepnyElement;
                }
                e.NastepnyElement = new Element(wartosc);
                liczbaElementow++;
            }
        }
        public Osoba Pobierz(int index)
        {
            
            if (index == 0)
            {
                Osoba result = pierwszyElement.Wartosc;
                pierwszyElement = pierwszyElement.NastepnyElement;
                return result;
            }
            else
            {
                    Element poprzedni = pierwszyElement;
                    Element result = pierwszyElement.NastepnyElement;
                    for(int i=2; i<index; i++)
                    {
                        poprzedni = result;
                        result = result.NastepnyElement;
                    }
                    poprzedni.NastepnyElement = result.NastepnyElement;
                    liczbaElementow--;
                    return result.Wartosc;
            }
        }
        
        public void Wypisz()
        {
            Element e = pierwszyElement;
            while (e != null)
            {
                e.Wartosc.WypiszInfo();
                e = e.NastepnyElement;
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Osoba o1 = new Osoba("Alicja", "xD");
            Osoba o2 = new Osoba("Marek", "Mirek");
            Osoba o3 = new Osoba("Kac", "Balagan");
            Osoba o4 = new Osoba("Karolek", "Matolek");
            Lista l = new Lista();
            l.Dodaj(o1);
            l.Dodaj(o2);
            l.Dodaj(o3);
            l.Dodaj(o4);

            l.Wypisz();

            l.Pobierz(2);
            l.Pobierz(0);
            l.Pobierz(1);

            l.Wypisz();
            Console.ReadKey();
    //        l.Wstaw(o3, 0);
    //       l.Wstaw(o4, 1);
    //        l.Wstaw(o1, 2);

    //        l.Wypisz();
        }
    }
}

/*
 * private Osoba osoba_first;
        private Osoba osoba_last;
        private uint osoba_amount;
        public Osoba Osoba_First
        {
            get { return osoba_first; }
            set { osoba_first = value; }
        }
        public Osoba Osoba_Last
        {
            get { return osoba_last; }
            set { osoba_last = value; }
        }
        public uint Osoba_Amount
        {
            get { return osoba_amount; }
            set { osoba_amount = value; }
        }
    public Lista()
        {
            osoba_first = null;
            osoba_last = null;
            osoba_amount = 0;
        }
    public Lista(Osoba f, Osoba l, uint a)
        {
            this.osoba_first = f;
            this.osoba_last = l;
            this.osoba_amount = a;
        }
    public void Add_Osoba(object person)
        {
            if(osoba_first == null)
            {
                Osoba p = new Osoba(person);
                osoba_first = p;
                osoba_last = p;
                osoba_amount++;
            }
        }
*/
