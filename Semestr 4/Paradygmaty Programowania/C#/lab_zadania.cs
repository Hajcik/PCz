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
        {   // Zadanie 1 - Fibonacci
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
            Console.ReadKey();
        }
    }
}
