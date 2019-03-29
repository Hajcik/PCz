using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApp1
{
    class Program
    {
        unsafe static void Main(string[] args)
        {
            int* ip;
            // Deklaracja zmiennej calkowitej
            int number = 20;
            // Przypisanie do wskaźnika adresu pamięci zmiennej
            // Wyrazenie &nazwa_zmiennej zwraca nam adres pamieci tej zmiennej
            ip = &number;
            Console.WriteLine( "Wartosc liczby: {0}", number );
            Console.WriteLine( "Adres w pamieci: {0}", (int)ip);
            Console.WriteLine( "\nWartosc liczby: {0}", ip->ToString());

            int[] tablica = { 100, 200, 300 }; // Deklaracja tablicy
            fixed (int* pointer = tablica) // ustalamy wskaźnik naszej tablicy

                // Adres tablicy przechowujemy we wskazniku
                for(int i =0; i<3; i++)
                {
                    Console.WriteLine("Adres tablicy: [{0}] = {1}", i, (int)(pointer + i));
                    Console.WriteLine("Wartosc tablicy: [{0}] = {1}", i, *(pointer + i));
                    Console.WriteLine("Wartosc tablicy: [{0}] = {0}", (pointer + 1)->ToString());
                    Console.WriteLine();
                }

            byte[] b = new byte[8];
            unsafe
            {
                // Uzyskanie adresu tablicy - tablica to obiekt zarzadzany, aby jej adres
                // sie nie zmienil w czasie odwolac przez wskaznik uzywamy bloku fixed
                fixed(byte* p = b)
                {
                    // Rzutowanie adresu liczby typu byte na adres typu int
                    int* i = (int*)p;
                    // Tym sposobem zmieniam 4 kolejne elementy tablicy byte elementy (0-3)
                    *i = 1857;
                    // A tu zmieniam kolejne 4 elementy tablicy (4-7)
                    *(i + 1) = 5678;
                    // Rzutuje adres do int na adres do long, dzieki temu wyswietlam cala tablice
                    // jako liczbe typu long
                    Console.WriteLine(*(long*)i);
                    Console.WriteLine();
                }
            }
            // Zadanie 1
            long[] array = new long[25];
            array[0] = array[1] = 1;

            fixed(long* pointer = array)
            {
                Console.WriteLine("{0}: {1}", 0, *pointer);
                Console.WriteLine("{0}: {1}", 1, *(pointer + 1));

                for(long i = 2; i < 25; i++)
                {
                    *(pointer + i) = *(pointer + i - 1) + *(pointer + i - 2);
                    Console.WriteLine("{0}: {1}", i + 1, *(pointer + i));
                }
            }
            Console.WriteLine();

            // Zadanie 2
            long[,] macierz_A = new long[25, 25];
            long[,] macierz_B = new long[25, 25];
            
            fixed(long* wskaznik_macierz_A = macierz_A)
            { 
                fixed(long* wskaznik_macierz_B = macierz_B)
                {
                    for(int i = 0; i < 25; i++)
                    {
                        for(int j = 0; j < 25; j++)
                        {
                            *(wskaznik_macierz_A + i + (j * 25)) = j;
                            *(wskaznik_macierz_B + i + (j * 25)) = i;
                        }
                    }
                    for(int i = 0; i < 25; i++)
                    {
                        for(int j = 0; j < 25; j++)
                        {
                            Console.WriteLine(*(wskaznik_macierz_A + i + (j * 25)) + *(wskaznik_macierz_B + i + (j * 25)) + " ");
                        }
                        Console.WriteLine();
                    }
                }
            }

            Console.ReadKey();
        }
    }
}
