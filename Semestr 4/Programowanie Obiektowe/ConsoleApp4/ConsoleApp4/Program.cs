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
            Console.WriteLine("Osoba:\n IM: " + imie + " NAZ: " + nazwisko + " DAT: " + dataUrodzenia + " ");
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
            Console.WriteLine("Wykladowca:\n IM: " + imie + " NAZ: " + nazwisko + " DAT: "
                + dataUrodzenia + " TYT: " + tytulNaukowy + " ST: " + stanowisko);
        }
    }

    class Student : Osoba, IInfo
    {
        List<OcenaKoncowa> ocenyKoncowe = new List<OcenaKoncowa>();
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
            Console.WriteLine("Student:\n IM: " + imie + " NAZ: " + nazwisko + " DAT: " + dataUrodzenia + " KIER: "
                + kierunek + " S:" + specjalnosc + " R: " + rok + " GR: " + grupa + " INDEX: " + nrIndeksu);
        }
        public bool DodajOcene(Przedmiot przedmiot, double ocena, string data)
        {
            ocenyKoncowe.Add(new OcenaKoncowa(ocena, data, przedmiot));
            return true;
        }
        public void InfoOceny()
        {
            for(int i=0; i<ocenyKoncowe.Count; i++)
            {
                ocenyKoncowe[i].WypiszInfo();
            }
        }
    }

    class Wydzial
    {
        List<Student> studenci = new List<Student>();
        List<Przedmiot> przedmioty = new List<Przedmiot>();
        List<Jednostka> jednostki = new List<Jednostka>();

        public void DodajJednostke(string nazwa, string adres)
        {
            jednostki.Add(new Jednostka(nazwa, adres));
        }
        public void DodajPrzedmiot(Przedmiot przedmiot)
        {
            przedmioty.Add(przedmiot);
        }
        public void DodajStudenta(Student student)
        {
            studenci.Add(student);
        }
        public bool UsunStudenta(int Index_number)
        {
            for (int i = 0; i < studenci.Count; i++)
            {
                if (studenci[i].NrIndeksu == Index_number)
                {
                    studenci.RemoveAt(i);
                    return true;
                }
            }
            return false;
        }
        public void DodajWykladowce(Wykladowca wykladowca, string jednostka)
        {
            for (int i = 0; i < jednostki.Count; i++)
            {
                if(jednostki[i].Nazwa == jednostka)
                {
                    jednostki[i].DodajWykladowce(wykladowca);
                }
            }
        }
        public bool PrzeniesWykladowce(Wykladowca w, string obecnaJednostka, string nowaJednostka)
        {
            for(int i=0; i<jednostki.Count; i++)
            {
                if(jednostki[i].Nazwa == obecnaJednostka)
                {
                    jednostki[i].UsunWykladowce(w);
                }
            }
            for(int i=0; i<jednostki.Count; i++)
            {
                if (jednostki[i].Nazwa == nowaJednostka)
                {
                    jednostki[i].DodajWykladowce(w);
                    return true;
                }
            }
            return false;
        }
        public bool DodajOcene(int numer_indeksu, double ocena, Przedmiot przedmiot, string data)
        {
            for (int i = 0; i < studenci.Count; i++)
            {
                if(numer_indeksu == studenci[i].NrIndeksu)
                {
                    studenci[i].DodajOcene(przedmiot, ocena, data);
                    return true;
                }
            }
            return false;
        }
        public void InfoPrzedmioty()
        {
            for (int i = 0; i < przedmioty.Count; i++)
                przedmioty[i].WypiszInfo();
        }
        public void InfoStudenci(bool infoOceny)
        {       //       studenci.ForEach(i => Console.WriteLine("{0}", i));
            if (studenci.Count == 0)
                Console.WriteLine("Brak studentow na tym wydziale, przepraszamy.");
            else
            {
                if(infoOceny == false)
                {
                    for (int i=0; i<studenci.Count; i++)
                        studenci[i].WypiszInfo();
                }
            else if(infoOceny == true)
                {
                    for(int i=0; i<studenci.Count; i++)
                    {
                        studenci[i].WypiszInfo();
                        studenci[i].InfoOceny();
                    }
                }
            }
        }
        public void InfoJednostki(bool infoWykladowcy)
        {       //       jednostki.ForEach(i => Console.WriteLine("{0}", i));
            if (jednostki.Count == 0)
                Console.WriteLine("Brak jednostek na tym wydziale, przepraszamy.");
            else
            {
                if (infoWykladowcy == false)
                {
                    for(int i=0; i<jednostki.Count; i++)
                        jednostki[i].WypiszInfo();
                }
            else if (infoWykladowcy == true)
                {
                    for(int i=0; i<jednostki.Count; i++)
                        jednostki[i].InfoWykladowcy();
                }
            }
        }
    }
    class Jednostka : IInfo
    {
        List<Wykladowca> wykladowcy = new List<Wykladowca>();
        private string nazwa;
        private string adres;
        public string Nazwa { get { return nazwa; } set { nazwa = value; } }
        public string Adres { get { return adres; } set { adres = value; } }
        public Jednostka() { nazwa = ""; adres = ""; wykladowcy = null; }
        public Jednostka(string naz, string ad) { this.nazwa = naz; this.adres = ad; }

        public void DodajWykladowce(Wykladowca wykladowca)
        {
            wykladowcy.Add(wykladowca);
        }

        public bool UsunWykladowce(Wykladowca wykladowca) // po referencji
        {
            wykladowcy.Remove(wykladowca);
            return true;
        }

        public bool UsunWykladowce(string imie, string nazwisko) // po imieniu i nazwisku
        {
            for (int i = 0; i < wykladowcy.Count; i++)
            {
                if (imie == wykladowcy[i].Imie && nazwisko == wykladowcy[i].Nazwisko)
                {
                    wykladowcy.RemoveAt(i);
                }
            }
            return true;
        }

        public void InfoWykladowcy()
        {
            for (int i = 0; i < wykladowcy.Count; i++)
            {
                wykladowcy[i].WypiszInfo();
            }
        }

        public void WypiszInfo()
        {
            Console.WriteLine(nazwa + " " + adres + " ");
            InfoWykladowcy();
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
            Console.WriteLine("Przedmiot:\n " + nazwa + " K: " + kierunek + " SP: " + specjalnosc
                + " SEM: " + semestr + " H: " + ileGodzin);
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
        public OcenaKoncowa() { wartosc = 0.0; data = ""; przedmiot = null; }
        public OcenaKoncowa(double oc, string dat, Przedmiot p)
        {
            this.wartosc = oc;
            this.data = dat;
            this.przedmiot = p;
        }
        public void WypiszInfo()
        {
            Console.WriteLine("Ocena koncowa:\n P: " + przedmiot.Nazwa + " O: " + wartosc + " D: " + data);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Student student1 = new Student("Kamil", "Michalski", "15.05.1998", "INFORMATYKA", "IO", 3, 2, 1599);
            Student student2 = new Student("Michał", "Gorzelnicki", "30.04.1996", "INFORMATYKA", "IO", 3, 2, 2232);
            Wydzial wydzial = new Wydzial();
            Przedmiot informatyka = new Przedmiot("Informatyka", "INFORMATYCZNY", "IO", 3, 2);
            Przedmiot angielski = new Przedmiot("Język angielski", "HUMANISTYCZNY", "IO", 3, 3);
            Przedmiot chinski = new Przedmiot("Język chiński", "HUMANISTYCZNY", "FILOLOGIA CHIŃSKA", 4, 5);
            Wykladowca wykladowca1 = new Wykladowca("Adam", "Romanowski", "02.02.1976", "Profesor nadzwyczajny", "Dyrektor");
            Wykladowca wykladowca2 = new Wykladowca("Robert", "Michalski", "19.09.1993", "Magister inżynier", "adiunkt");
            Jednostka jed1 = new Jednostka("Politechnika", "Dabrowskiego");
            Jednostka jed2 = new Jednostka("Uniwersytet", "Wodzickiego");
            student1.WypiszInfo();
            
            student1.DodajOcene(chinski, 3.5, "02.03.2019");
            student1.InfoOceny();
            Console.WriteLine();
            wykladowca1.WypiszInfo();
            Console.WriteLine();
            jed1.DodajWykladowce(wykladowca1);
            jed2.DodajWykladowce(wykladowca1);
            jed2.DodajWykladowce(wykladowca2);
            jed1.WypiszInfo();
            Console.WriteLine();
            jed2.WypiszInfo();
            Console.WriteLine();
            jed1.InfoWykladowcy();
            Console.WriteLine();
            jed2.InfoWykladowcy();
            Console.WriteLine();

            wydzial.DodajJednostke("Politechnika", "Dabrowskiego");
            wydzial.DodajPrzedmiot(informatyka);
            wydzial.DodajPrzedmiot(angielski);
            wydzial.DodajStudenta(student1);
            wydzial.DodajStudenta(student2);
            wydzial.DodajWykladowce(wykladowca1, "Politechnika");
            wydzial.DodajWykladowce(wykladowca2, "Politechnika");
            wydzial.InfoStudenci(false);
            Console.WriteLine();
            wydzial.InfoJednostki(true);
            Console.WriteLine();
            wydzial.InfoJednostki(false);
            Console.WriteLine();
            wydzial.InfoPrzedmioty();
            Console.WriteLine();
            wydzial.DodajOcene(1599, 5.0, informatyka, "21.03.2019");
            wydzial.DodajOcene(2232, 4.5, angielski, "22.03.2019");
            wydzial.InfoStudenci(true);
            Console.WriteLine();
            wydzial.UsunStudenta(1599);
            wydzial.InfoStudenci(true);
            Console.WriteLine();
            wydzial.DodajJednostke("Najlepsza", "Jednocha");
            wydzial.PrzeniesWykladowce(wykladowca1, "Politechnika", "Jednocha");
            wydzial.InfoJednostki(false);
            Console.WriteLine();
            Console.ReadKey();
        }
    }
}
