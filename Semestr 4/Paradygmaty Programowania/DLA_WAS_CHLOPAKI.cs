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
                return LastName + " " + FirstName + " " + Age + "\n";
            }
        }
        static void Main(string[] args)
        {
            List<Person> Ludzie = new List<Person>();
            Person osoba1 = new Person("Michal", "Wisniewski", 30);
            Person osoba2 = new Person("Radek", "Gorzelski", 25);
            Person osoba3 = new Person("Adam", "Wkladaj", 19);
            Person osoba4 = new Person("Mlody", "Maniek", 17);
            Person osoba5 = new Person("Janek", "Adamowski", 14);
            Ludzie.Add(osoba1);
            Ludzie.Add(osoba2);
            Ludzie.Add(osoba3);
            Ludzie.Add(osoba4);
            Ludzie.Add(osoba5);

            var alfabetycznie = 
                Ludzie.OrderBy(Person => Person.LastName).ToList();
            foreach (var osoba in alfabetycznie)
            { Console.Write(osoba.ToString() );  }
            Console.ReadKey();
        }
    }
}
