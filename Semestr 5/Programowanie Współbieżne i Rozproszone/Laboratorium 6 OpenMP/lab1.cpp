#include<iostream>
#include<omp.h>
#include<string>
using namespace std;

int main()
{

/*
Zad1. Napisać program z wykorzystaniem standardu OpenMP,
którego zadaniem będzie wypisaniena standardowe wyjście informacji
o numerze danego wątku oraz liczbie wszystkich uruchomionych
wątków (funkcje omp_get_thread_num oraz omp_get_num_threads).
*/

/*
cout<<"Zadanie 1: \n\n";
  #pragma omp parallel
    {
      int threadID = omp_get_thread_num();
      int totalThreads = omp_get_num_threads();
      string output = "Watek " + to_string(threadID) + " z " + to_string(totalThreads);
      cout << output << "\n";
    }
*/

cout<<"Zadanie 2: \n\n";
  #pragma omp parallel
    {
      
    }


  return 0;
}
