/*
Kompilacja: mpic++ -o lab1 lab1.cpp
Uruchomienie: mpirun -np 4 ./lab1
Napisać program z wykorzystaniem biblioteki MPI, który będzie realizował komunikację między
4 procesami z wykorzystaniem funkcji MPI_Send i funkcji MPI_Recv.
Procesy, w kolejności od procesu 0 do procesu 3, mają przekazywać wiadomość msg zwiększając
jej wartość o swój rank:
proces 0: wysyła msg=0 do procesu 1;
proces 1: odbiera msg;
 zwiększa wartość: msg = msg + rank;
 wysyła msg do procesu 2;
proces 2: odbiera msg;
 zwiększa wartość msg = msg + rank;
 wysyła msg do procesu 3;
proces 3: odbiera msg;
 zwiększa wartość msg = msg + rank;
 wyświetla rank i wartość msg;
Po uruchomieniu (mpirun -np 4 ./lab1) , program powinien wypisać na ekranie:
rank:3 msg:6

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
