using System;
using System.Collections.Generic;
using System.Linq;
using System.Xml.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp24
{
    class Program
    {
        public class Waluta
        {
            public string nazwa { get; set; }
            public float kursKupna { get; set; }
            public float kursSprzedazy { get; set; }
            public string kod { get; set; }

            public Waluta() { }
            public Waluta(string naz, float kursK, float kursS, string kod_)
            {
                nazwa = naz;
                kursKupna = kursK;
                kursSprzedazy = kursS;
                kod = kod_;
            }

            public override string ToString()
            {
                return nazwa + " : " + kursKupna.ToString() + "PLN";
            }
        }
        public class Repozytorium
        {
            public List<Waluta> WczytajWaluty(string locFile = @"..\..\..\waluty.xml")
            {
                List<Waluta> lista = new List<Waluta>();
                XDocument loadFromDisk = XDocument.Load(locFile);
                foreach (var item in loadFromDisk.Elements().Elements("pozycja"))
                {
                    Waluta TWaluta = new Waluta();
                    TWaluta.nazwa = item.Elements("nazwa_waluty").FirstOrDefault().Value;
                    TWaluta.kod = item.Elements("kod_waluty").FirstOrDefault().Value;
                    TWaluta.kursKupna =
                    float.Parse(item.Elements("kurs_kupna").FirstOrDefault().Value);
                    TWaluta.kursSprzedazy =
                    float.Parse(item.Elements("kurs_sprzedazy").FirstOrDefault().Value);
                    lista.Add(TWaluta);
                }
                return lista;
            }
        }
        static void Main(string[] args)
            {
                //    Waluta PLN = new Waluta("PLN", 1.0f, 1.5f, "23");
                //    Waluta EUR = new Waluta("EUR", 3.45f, 4.21f, "25");
                //    Waluta USD = new Waluta("USD", 2.98f, 3.21f, "27");
                Repozytorium repo = new Repozytorium();
                List<Waluta> lista = new List<Waluta>();
                lista = repo.WczytajWaluty();
                System.Nullable<float> q3 = (from n in lista
                                             select n.kursKupna).Min();
                System.Nullable<float> q4 = (from n in lista
                                             select n.kursKupna).Max();
                Console.WriteLine("Kurs kupna minimalny: " + q3);
                Console.WriteLine("Kurs kupna maksymalny: " + q4);



                //  Tworzymy listę int z losowymi wartościami
                List<int> liczby = new List<int>();
                Random rnd = new Random();

                
                // Inny sposób dodawania wartości do listy bez Linq:
                // for (int i = 0; i<100; ++i)
                //  { 
                //      liczby.Add(rnd.Next(i, i+100));
                //  }

                // Tworzymy zapytania do listy
                var q1 = liczby.Select(n => n).Where(n => n > 10).OrderByDescending(a => a).ToList();
                var q2 = (from n in liczby
                          where n > 10
                          orderby n descending
                          select n).ToList();
                // Sprawdzamy co zwróciły nam zapytania

                foreach (var item in q1)
                { Console.Write(item + " "); }
                foreach (var item in q2)
                { Console.Write(item + " "); }

                Console.ReadKey();
            }
        }
    }


