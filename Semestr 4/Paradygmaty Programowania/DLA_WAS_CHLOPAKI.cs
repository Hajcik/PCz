using System;
using System.Linq;
using System.Xml.Linq;
using System.Collections.Generic;
namespace ConsoleApp27
{
    class Program
    {
        public class Person
        {
        //   List<Person> Ludzie = new List<Person>();
            public string FirstName { get; private set; }
            public string LastName { get; private set; }
            public int Age { get; private set; }
            public Person(string sFirstName, string sLastName, int nAge)
            {
                FirstName = sFirstName;
                LastName = sLastName;
                Age = nAge;
            }
            public override string ToString()
            {
                return LastName + " " + FirstName + " " + Age;
            }
        }
        static void Main(string[] args)
        {
            List<Person> Ludzie = new List<Person>();
            Person osoba1 = new Person("Michal", "Wisniewski", 30);
            Person osoba2 = new Person("Mariusz", "Gorzelski", 25);
            Person osoba3 = new Person("Adam", "Wkladaj", 19);
            Person osoba4 = new Person("Mlody", "Maniek", 17);
            Person osoba5 = new Person("Janek", "Adamowski", 14);
            Person osoba6 = new Person("Dawido", "Kmako", 13);
            Person osoba7 = new Person("Janek", "Zawadzki", 93);
            Person osoba8 = new Person("Bambuko", "Afryko", 2);
            Person osoba9 = new Person("Mariusz", "Maloletni", 10);
            Person osoba10 = new Person("Mariusz", "Wieloletni", 45);
            Ludzie.Add(osoba1);
            Ludzie.Add(osoba2);
            Ludzie.Add(osoba3);
            Ludzie.Add(osoba4);
            Ludzie.Add(osoba5);
            Ludzie.Add(osoba6);
            Ludzie.Add(osoba7);
            Ludzie.Add(osoba8);
            Ludzie.Add(osoba9);
            Ludzie.Add(osoba10);
            // podpunkt A
            var alfabetycznie = 
                Ludzie.OrderBy(Person => Person.LastName).ToList();
            foreach (var osoba in alfabetycznie)
            { Console.WriteLine(osoba.ToString() );  }
            Console.WriteLine();
            // podpunkt B
         
            var test =
                (from n in Ludzie
                 where n.Age > 18
                 where n.FirstName == "Mariusz"
                 select n).ToList();
            foreach(var osoba in test)
            { Console.WriteLine(osoba.ToString() ); }

            Console.ReadKey();


        }
    }
}
