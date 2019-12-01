/*
Kompilacja: mpic++ -o lab1 lab1.cpp
Uruchomienie: mpirun -np 4 ./lab1

Napisać program z wykorzystaniem biblioteki MPI, który pozwoli na uruchomienie równolegle np
procesów. Każdy proces powinien wyświetli bieżący numer procesu, liczbę wszystkich procesów
oraz podstawowe informacje o komputerze.

*/

#include<mpi.h>
#include<iostream>
using namespace std;

int main()
{
	int rank; // ID procesu
	int size; // Liczba uruchomionych procesow
	int len;
	char name[MPI_MAX_PROCESSOR_NAME];	
		
	MPI_Init(NULL, NULL);
	
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Get_processor_name(name, &len);
//	cout<<"HELLO WORLD, RANK: "<<rank<<" SIZE: "<<size<<endl;
	cout<<"HELLO WORLD, RANK: "<<rank<<" SIZE: "<<size
		<<" PROCESSOR NAME: "<<name<<endl;
	
	int temp = 0;
	
	
	//Funkcja cin jest dostepna tylko dla ranku o id=0
	if(rank == 0)
	{
		// cin >> temp
		temp = 10;
	}
	else
	{
		temp=11;
	}
	cout<<"Rank: "<< rank <<"Temp: "<<temp<<endl;
	
	int MPI_Finalize();
	
	
	return 0;
}
