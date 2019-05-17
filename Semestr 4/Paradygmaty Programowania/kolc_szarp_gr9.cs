using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Kolokwium_gr9
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        //Zadanie 1:
        unsafe private void Zadanie1_Click(object sender, EventArgs e)
        {
            int[,] matrix1 = new int[5, 5];
            int[,] matrix2 = new int[5, 5];
            int[,] result = new int[5, 5];
            for (int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                {
                    //Przykladowe dane:
                    matrix1[i, j] = i + j;
                    matrix2[i, j] = 2 * i + 3 + j;

                }
            }
            string res1 = "";
            //Dodawanie:
            fixed (int * ptr1 = matrix1)
                fixed(int * ptr2 = matrix2)
                fixed(int * res = result)
            {
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        *(res + 5 * i + j) = *(ptr1 + 5 * i + j) + *(ptr2 + 5 * i + j);
                        res1 += "[" + *(res + 5 * i + j) + "]";
                    }
                    res1 += "\n";
                }
            }
            wynik1.Text = res1;
            string res2 = "";
            //Mnozenie:
            fixed (int* ptr1 = matrix1)
            fixed (int* ptr2 = matrix2)
            fixed (int* res = result)
            {
                for (int i = 0; i < 5; i++)
                {
                    for (int j = 0; j < 5; j++)
                    {
                        *(res + 5 * i + j) = *(ptr1 + 5 * i + j) * *(ptr2 + 5 * i + j);
                        res2 += "[" + *(res + 5 * i + j) + "]";
                    }
                    res2 += "\n";
                }
            }
            wynik2.Text = res2;
        }
        //Zadanie 2
        private Bitmap obrazek = new Bitmap(@"..\..\..\obrazek.jpg");
        private void button1_Click(object sender, EventArgs e)
        {
            pictureBox1.Image = obrazek;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Bitmap odwrotny = new Bitmap(obrazek);
            for(int i = 0; i < obrazek.Width; i++)
            {
                for(int j = 0; j < obrazek.Height; j++)
                {
                    Color pix = obrazek.GetPixel(i, j);
                    int r = 255 - pix.R;
                    int g = 255 - pix.G;
                    int b = 255 - pix.B;
                    odwrotny.SetPixel(i, j, Color.FromArgb(pix.A, r, g, b));
                }
            }
            pictureBox1.Image = odwrotny;
        }
        //Zadanie 3
        private string Polacz<T>(T a, T b)
        {
            return a.ToString() + b.ToString();
        }
        private void Zamien<T>(ref T a, ref T b)
        {
            T tmp = a;
            a = b;
            b = tmp;
        }
        private void button3_Click(object sender, EventArgs e)
        {
            zad3.Text = Polacz<int>(3, 4);
            zad3.Text += "\n";
            zad3.Text += Polacz<string>("test", "Test");
            int a = new int();
            a = 3;
            int b = new int();
            b = 4;
            zad3_2.Text = "Przed zamiana:" + a + " " + b + "\n";
            Zamien<int>(ref a, ref b);
            zad3_2.Text += "Po zamianie:" + a + " " + b + "\n";
        }
        //Zadanie 4
        public class Produkt
        {
            public string nazwa { get; private set; }
            public double cena { get; private set; }
            public DateTime dataWaznosci { get; private set; }

            public Produkt()
            {

            }
            public Produkt(string nazwa, double cena, DateTime dataWaznosci)
            {
                this.nazwa = nazwa;
                this.cena = cena;
                this.dataWaznosci = dataWaznosci;
            }
            public override string ToString()
            {
                return nazwa + " " + cena + " " + dataWaznosci;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            List<Produkt> produkty = new List<Produkt>();
            produkty.Add(new Produkt("kokakola", 5.99, new DateTime(2020, 3, 4, 7, 0, 0)));
            produkty.Add(new Produkt("hawajska", 16.99, new DateTime(2019, 7, 1, 3, 0, 0)));
            produkty.Add(new Produkt("paluszki", 5.99, new DateTime(2030, 3, 3, 7, 0, 0)));

            produkty.Add(new Produkt("mieso", 3.00, new DateTime(2021, 6, 7, 7, 0, 0)));
            produkty.Add(new Produkt("ser", 7.39, new DateTime(2030, 3, 3, 9, 0, 0)));
            produkty.Add(new Produkt("czekolada", 4.22, new DateTime(2020, 3, 4, 7, 0, 0)));
            produkty.Add(new Produkt("mleko", 1.20, new DateTime(2030, 2, 2, 9, 0, 0)));
            produkty.Add(new Produkt("woda", 5.00, new DateTime(2031, 6, 3, 7, 0, 0)));
            produkty.Add(new Produkt("maslo", 2.99, new DateTime(2032, 3, 3, 3, 0, 0)));
            //wg ceny
            var q1 = produkty.Select(n => n).OrderBy(n => n.cena).ToList();
            string wynik = "";
            foreach (var item in q1) wynik += item.ToString() + "\n";
            zad4.Text = wynik;
            //tansze od 15 zaczynajace sie na s
            var q2 = produkty.Select(n => n).Where(n => (n.cena < 15.00) && (n.nazwa[0] == 's')).OrderBy(n => n.cena).ToList();
            string wynik2 = "";
            foreach (var item in q2) wynik2 += item.ToString() + "\n";
            zad4_2.Text = wynik2;
        }
    }
}
