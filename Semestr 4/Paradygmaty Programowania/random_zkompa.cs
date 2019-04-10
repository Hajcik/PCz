//Mikołajczak Kacper 128112
using System;

namespace kolokwium
{
    class FiguraGeometryczna
    {
        protected string _nazwa = "";

        public FiguraGeometryczna()
        {
            _nazwa = "";
        }

        public FiguraGeometryczna(string nazwa)
        {
            _nazwa = nazwa;
        }

        virtual public double WyznaczObwod()
        {
            return 0.0;
        }
    }

    class Kwadrat : FiguraGeometryczna
    {
        private double _dlugoscBoku =  0;
        private Wierzcholek wierzcholek1 = null;
        private Wierzcholek wierzcholek2 = null;
        private Wierzcholek wierzcholek3 = null;
        private Wierzcholek wierzcholek4 = null;


        public Kwadrat() : base("Kwadrat")
        {
            _dlugoscBoku = 0;
            wierzcholek1 = null;
            wierzcholek2 = null;
            wierzcholek3 = null;
            wierzcholek4 = null;

        }

        public Kwadrat(double dlugoscBoku, double xPierwszegoWierzcholka, double yPierwszegoWierzcholka)
            :base("Kwadrat")
        {
            _dlugoscBoku = dlugoscBoku;
            wierzcholek1 = new Wierzcholek(xPierwszegoWierzcholka, yPierwszegoWierzcholka);
            wierzcholek2 = new Wierzcholek(xPierwszegoWierzcholka + dlugoscBoku, yPierwszegoWierzcholka);
            wierzcholek3 = new Wierzcholek(xPierwszegoWierzcholka + dlugoscBoku, yPierwszegoWierzcholka + dlugoscBoku);
            wierzcholek4 = new Wierzcholek(xPierwszegoWierzcholka, yPierwszegoWierzcholka + dlugoscBoku);
        }

        public override double WyznaczObwod()
        {
            return _dlugoscBoku * 4.0;
        }
    }

    class Wierzcholek
    {
        private double _x = 0;
        private double _y = 0;

        public Wierzcholek()
        {
            _x = 0;
            _y = 0;
        }
        public Wierzcholek(double x, double y)
        {
            _x = x;
            _y = y;
        }

        public double X { get => _x; set => _x = value; }
        public double Y { get => _y; set => _y = value; }
    }
    class Program
    {
        static void Main(string[] args)
        {
            FiguraGeometryczna z = new Kwadrat(2, 0, 0);
            Kwadrat x = new Kwadrat(3, 0, 0);
            FiguraGeometryczna c = new FiguraGeometryczna("Test");
            Console.WriteLine(z.WyznaczObwod());
            Console.WriteLine(x.WyznaczObwod());
            Console.WriteLine(c.WyznaczObwod());
        }
    }
}
