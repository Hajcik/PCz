using System;

namespace Lab4MJ
{   class Element
    {
        private object wartosc;
        public object Wartosc
        {   get { return wartosc; }
            set { wartosc = value;}
        }
        private Element nastepnyElement;
        public Element NastepnyElement
        {
            get { return nastepnyElement;  }
            set { nastepnyElement = value; }
        }
        public Element() { wartosc = 0; }
        public Element(object _w) { this.wartosc = _w; }
    }
    class Kolejka
    {
        private Element pierwszyElement;
        private Element ostatniElement;
        private int liczbaElementow;
        public Element PierwszyElement
        {
            get { return pierwszyElement;  }
            set { pierwszyElement = value; }
        }
        public Element OstatniElement
        {
            get { return ostatniElement;  }
            set { ostatniElement = value; }
        }
        public int LiczbaElementow
        {
            get { return liczbaElementow;  }
            set { liczbaElementow = value; }
        }
        public Kolejka()
        {
            pierwszyElement = null;
            ostatniElement  = null;
            liczbaElementow = 0;
        }
        public Kolejka(Element p, Element o, int l)
        {
            this.pierwszyElement = p;
            this.ostatniElement = o;
            this.liczbaElementow = l;
        }
        public void Dodaj(object wartosc)
        {
            if(pierwszyElement == null)
            {
                Element e = new Element(wartosc);
                pierwszyElement = e;
                ostatniElement = e;
                liczbaElementow++;
            }
            else      
            {
                Element e = new Element(wartosc);
                ostatniElement.NastepnyElement = e;
                ostatniElement = e;
                liczbaElementow++;
            }
        }
        public object Pobierz()
        {
            Element e = pierwszyElement;
            pierwszyElement = pierwszyElement.NastepnyElement;
            return e.Wartosc;
        }
        public void Wyswietl()
        {
            Element e = pierwszyElement;
            while(e != null)
            {
                Console.WriteLine(e.Wartosc);
                e = e.NastepnyElement;
            }

        }
    }
    class Program
    {
        static void Main(string[] args)
        {
                Kolejka k = new Kolejka();
                k.Dodaj(1);
                k.Dodaj(5);
                k.Dodaj(3);
                k.Dodaj(8);
                k.Wyswietl();
                Console.WriteLine("Liczba elementow: {0}", k.LiczbaElementow);
                int element = (int)k.Pobierz();
                Console.WriteLine("Pobrany element: {0}", element);
                k.Wyswietl();
                Console.WriteLine("Liczba elementow: {0}", k.LiczbaElementow);
                k.Dodaj(7);
                k.Dodaj(4);
                k.Wyswietl();
                Console.WriteLine("Liczba elementow: {0}", k.LiczbaElementow);
                element = (int)k.Pobierz();
                Console.WriteLine("Pobrany element: {0}", element);
                k.Wyswietl();
                Console.WriteLine("Liczba elementow: {0}", k.LiczbaElementow); 
            Console.ReadKey(); 
        }
    }
}
